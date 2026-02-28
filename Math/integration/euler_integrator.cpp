#include "euler_integrator.h"

float euler_integrate(float x, float xdot, float dt) {
    return x+xdot*dt;
}
