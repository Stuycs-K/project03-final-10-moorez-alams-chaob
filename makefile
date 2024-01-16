default: compile
compile: client.o poker.o server.o
	@gcc -o client client.o poker.o
	@gcc -o server server.o
server.o: server.c
	@gcc -c server.c
poker.o: poker.c poker.h
	@gcc -c poker.c
client.o: client.c poker.h
	@gcc -c client.c
clean:
	rm server
	rm client
	rm *.o