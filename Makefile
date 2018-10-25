all: main.c
	gcc main.c -o EXEC_GCC Sources/Menu.c Sources/Permutacao.c

clang: main.c
	clang main.c -o EXEC_CLANG Sources/Menu.c Sources/Permutacao.c

run_g:
	./EXEC_GCC

run_c:
	./EXEC_CLANG

rm:
	rm EXEC_*
