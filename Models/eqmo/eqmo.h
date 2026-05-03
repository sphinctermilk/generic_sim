#ifndef EQMO_H_INCLUDED
#define EQMO_H_INCLUDED

class eqmo_input_bus {
public:
    float u_fps_z, v_fps_z, w_fps_z;
    float p_rps_z, q_rps_z, r_rps_z;
    float q0_n_z, q1_n_z, q2_n_z, q3_n_z;
    float udot_fps2_z, vdot_fps2_z, wdot_fps2_z;
    float pdot_rps2_z, qdot_rps2_z, rdot_rps2_z;
    float q0dot_ps_z, q1dot_ps_z, q2dot_ps_z, q3dot_ps_z;
    float fx_lbf, fy_lbf, fz_lbf;
    float mx_ftlbf, my_ftlbf, mz_ftlbf;
    float m_slug;
    float ixx_slugft2, iyy_slugft2, izz_slugft2;
    float ixy_slugft2, ixz_slugft2, iyz_slugft2;
    float dt;
};

class eqmo_output_bus {
public:
    float u_fps, v_fps, w_fps;
    float p_rps, q_rps, r_rps;
    float q0_n, q1_n, q2_n, q3_n;
    float phi_rad, theta_rad, psi_rad;
    float udot_fps2, vdot_fps2, wdot_fps2;
    float pdot_rps2, qdot_rps2, rdot_rps2;
    float q0dot_ps, q1dot_ps, q2dot_ps, q3dot_ps;
};

eqmo_output_bus eqmo(eqmo_input_bus);

#endif
