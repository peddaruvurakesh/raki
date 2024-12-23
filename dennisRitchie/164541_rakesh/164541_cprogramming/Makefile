
CC = gcc
LDFLAGS = -g -lm

chapter = 164541_rakesh_chapter5
program = 164541_rakesh_ex5-7
CFLAGS = $(chapter)/$(program)


all: final
	
final: $(CFLAGS).o 
	$(CC)  $(CFLAGS).o -o all $(LDFLAGS)
	
	

$(CFLAGS).o: $(CFLAGS).c 
	$(CC) -c $(CFLAGS).c  -o $(CFLAGS).o 


clean:
	rm -f $(CFLAGS)*.o


