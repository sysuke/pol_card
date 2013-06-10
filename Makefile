# Makefile 1 (「#」は行末までのコメント)

a32.out: main.o pol_init.o
		gcc $$(pkg-config --cflags --libs gtk+-2.0) -o a32.out pol_init.o main.o -m32

pol_init.o: pol_init.c
		gcc $$(pkg-config --cflags --libs gtk+-2.0) pol_init.c -c -m32

main.o: main.c
		gcc $$(pkg-config --cflags --libs gtk+-2.0) main.c -c -m32

