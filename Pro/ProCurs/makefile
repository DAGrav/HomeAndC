all: prog

prog: main.o
	gcc -o math main.o
main.o:main.c
	gcc -c -o main.o main.c
clean:
	del -rf *.o prog
