trab2_alg: main.o lista_dim.o lista_dim.h bubble_sort.o bubble.h merg_sort.o merge.h insertio_sort.o insertion.h 
	gcc main.o lista_dim.o lista_dim.h bubble_sort.o bubble.h merg_sort.o merge.h insertio_sort.o insertion.h -o trab2_alg
main.o: main.c
	gcc -c main.c
lista.o: lista_dim.c
	gcc -c lista_dim.c
bubble_sort.o: bubble_sort.c
	gcc -c bubble_sort.c
merg_sort.o: merg_sort.c
	gcc -c merg_sort.c
insertio_sort.o: insertio_sort.c
	gcc -c insertio_sort.c
