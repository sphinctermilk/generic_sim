#include "eqmo_angular_velocity.h"
#include <Eigen/Dense>

eqmo_angular_velocity_output_bus eqmo_angular_velocity(eqmo_angular_velocity_input_bus inputs) {
    // get data out of inputs
    Eigen::Matrix3f I;
    I[0][0] = inputs.ixx_slugft2; I[0][1] = inputs.ixy_slugft2; I[0][2] = inputs.ixz_slugft2;
    I[1][0] = inputs.ixy_slugft2; I[1][1] = inputs.iyy_slugft2; I[1][2] = inputs.iyz_slugft2;
    I[2][0] = inputs.ixz_slugft2; I[2][1] = inputs.iyz_slugft2; I[2][2] = inputs.izz_slugft2;
    Eigen::MatrixXf omega(3, 1), M(3, 1);
    omega[0] = inputs.p_rps; omega[1] = inputs.q_rps; omega[2] = inputs.r_rps;
    M[0] = inputs.mx_ftlbf; M[1] = inputs.my_ftlbf; M[2] = inputs.mz_ftlbf;

    // angular velocity rate calculations
    eqmo_angular_velocity_output_bus outputs;
    Eigen::Matrix3f inverse_I = I.inverse();
    Eigen::MatrixXf omegadot(3, 1);
    omegadot = inverse_I*(M-(omega.vector().cross((I*omega).vector())).matrix());
    outputs.pdot_rps2 = omegadot[0][0];
    outputs.qdot_rps2 = omegadot[1][0];
    outputs.rdot_rps2 = omegadot[2][0];
}
