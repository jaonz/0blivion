c_flags=-I/usr/include/allegro5
lib_flags=-L/usr/lib -lallegro

main: mapa.o main.o settings.h
	gcc -o bomber main.o mapa.o ${lib_flags}

main.o: main.c
	gcc -o main.o -c main.c ${c_flags}

mapa.o: mapa.c mapa.h
	gcc -o mapa.o -c mapa.c

clear:
	rm -r *.o
