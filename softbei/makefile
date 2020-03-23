signation: main.o signation.o
	gcc main.o signation.o -o signation

main.o: main.c signation.h
	gcc -c main.c

signation.o: signation.c signation.h
	gcc -c signation.c

clean:
	rm main.o signation.o