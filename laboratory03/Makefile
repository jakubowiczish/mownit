out_optimized: main.c
	gcc main.c `pkg-config --cflags --libs gsl` -lgslcblas -lgsl -lm -o out_optimized -O3

out_normal: main.c
	gcc main.c `pkg-config --cflags --libs gsl` -lgslcblas -lgsl -lm -o out_normal

run_optimized: out_optimized
	./out_optimized resultlab3optimized.csv

run_normal: out_normal
	./out_normal resultlab3.csv

clean:
	rm -f out_normal
	rm -f out_optimized
	rm -f *.csv