CC = gcc
cflags = -g -O3

all: oucat ouecho ouhead ouseq outail ouwc
clean:
	rm -f *.o

oucat:
	$(CC) oucat.c $(cflags) -o oucat
ouecho:
	$(CC) ouecho.c $(cfags) -o ouecho
ouhead:
	$(CC) ouhead.c $(cflags) -o ouhead
ouseq:
	$(CC) ouseq.c $(cflags) -o ouseq
outail:
	$(CC) outail.c $(cflags) -o outail
ouwc:
	$(CC) ouwc.c $(cflags) -o ouwc
