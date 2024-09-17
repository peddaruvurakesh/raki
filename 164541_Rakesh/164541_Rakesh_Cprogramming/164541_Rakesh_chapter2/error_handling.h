
#include <stdio.h>
#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

// Define error codes
#define ERROR_NONE 0
#define ERROR_INVALID_INPUT 1
#define ERROR_OUT_OF_RANGE 2
#define ERROR_STEP_TOO_LARGE 3
#define ZERO_DEVISION_ERROR 4

// Function definitions
void handle_error(int error_code) {
    switch (error_code) {
        case ERROR_NONE:
            break;  // No error
        case ERROR_INVALID_INPUT:
            printf("Error: Invalid input entered.\n");
            break;
        case ERROR_OUT_OF_RANGE:
            printf("Error: Input out of range.\n");
            break;
        case ERROR_STEP_TOO_LARGE:
            printf("Error: Step size greater than upper bound.\n");
            break;
        case ZERO_DEVISION_ERROR:
            printf("Error %d: Zero devision error\n",ZERO_DEVISION_ERROR);
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}

#endif /* ERROR_HANDLING_H */
