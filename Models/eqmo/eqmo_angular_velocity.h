#ifndef EQMO_ANGULAR_VELOCITY_H_INCLUDED
#define EQMO_ANGULAR_VELOCITY_H_INCLUDED

class eqmo_angular_velocity_input_bus {
public:
    float p_rps, q_rps, r_rps;
    float mx_ftlbf, my_ftlbf, mz_ftlbf;
    float ixx_slugft2, iyy_slugft2, izz_slugft2;
    float ixy_slugft2, ixz_slugft2, iyz_slugft2;
};

class eqmo_angular_velocity_output_bus {
public:
    float pdot_rps2, qdot_rps2, rdot_rps2;
};

eqmo_angular_velocity_output_bus eqmo_angular_velocity(eqmo_angular_velocity_input_bus);

#endif
