#include <stdio.h>
#include <math.h>
void master(int a, int b, double exponent)
{
    double n_log_b_a = log(a) / log(b);
    if (exponent < n_log_b_a)
    {
        printf("Tn=theta(n^%.2f)\n", n_log_b_a);
    }
    else if (exponent == n_log_b_a)
    {
        printf("T(n) = Θ(n^%.2f * log(n))\n", exponent);
    }
    else
    {
        printf("T(n) = Θ(n^%.2f)\n", exponent);
    }
}
int main()
{
    int a, b;
    double exponent;
    scanf("%d %d", &a, &b);
    master(a, b, exponent);
}