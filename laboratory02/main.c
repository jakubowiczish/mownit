#include <stdio.h>
#include <gsl/gsl_blas.h>
#include <time.h>
#include <string.h>

const int SIZE_OF_MATRIX = 5000;
const int SIZE_OF_VECTOR = 25000000;

static struct timespec timespec_start, timespec_stop;

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

double *get_generated_vector(int size_of_vector) {
    srand((unsigned) time(NULL));
    double *vector = malloc(size_of_vector * sizeof(double));
    for (int i = 0; i < size_of_vector; ++i) {
        vector[i] = rand() % 50 + 1;
    }
    return vector;
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

long get_vectors_multiplication_time(double *vector_1_double, double *vector_2_double, int size) {
    gsl_vector_view vector1 = gsl_vector_view_array(vector_1_double, (size_t) size);
    gsl_vector_view vector2 = gsl_vector_view_array(vector_2_double, (size_t) size);

    double result;

    start_timer();
    gsl_blas_ddot(&vector1.vector, &vector2.vector, &result);
//    printf("%lf\n", result);
    return stop_timer();
}

long get_matrix_and_vector_multiplication_time(double *matrix_double, double *vector_double, int size, double *result) {
    gsl_matrix_view matrix = gsl_matrix_view_array(matrix_double, size, size);
    gsl_vector_view vector = gsl_vector_view_array(vector_double, size);

    gsl_vector_view vector_result = gsl_vector_view_array(result, size);

//    y := alpha*A*x + beta*y,   or   y := alpha*A**T*x + beta*y,

    start_timer();
    gsl_blas_dgemv(CblasNoTrans, 1.0, &matrix.matrix, &vector.vector, 1.0, &vector_result.vector);
    return stop_timer();
}


void fill_csv() {
    double *vector = get_generated_vector(SIZE_OF_VECTOR);
    double *matrix = get_gsl_generated_matrix(SIZE_OF_MATRIX);

    char *csv_file_name = "result.csv";
    unsigned int buffer_size = 512;

    FILE *csv_file = fopen(csv_file_name, "w");

    if (csv_file == NULL) {
        printf("FILE IS NULL");
        return;
    }

    char *buffer = malloc(buffer_size * sizeof(char));
    snprintf(buffer, buffer_size,
             "SIZE_OF_VECTOR,ITERATION,VECTOR_TIME,MATRIX_TIME\n");
    fwrite(buffer, sizeof(char), strlen(buffer), csv_file);

    double *result_array = calloc(SIZE_OF_MATRIX, sizeof(double));

    int size = 1;
    while (size < 25) {
        for (int i = 0; i < 10; ++i) {
            long vector_multiplication_time = get_vectors_multiplication_time(vector, vector, size);
            long matrix_and_vector_multiplication_time = get_matrix_and_vector_multiplication_time(matrix, vector,
                                                                                                     size,
                                                                                                     result_array);

            snprintf(buffer, buffer_size, "%d,%d,%ld,%ld\n", size, i, vector_multiplication_time,
                     matrix_and_vector_multiplication_time);

            fwrite(buffer, sizeof(char), strlen(buffer), csv_file);
        }
        size += 1;
    }

    fclose(csv_file);
    free(vector);
    free(matrix);
}


int main() {
    fill_csv();
    return 0;
}