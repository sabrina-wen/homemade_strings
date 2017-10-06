all: homemade_strings.o
	gcc homemade_strings.o -o o_strings
homemade_strings.o: homemade_strings.c
	gcc -c homemade_strings.c
run: all
	./o_strings
clean:
	rm -f *.o
	rm -f *~
