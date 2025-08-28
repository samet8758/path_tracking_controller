//
// Created by Samet Uslu on 28.08.2025.
//
#include <math.h>
#include <stdio.h>
#include "kinematicModel.h"
#include <stdlib.h>
#include <string.h>

void integrate(double *p_int, double *p_der, double timestamp) ;


int main(void) {
    double r1Dot, gammaDot, psi1Dot, psi2Dot, x1Dot, y1Dot, x2Dot, y2Dot;
    double r1 = 0, r2 = 0, gamma = 0, psi1 = 0, psi2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, x_a1 = 0, y_a1 = 0 ,x_b1= 0, y_b1 = 0, x_a2 =0, y_a2 = 0, x_b2 = 0, y_b2 = 0;
    double time = 0;
    double vx = 5;
    double steer = 0;
    FILE *fp = fopen("trajectory.csv", "w");
    fprintf(fp, "time,x_a1,y_a1,x_b1, y_b1, x_a2, y_a2, x_b2, y_b2\n");

    while (time <= 40) {
        r1Dot = (-r1 / tau) + (vx * tan(steer) / (tau * l1));
        integrate(&r1, &r1Dot, (double) 1 / 200);

        gammaDot = r1 * (1 - (H * cos(gamma) / l2) - (vx * sin(gamma) / l2));
        integrate(&r1, &r1Dot, (double) 1 / 200);

        r2 = r1 - gammaDot;
        psi1Dot = r1;
        psi2Dot = r2;
        integrate(&psi1, &psi1Dot, (double) 1 / 200);
        integrate(&psi2, &psi2Dot, (double) 1 / 200);

        x1Dot = vx * cos(psi1);
        y1Dot = vx * sin(psi1);

        integrate(&x1, &x1Dot, (double) 1 / 200);
        integrate(&y1, &y1Dot, (double) 1 / 200);


        x2Dot = vx * cos(gamma) * cos(psi2) - r1 * H * sin(gamma) * cos(psi2);
        y2Dot = vx * cos(gamma) * sin(psi2) - r1 * H * sin(gamma) * sin(psi2);

        integrate(&x2, &x2Dot, (double) 1 / 200);
        integrate(&y2, &y2Dot, (double) 1 / 200);

        x_a1 = x1 + a1*cos(psi1) ;
        y_a1 = y1 + a1*sin(psi1) ;

        x_b1 = x1 - b1*cos(psi1) ;
        y_b1 = y1 - b1*sin(psi1) ;

        x_a2 = x1 - c1*cos(psi1) ;
        y_a2 = y1 - c1*sin(psi1) ;

        x_b2 = x2 - b2*cos(psi2) ;
        y_b2 = y2 - b2*sin(psi2) ;
        fprintf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f\n", time, x_a1, y_a1, x_b1, y_b1, x_a2, y_a2, x_b2, y_b2);

        time += (double) 1 / 200;
        printf("Time is : %.2f\n", time);
    }
    fclose(fp);
    return 0;
}
