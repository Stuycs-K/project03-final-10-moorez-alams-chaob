compile: poker.o
	@gcc -o runme poker.o
poker.o: poker.c poker.h
	@gcc -c poker.c
run: runme
	@./runme
clean:
	rm *.o
	rm runme