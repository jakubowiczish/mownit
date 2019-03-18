all:
	gcc main.c `pkg-config --cflags --libs gsl` -lgslcblas -lgsl -lm -o out_main

run:
	make all
	./out_main

clean:
	rm -f out_main
	rm -f *.csv