#ifndef EQMO_QUATERNION_H_INCLUDED
#define EQMO_QUATERNION_H_INCLUDED

class eqmo_quaternion_input_bus {
public:
    float q0_n, q1_n, q2_n, q3_n;
    float p_rps, q_rps, r_rps;
};

class eqmo_quaternion_output_bus {
public:
    float q0dot_ps, q1dot_ps, q2dot_ps, q3dot_ps;
};

eqmo_quaternion_output_bus eqmo_quaternion(eqmo_quaternion_input_bus);

class quaternion_vector {
public:
    float q0_n, q1_n, q2_n, q3_n;
};

class euler_angle_vector {
public:
    float phi_rad, theta_rad, psi_rad;
};

euler_angle_vector quaternion2euler(euler_angle_vector);

#endif
