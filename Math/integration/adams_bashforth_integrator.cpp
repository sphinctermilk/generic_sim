#include "adams_bashforth_integrator.h"

float adams_bashforth_integrate(float x, float xdot, float xdot_z, float dt) {
    return x+dt*(3*xdot-xdot_z)/2;
}
