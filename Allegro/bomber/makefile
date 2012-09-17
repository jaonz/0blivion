c_flags=-I/usr/include/allegro5
lib_flags=-L/usr/lib -lallegro

main: block.o object.o mapa.o main.o settings.h
	gcc -o bomber main.o mapa.o object.o block.o ${lib_flags}

main.o: main.c
	gcc -o main.o -c main.c ${c_flags}

mapa.o: mapa.c mapa.h
	gcc -o mapa.o -c mapa.c

object.o: object.c object.h
	gcc -o object.o -c object.c ${c_flags}
	
block.o: block.c block.h object.o
	gcc -o block.o -c block.c

util.o: util.c util.h
	gcc -o util.o -c util.c

clear:
	rm -r *.o
