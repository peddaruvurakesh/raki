#include "simplefs-ops.h"
extern struct filehandle_t file_handle_array[MAX_OPEN_FILES]; // Array for storing opened files
 
int simplefs_create(char *filename){
    /*
        Create file with name `filename` on disk
    */
    // Check if the file already exists (i.e., check if inode is already in use)
    for (int i = 0; i < NUM_INODES; i++) {
        struct inode_t inode;
        simplefs_readInode(i, &inode);
        if (inode.status == INODE_IN_USE && strcmp(inode.name, filename) == 0) {
            // File already exists
            return -1;
        }
    }
 
    // Allocate a new inode
    int inode_index = simplefs_allocInode();
    if (inode_index == -1) {
        // No available inodes
        return -1;
    }
 
    // Initialize the inode
    struct inode_t inode;
    inode.status = INODE_IN_USE;
    strncpy(inode.name, filename, MAX_NAME_STRLEN);
    inode.file_size = 0;
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        inode.direct_blocks[i] = -1;
    }
 
    // Write the inode to disk
    simplefs_writeInode(inode_index, &inode);
 
    return inode_index; // Return the inode index as file handle
}
 
 
void simplefs_delete(char *filename){
    /*
        Delete file with name `filename` from disk
    */
    // Find the inode for the given filename
    int inode_index = -1;
    for (int i = 0; i < NUM_INODES; i++) {
        struct inode_t inode;
        simplefs_readInode(i, &inode);
        if (inode.status == INODE_IN_USE && strcmp(inode.name, filename) == 0) {
            inode_index = i;
            break;
        }
    }
 
    if (inode_index == -1) {
        // File not found
        return;
    }
 
    // Free the associated data blocks
    struct inode_t inode;
    simplefs_readInode(inode_index, &inode);
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        if (inode.direct_blocks[i] != -1) {
            simplefs_freeDataBlock(inode.direct_blocks[i]);
        }
    }
 
    // Free the inode
    simplefs_freeInode(inode_index);
}
 
 
int simplefs_open(char *filename){
    /*
        Open file with name `filename`
    */
    // Check if the file already exists and find the inode
    int inode_index = -1;
    for (int i = 0; i < NUM_INODES; i++) {
        struct inode_t inode;
        simplefs_readInode(i, &inode);
        if (inode.status == INODE_IN_USE && strcmp(inode.name, filename) == 0) {
            inode_index = i;
            break;
        }
    }
 
    if (inode_index == -1) {
        // File not found
        return -1;
    }
 
    // Find an available file handle
    for (int i = 0; i < MAX_OPEN_FILES; i++) {
        if (file_handle_array[i].inode_number == -1) {
            // Found available file handle
            file_handle_array[i].inode_number = inode_index;
            file_handle_array[i].offset = 0;
            return i; // Return file handle
        }
    }
 
    // No available file handle
    return -1;
}
 
void simplefs_close(int file_handle){
    /*
        Close file pointed by `file_handle`
    */
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        return; // Invalid file handle
    }
 
    // Free the file handle
    file_handle_array[file_handle].inode_number = -1;
    file_handle_array[file_handle].offset = 0;
}
 
int simplefs_read(int file_handle, char *buf, int nbytes){
    //
     //   Read `nbytes` of data into `buf` from file pointed by `file_handle` starting at current offset
    //
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        return -1; // Invalid file handle
    }
 
    struct filehandle_t *file_handle_entry = &file_handle_array[file_handle];
    int inode_index = file_handle_entry->inode_number;
 
    if (inode_index == -1) {
        return -1; // No file associated with this handle
    }
 
    struct inode_t inode;
    simplefs_readInode(inode_index, &inode);
 
    int buf_offset = 0;
    int block_index = file_handle_entry->offset / BLOCKSIZE;
    int block_offset_in_file = file_handle_entry->offset % BLOCKSIZE;
 
    while (nbytes > 0 && block_index < MAX_FILE_SIZE) {
        if (inode.direct_blocks[block_index] == -1) {
            break; // No more data blocks
        }
 
        char databuf[BLOCKSIZE];
        simplefs_readDataBlock(inode.direct_blocks[block_index], databuf);
 
        int bytes_to_read = (nbytes < BLOCKSIZE - block_offset_in_file) ? nbytes : (BLOCKSIZE - block_offset_in_file);
        memcpy(buf + buf_offset, databuf + block_offset_in_file, bytes_to_read);
 
        buf_offset += bytes_to_read;
        nbytes -= bytes_to_read;
 
        block_index++;
        block_offset_in_file = 0;
    }
 
    return 0;
}
 
int simplefs_write(int file_handle, char *buf, int nbytes){
 
       // Write `nbytes` of data from `buf` to file pointed by `file_handle` starting at current offset
 
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        return -1; // Invalid file handle
    }
 
    struct filehandle_t *file_handle_entry = &file_handle_array[file_handle];
    int inode_index = file_handle_entry->inode_number;
 
    if (inode_index == -1) {
        return -1; // No file associated with this handle
    }
 
    struct inode_t inode;
    simplefs_readInode(inode_index, &inode);
 
    int buf_offset = 0;
    int block_index = file_handle_entry->offset / BLOCKSIZE;
    int block_offset_in_file = file_handle_entry->offset % BLOCKSIZE;
 
    int iNew = 0;
    while (nbytes > 0 && block_index < MAX_FILE_SIZE) {
        if (inode.direct_blocks[block_index] == -1) {
            int new_block = simplefs_allocDataBlock();
            if (new_block == -1) {
                return -1; // No free data block
            }
            inode.direct_blocks[block_index] = new_block;
            iNew = 1;
        }
 
        char data[BLOCKSIZE];
 
 
        if(iNew == 0)
        {
                simplefs_readDataBlock(inode.direct_blocks[block_index], data);
        }
 
        int bytes_to_write = (nbytes < BLOCKSIZE - block_offset_in_file) ? nbytes : (BLOCKSIZE - block_offset_in_file);
        memcpy(data + block_offset_in_file, buf + buf_offset, bytes_to_write);
        simplefs_writeDataBlock(inode.direct_blocks[block_index], data);
 
 
        inode.file_size += bytes_to_write;
        buf_offset += bytes_to_write;
        nbytes -= bytes_to_write;
 
        block_index++;
        block_offset_in_file = 0;
    }
 
    simplefs_writeInode(inode_index, &inode);
 
    return 0;
}
 
int simplefs_seek(int file_handle, int nseek){
 
    //   Increase `file_handle` offset by `nseek`
 
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        return -1; // Invalid file handle
       }    
    struct filehandle_t *file_handle_entry = &file_handle_array[file_handle];
    file_handle_entry->offset += nseek;

    return 0;
}
