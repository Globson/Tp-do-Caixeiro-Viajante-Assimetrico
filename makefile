all: main.c
	gcc main.c -o EXEC_GCC

clang: main.c
	clang main.c -o EXEC_CLANG

run_g:
	./EXEC_GCC

run_c:
	./EXEC_CLANG

rm:
	rm EXEC_GCC && rm EXEC_CLANG
