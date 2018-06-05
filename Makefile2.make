all: app 

app: main.o message.o generators.o
	gcc main.o message.o generators.o -o app

main.o: main.c
	gcc -c main.c

message.o: message.c
	gcc -c message.c

generators.o: generators.c
	gcc -c generators.c
	
clean:
	rm *o app