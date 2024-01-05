compile:
	@gcc -c playerData.c
	@gcc -c main.c
	@gcc -o a.out playerData.o main.o
run:
	@./a.out