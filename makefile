default: compile
compile: poker.o
  @gcc client.c -o client
  @gcc server.c -o server
  @gcc poker.o -o runme
poker.o: poker.c poker.h
  @gcc -c poker.c
clean:
  rm client
  rm server
  rm runme