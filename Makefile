OBJS	= main.o mycp.o
SOURCE	= erg2/main.c erg2/mycp.c
HEADER	= erg2/mycp.h
OUT	= mycp
CC	= gcc
FLAGS	= -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: erg2/main.c
	$(CC) $(FLAGS) erg2/main.c 

mycp.o: erg2/mycp.c
	$(CC) $(FLAGS) erg2/mycp.c 


clean:
	rm -f $(OBJS) $(OUT)
