out_file: main.c
	gcc main.c `pkg-config --cflags --libs gsl` -lgslcblas -lgsl -lm -o out_file

run: out_file
	./out_file

clean: out_file
	rm -f out_file
	rm -f *.csv