#include <stdio.h>
#include <math.h>

int main()
{
    double lambda_g = 530;
    double lambda_r = 700;
    int m_g = 3;
    int m_r = 2;
    double theta_g = 65;

    double d = (m_g * lambda_g) / sin(theta_g * M_PI / 180);

    double theta_r = asin((m_r * lambda_r) / d) * 180 / M_PI;

    printf("The angle for the second-order bright spot for red light is %.2f degrees.\n", theta_r);

    return 0;
}
