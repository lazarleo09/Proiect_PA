CC=gcc
CFLAGS=-c -Wall

all: app

app: main.o message.o generators.o
	$(CC) main.o message.o generators.o -o app

main.o: main.c
	$(CC) $(CFLAGS) main.c

message.o: message.c
	$(CC) $(CFLAGS) message.c

generators.o: generators.c
	$(CC) $(CFLAGS) generators.c

clean:
	rm -f *.o