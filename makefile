default: run
compile:
	@gcc client.c -o client
	@gcc server.c -o server
	@gcc poker.c -o runme
run: client.o
	@./client.o localhost 3444

