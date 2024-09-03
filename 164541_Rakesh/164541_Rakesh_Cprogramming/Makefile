
CC = gcc
LDFLAGS = -g -lm

chapter = 164541_Rakesh_chapter2
program = 164541_Rakesh_ex2-1
CFLAGS = $(chapter)/$(program)


all: final
	
final: $(CFLAGS).o 
	$(CC)  $(CFLAGS).o -o all $(LDFLAGS)
	./all
	

$(CFLAGS).o: $(CFLAGS).c 
	$(CC) -c $(CFLAGS).c  -o $(CFLAGS).o 


clean:
	rm -f $(CFLAGS)*.o


