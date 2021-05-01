all: hw0301.o hw0301another.c hw0302.o hw0302another.c hw0303.o hw0306.o 
	gcc hw0301another.c hw0301.o -o hw0301
	gcc hw0302another.c hw0302.o -o hw0302
	gcc hw0303.o -o hw0303 -lm
	gcc hw0306.o -o hw0306

hw0301: hw0301.c
	gcc -c hw0301.c -o hw0301.o 
	gcc -shared hw0301.o -o libhw0301.so

hw0302: hw0302.c
	gcc -c hw0302.c -o hw0302.o 
	gcc -shared hw0302.o -o libhw0302.so

hw0303: hw0303.c
	gcc -c hw0303.c -o hw0303.o 
	gcc -shared hw0303.o -o libhw0303.so

hw0306: hw0306.c
	gcc -c hw0306.c -o hw0306.o 
	gcc -shared hw0306.o -o libhw0306.so
