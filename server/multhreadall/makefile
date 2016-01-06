

.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=multhread 

all:$(BIN)

multhread: multhread.o myipc_sem.o myipc_shm.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
	

#dm01_pc:dm01_pc.o
#	$(CC) $(CFLAGS) $^ -o $@ -lpthread
#


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)






