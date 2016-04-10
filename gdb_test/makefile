.SUFFIXES:.c .o
CC=gcc #CC是变量，一般变量都是大写的
EXEC=app
SRCS=main1.c 
OBJS=$(SRCS:.c=.o)
FLAGS1=-o
FLAGS2=-c


start1:$(OBJS)
	$(CC) $(OBJS) $(FLAGS1) $(EXEC) 
	@echo "-----ok----"
.c.o:
	$(CC) $(FLAGS1) $@ -g $(FLAGS2) $<
clean:
	rm $(EXEC) $(OBJS)
