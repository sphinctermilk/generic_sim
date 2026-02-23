#ifndef EQMO_VELOCITY_H_INCLUDED
#define EQMO_VELOCITY_H_INCLUDED

class eqmo_velocity_input_bus {
public:
    float u_fps, v_fps, w_fps;
    float p_rps, q_rps, r_rps;
    float fx_lbf, fy_lbf, fz_lbf;
    float m_slug;
};

class eqmo_velocity_output_bus {
public:
    float udot_fps2, vdot_fps2, wdot_fps2;
};

eqmo_velocity_output_bus eqmo_velocity(eqmo_velocity_input_bus);

#endif
