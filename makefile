default: run
compile client.o: client.c server.h
	@gcc -c client.c
run: client.o
	@./client.o localhost 0002

