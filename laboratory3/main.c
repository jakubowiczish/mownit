#include <stdlib.h>
#include <time.h>

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

double *get_generated_matrix(int size_of_matrix) {
    srand((unsigned) time(NULL));
    double *matrix = malloc(size_of_matrix * size_of_matrix * sizeof(double));
    for (int i = 0; i < size_of_matrix; ++i) {
        for (int j = 0; j < size_of_matrix; ++j) {
            matrix[i * size_of_matrix + j] = rand() % 50 + 1;
        }
    }
    return matrix;
}

