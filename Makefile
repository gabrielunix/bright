src := ./main.c ./bright.c
warns := -Wall -Wextra
cc := gcc
out := bright


build:
	$(cc) $(warns) -o$(out) $(src)
