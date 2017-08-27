foo: eesh.o user_input.o cprt_func.o string_compare.o CloneRunApp.o
	gcc -o foo eesh.o user_input.o cprt_func.o string_compare.o CloneRunApp.o
eesh.o: eesh.c header.h
	gcc -c eesh.c
user_input.o: user_input.c
	gcc -c user_input.c
cprt_func.o: cprt_func.c
	gcc -c cprt_func.c
string_compare.o: string_compare.c
	gcc -c string_compare.c
CloneRunApp.o: CloneRunApp.c
	gcc -c CloneRunApp.c
clean:
	rm -rf *.o
