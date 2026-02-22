#include "eqmo_quaternion.h"
#include <cmath>

eqmo_quaternion_output_bus eqmo_quaternion(eqmo_quaternion_input_bus inputs) {
    // get data out of inputs
    float q0 = inputs.q0_n;
    float q1 = inputs.q1_n;
    float q2 = inputs.q2_n;
    float q3 = inputs.q3_n;
    float p = inputs.p_rps;
    float q = inputs.q_rps;
    float r = inputs.r_rps;

    // quaternion rate calculations
    eqmo_quaternion_output_bus outputs;
    outputs.q0dot_ps = 0.5*(-p*q1-q*q2-r*q3);
    outputs.q1dot_ps = 0.5*(p*q0+r*q2-q*q3);
    outputs.q2dot_ps = 0.5*(q*q0-r*q1+p*q3);
    outputs.q3dot_ps = 0.5*(r*q0+q*q1-p*q2);
    return outputs;
}

euler_angle_vector quaternion2euler(quaternion_vector inputs) {
    // get data out of inputs
    float q0 = inputs.q0_n;
    float q1 = inputs.q1_n;
    float q2 = inputs.q2_n;
    float q3 = inputs.q3_n;

    // quaternion to euler conversion calculations
    euler_angle_vector outputs;
    outputs.phi_rad = std::atan2(2*(q0*q1+q2*q3), 1-2*(q1*q1+q2*q2));
    outputs.theta_rad = std::asin(2*(q0*q2-q3*q1));
    outputs.psi_rad = std::atan2(2*(q0*q3+q1*q2), 1-2*(q2*q2+q3*q3));
    return outputs;
}
