#include "trapezoidal_integrator.h"

float trapezoidal_integrate(float x, float xdot, float xdot_z, float dt) {
    return x+dt*(xdot+xdot_z)/2;
}
