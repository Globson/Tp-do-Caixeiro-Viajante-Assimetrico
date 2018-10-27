all: Main.c
	gcc Main.c -o EXEC Sources/Menu.c Sources/Permutacao.c Sources/Matricula.c Sources/Matriz.c Sources/Interativo.c

clang: Main.c
	clang Main.c -o EXEC_CLANG Sources/Menu.c Sources/Permutacao.c Sources/Matricula.c Sources/Matriz.c Sources/Interativo.c
run:
	./EXEC*
