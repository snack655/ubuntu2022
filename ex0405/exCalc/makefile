calc : add.o calc.c
	gcc -o calc add.o calc.c
add.o : add.h add.c
	gcc -c add.h add.c

clean:
	rm add.o calc add.h.gch
