ebola: main.o random.o header.h
	gcc main.o random.o -o ebola

main.o: main.c
	gcc -c main.c

random.o: random.o
	gcc -c random.c
