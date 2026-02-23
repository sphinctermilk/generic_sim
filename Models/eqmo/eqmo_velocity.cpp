#include "eqmo_velocity.h"

eqmo_velocity_output_bus eqmo_velocity(eqmo_velocity_input_bus inputs) {
    // get data out of inputs
    float u = inputs.u_fps;
    float v = inputs.v_fps;
    float w = inputs.w_fps;
    float p = inputs.p_rps;
    float q = inputs.q_rps;
    float r = inputs.r_rps;
    float fx = inputs.fx_lbf;
    float fy = inputs.fy_lbf;
    float fz = inputs.fz_lbf;
    float m = inputs.m_slug;

    // velocity rate calculations
    eqmo_velocity_output_bus outputs;
    if (m < 1e-8) {
        m = 1e-8;
    }
    outputs.udot_fps2 = fx/m-w*q+v*r;
    outputs.vdot_fps2 = fy/m-u*r+w*p;
    outputs.wdot_fps2 = fz/m-v*p+u*q;
    return outputs;
}
