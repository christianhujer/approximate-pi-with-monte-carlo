#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s ROUNDS\n", argv[0]);
        return 1;
    }
    unsigned long total = (unsigned long) atol(argv[1]);
    unsigned long pointsWithinCircle = 0;
    for (unsigned long count = 0; count < total; count++) {
        double x = (double) rand() / (double) RAND_MAX;
        double y = (double) rand() / (double) RAND_MAX;
        double d = sqrt(x*x + y*y);
        pointsWithinCircle += d <= 1.0;
    }
    double approximationOfPi = (double) pointsWithinCircle * 4.0 / (double) total;
    printf("Approximation of PI using Monte Carlo after %lu rounds: %f\n", total, approximationOfPi);
}
