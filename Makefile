# Makefile 1 (「#」は行末までのコメント)

a.out: main.o pol_init.o
		gcc $(pkg-config --cflags --libs gtk+-2.0) -o a.out main.o pol_init.o

main.o: main.c
		gcc $(pkg-config --cflags --libs gtk+-2.0) -c main.c

pol_init.o: pol_init.c
		gcc $(pkg-config --cflags --libs gtk+-2.0) -c pol_init.c

