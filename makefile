CC = gcc
cflags := -g -O3
executables = oucat ouecho ouhead ouseq outail ouwc

all: $(executables)
debug: cflags += -DDEBUG 
debug: all

clean:
	$(RM) $(executables)

oucat:
	$(CC) oucat.c $(cflags) -o oucat
ouecho:
	$(CC) ouecho.c $(cflags) -o ouecho
ouhead:
	$(CC) ouhead.c $(cflags) -o ouhead
ouseq:
	$(CC) ouseq.c $(cflags) -o ouseq
outail:
	$(CC) outail.c $(cflags) -o outail
ouwc:
	$(CC) ouwc.c $(cflags) -o ouwc
