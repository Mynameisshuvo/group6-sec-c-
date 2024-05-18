#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double rad_to_deg(double radians) {
    return radians * (180.0 / PI);
}

int main() {
    double lambda;
    int m;
    double a1, a2, a3;

    printf("Enter wavelength (nm): ");
    scanf("%lf", &lambda);

    if (lambda < 380 || lambda > 750) {
        printf("Out of the range, please enter a valid number.\n");
        return 1;
    }

    printf("Enter order (m): ");
    scanf("%d", &m);

    printf("Enter three values for slit width (a) in micrometers: ");
    scanf("%lf %lf %lf", &a1, &a2, &a3);

    double sin_theta1 = (m * lambda * 1e-3) / a1;
    double sin_theta2 = (m * lambda * 1e-3) / a2;
    double sin_theta3 = (m * lambda * 1e-3) / a3;

    if (sin_theta1 > 1 || sin_theta2 > 1 || sin_theta3 > 1) {
        printf("Invalid slit width resulting in sin(theta) out of range.\n");
        return 1;
    }

    double angle1 = rad_to_deg(asin(sin_theta1));
    double angle2 = rad_to_deg(asin(sin_theta2));
    double angle3 = rad_to_deg(asin(sin_theta3));

    double max_angle = angle1;
    int max_index = 1;

    if (angle2 > max_angle) {
        max_angle = angle2;
        max_index = 2;
    }

    if (angle3 > max_angle) {
        max_angle = angle3;
        max_index = 3;
    }

    printf("Slit %d bent the light the most with an angle of %.2f degrees\n", max_index, max_angle);

    return 0;
}
