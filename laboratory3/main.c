#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <string.h>

static struct timespec timespec_start, timespec_stop;

int SIZE_OF_MATRIX = 10000;

struct timespec timespec_diff(struct timespec start, struct timespec stop) {
    struct timespec temp;
    if ((stop.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = stop.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + stop.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = stop.tv_sec - start.tv_sec;
        temp.tv_nsec = stop.tv_nsec - start.tv_nsec;
    }
    return temp;
}

void start_timer() {
    clock_gettime(CLOCK_REALTIME, &timespec_start);
}

long stop_timer() {
    clock_gettime(CLOCK_REALTIME, &timespec_stop);
    struct timespec timespec_diff_time = timespec_diff(timespec_start, timespec_stop);
    return timespec_diff_time.tv_nsec;
}

double *get_gsl_generated_matrix(int size_of_matrix) {
    srand((unsigned) time(NULL));
    double *matrix = malloc(size_of_matrix * size_of_matrix * sizeof(double));
    for (int i = 0; i < size_of_matrix; ++i) {
        for (int j = 0; j < size_of_matrix; ++j) {
            matrix[i * size_of_matrix + j] = rand() % 50 + 1;
        }
    }
    return matrix;
}

double **get_regular_generated_matrix(int size_of_matrix) {
    srand((unsigned) time(NULL));
    double **matrix = malloc(size_of_matrix * size_of_matrix * sizeof(double));
    for (int k = 0; k < size_of_matrix; ++k) {
        matrix[k] = malloc(size_of_matrix * sizeof(double));
    }

    for (int i = 0; i < size_of_matrix; ++i) {
        for (int j = 0; j < size_of_matrix; ++j) {
            matrix[i][j] = rand() % 50 + 1;
        }
    }
    return matrix;
}

void print_matrix(double **matrix, int size_of_matrix) {
    for (int i = 0; i < size_of_matrix; ++i) {
        for (int j = 0; j < size_of_matrix; ++j) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double **naive_multiplication(double **A, double **B, int size_of_matrix) {
    double **result = malloc(size_of_matrix * size_of_matrix * sizeof(double));
    for (int k = 0; k < size_of_matrix; ++k) {
        result[k] = malloc(size_of_matrix * sizeof(double));
    }

    for (int i = 0; i < size_of_matrix; ++i) {
        for (int j = 0; j < size_of_matrix; ++j) {
            for (int k = 0; k < size_of_matrix; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

double **better_multiplication(double **A, double **B, int size_of_matrix) {
    double **result = malloc(size_of_matrix * size_of_matrix * sizeof(double));
    for (int k = 0; k < size_of_matrix; ++k) {
        result[k] = malloc(size_of_matrix * sizeof(double));
    }

    for (int j = 0; j < size_of_matrix; ++j) {
        for (int k = 0; k < size_of_matrix; ++k) {
            for (int i = 0; i < size_of_matrix; ++i) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

gsl_matrix gsl_matrix_multiplication(double *A, double *B, const size_t size_of_matrix, double *result) {
    gsl_matrix_view m_A = gsl_matrix_view_array(A, size_of_matrix, size_of_matrix);
    gsl_matrix_view m_B = gsl_matrix_view_array(B, size_of_matrix, size_of_matrix);

    gsl_matrix_view result_matrix = gsl_matrix_view_array(result, size_of_matrix, size_of_matrix);


    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, &m_B.matrix, &m_A.matrix, 0.0, &result_matrix.matrix);
}

long get_naive_multiplication_time(double **A, double **B, int size_of_matrix) {
    start_timer();
    naive_multiplication(A, B, size_of_matrix);
    return stop_timer();
}

long get_better_multiplication_time(double **A, double **B, int size_of_matrix) {
    start_timer();
    better_multiplication(A, B, size_of_matrix);
    return stop_timer();
}

long get_gsl_matrix_multiplication_time(double *A, double *B, const size_t size_of_matrix, double *result) {
    start_timer();
    gsl_matrix_multiplication(A, B, size_of_matrix, result);
    return stop_timer();
}


void fill_csv() {
    double **A = get_regular_generated_matrix(SIZE_OF_MATRIX);
    double **B = get_regular_generated_matrix(SIZE_OF_MATRIX);
    double *A_gsl = get_gsl_generated_matrix(SIZE_OF_MATRIX);
    double *B_gsl = get_gsl_generated_matrix(SIZE_OF_MATRIX);

    char *csv_file_name = "result.csv";
    unsigned int buffer_size = 512;

    FILE *csv_file = fopen(csv_file_name, "w");

    if (csv_file == NULL) {
        printf("FILE IS NULL");
        return;
    }

    char *buffer = malloc(buffer_size * sizeof(char));
    snprintf(buffer, buffer_size, "SIZE,ITERATION,NAIVE,BETTER,GSL\n");
    fwrite(buffer, sizeof(char), strlen(buffer), csv_file);

    double *result_array = calloc((size_t) SIZE_OF_MATRIX, sizeof(double));

    int size = 1;
    while (size < 25) {
        for (int i = 0; i < 10; ++i) {
            long naive_multiplication_time = get_naive_multiplication_time(A, B, size);
            long better_multiplication_time = get_better_multiplication_time(A, B, size);
            long gsl_multiplication_time = get_gsl_matrix_multiplication_time(A_gsl, B_gsl, size, result_array);

            snprintf(
                    buffer, buffer_size, "%d,%d,%ld,%ld,%ld\n", size, i,
                    naive_multiplication_time, better_multiplication_time, gsl_multiplication_time
                    );

            fwrite(buffer, sizeof(char), strlen(buffer), csv_file);
        }
        size += 1;
    }

    fclose(csv_file);
    free(A);
    free(B);
    free(A_gsl);
    free(B_gsl);
}

int main(int argc, char **argv) {
    fill_csv();
    return 0;
}