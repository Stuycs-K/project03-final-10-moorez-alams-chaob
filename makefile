compile: main.o poker.o
	@gcc -o runme poker.o main.o
main.o: main.c poker.h
	@gcc -c main.c
poker.o: poker.c
	@gcc -c poker.c
run: runme
	@./runme
clean:
	rm *.o
	rm runme