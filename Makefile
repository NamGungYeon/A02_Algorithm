#Makefile
all: bubble


bubble: bubble_original.c bubble_enhanced.c bubble_compare.c bubble_compare2.c
	gcc -o bubble_original bubble_original.c
	gcc -o bubble_enhanced bubble_enhanced.c
	gcc -o bubble_compare bubble_compare.c
	gcc -o bubble_compare2 bubble_compare2.c


clean:
	*.o
