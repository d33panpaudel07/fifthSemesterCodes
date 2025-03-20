#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    double lambda = 1.0 / 10.0; // Mean inter arrival rate (customers per minute)
    double mu = 1.0 / 5.0;      // Service rate (customers per minute)
    // Probability that a customer will not have to wait at the counter (P0)
    double rho = lambda / mu;
    double P0 = 1.0 - (lambda / mu);
    // Expected number of customers in the bank (L)
    double L = lambda / (mu - lambda);
    // Average time a customer can expect to spend in the bank (W)
    double W = 1.0 / (mu - lambda);
    printf("Probability that a customer will not have to wait: %lf\n", P0);
    printf("Expected number of customers in the bank: %lf\n", L);
    printf("Average time a customer can expect to spend in the bank: %lf minutes\n", W);
    return 0;
}