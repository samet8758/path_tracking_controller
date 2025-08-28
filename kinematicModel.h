//
// Created by Samet Uslu on 28.08.2025.
//

#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H

#endif //KINEMATICMODEL_H

double l1 = 4.0;
double H = 1.0;
double l2 = 6.0;
double tau = 0.1;
double a1 = 1.0;
double b1 = 3.0;
double a2 = 2.0;
double b2 = 4.0;
double c1 = 3.0 - 1.0;


void integrate(double *p_int, double *p_der, double timestamp) {
    *p_int += *p_der * timestamp;
}