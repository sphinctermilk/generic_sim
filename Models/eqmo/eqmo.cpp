#include "eqmo.h"
#include "eqmo_velocity.h"
#include "eqmo_angular_velocity.h"
#include "eqmo_quaternion.h"
#include "../../Math/integration/trapezoidal_integrator.h"

eqmo_output_bus eqmo(eqmo_input_bus inputs) {
    // set up outputs
    eqmo_output_bus outputs;

    // set up velocity buses and do calcs
    eqmo_velocity_input_bus velocity_inputs;
    eqmo_velocity_output_bus velocity_outputs;
    velocity_inputs.u_fps = inputs.u_fps_z;
    velocity_inputs.v_fps = inputs.v_fps_z;
    velocity_inputs.w_fps = inputs.w_fps_z;
    velocity_inputs.p_rps = inputs.p_rps_z;
    velocity_inputs.q_rps = inputs.q_rps_z;
    velocity_inputs.r_rps = inputs.r_rps_z;
    velocity_inputs.fx_lbf = inputs.fx_lbf;
    velocity_inputs.fy_lbf = inputs.fy_lbf;
    velocity_inputs.fz_lbf = inputs.fz_lbf;
    velocity_inputs.m_slug = inputs.m_slug;
    velocity_outputs = eqmo_velocity(velocity_inputs);
    outputs.udot_fps2 = velocity_outputs.udot_fps2;
    outputs.vdot_fps2 = velocity_outputs.vdot_fps2;
    outputs.wdot_fps2 = velocity_outputs.wdot_fps2;
    outputs.u_fps2 = trapezoidal_integrate(inputs.u_fps_z, velocity_outputs.udot_fps2, inputs.udot_fps2_z, inputs.dt);
    outputs.v_fps2 = trapezoidal_integrate(inputs.v_fps_z, velocity_outputs.vdot_fps2, inputs.vdot_fps2_z, inputs.dt);
    outputs.w_fps2 = trapezoidal_integrate(inputs.w_fps_z, velocity_outputs.wdot_fps2, inputs.wdot_fps2_z, inputs.dt);

    // set up angular velocity buses and do calcs
    eqmo_angular_velocity_input_bus angular_velocity_inputs;
    eqmo_angular_velocity_output_bus angular_velocity_outputs;
    angular_velocity_inputs.p_rps = inputs.p_rps_z;
    angular_velocity_inputs.q_rps = inputs.q_rps_z;
    angular_velocity_inputs.r_rps = inputs.r_rps_z;
    angular_velocity_inputs.mx_ftlbf = inputs.mx_ftlbf;
    angular_velocity_inputs.my_ftlbf = inputs.my_ftlbf;
    angular_velocity_inputs.mz_ftlbf = inputs.mz_ftlbf;
    angular_velocity_inputs.ixx_slugft2 = inputs.ixx_slugft2;
    angular_velocity_inputs.iyy_slugft2 = inputs.iyy_slugft2;
    angular_velocity_inputs.izz_slugft2 = inputs.izz_slugft2;
    angular_velocity_inputs.ixy_slugft2 = inputs.ixy_slugft2;
    angular_velocity_inputs.ixz_slugft2 = inputs.ixz_slugft2;
    angular_velocity_inputs.iyz_slugft2 = inputs.iyz_slugft2;
    angular_velocity_outputs = eqmo_angular_velocity(angular_velocity_inputs);
    outputs.pdot_rps2 = angular_velocity_outputs.pdot_rps2;
    outputs.qdot_rps2 = angular_velocity_outputs.qdot_rps2;
    outputs.rdot_rps2 = angular_velocity_outputs.rdot_rps2;
    outputs.p_rps = trapezoidal_integrate(inputs.p_rps_z, angular_velocity_outputs.pdot_rps2, inputs.pdot_rps2_z, inputs.dt);
    outputs.q_rps = trapezoidal_integrate(inputs.q_rps_z, angular_velocity_outputs.qdot_rps2, inputs.qdot_rps2_z, inputs.dt);
    outputs.r_rps = trapezoidal_integrate(inputs.r_rps_z, angular_velocity_outputs.rdot_rps2, inputs.rdot_rps2_z, inputs.dt);

    // set up quaternion buses and do calcs
    eqmo_quaternion_input_bus quaternion_inputs;
    eqmo_quaternion_output_bus quaternion_outputs;
    quaternion_inputs.q0_n = inputs.q0_n_z;
    quaternion_inputs.q1_n = inputs.q1_n_z;
    quaternion_inputs.q2_n = inputs.q2_n_z;
    quaternion_inputs.q3_n = inputs.q3_n_z;
    quaternion_inputs.p_rps = inputs.p_rps_z;
    quaternion_inputs.q_rps = inputs.q_rps_z;
    quaternion_inputs.r_rps = inputs.r_rps_z;
    quaternion_outputs = eqmo_quaternion(quaternion_inputs);
    outputs.q0dot_ps = quaternion_outputs.q0dot_ps;
    outputs.q1dot_ps = quaternion_outputs.q1dot_ps;
    outputs.q2dot_ps = quaternion_outputs.q2dot_ps;
    outputs.q3dot_ps = quaternion_outputs.q3dot_ps;
    outputs.q0_n = trapezoidal_integrate(inputs.q0_n_z, quaternion_outputs.q0dot_ps, inputs.q0dot_ps_z, inputs.dt);
    outputs.q1_n = trapezoidal_integrate(inputs.q1_n_z, quaternion_outputs.q1dot_ps, inputs.q1dot_ps_z, inputs.dt);
    outputs.q2_n = trapezoidal_integrate(inputs.q2_n_z, quaternion_outputs.q2dot_ps, inputs.q2dot_ps_z, inputs.dt);
    outputs.q3_n = trapezoidal_integrate(inputs.q3_n_z, quaternion_outputs.q3dot_ps, inputs.q3dot_ps_z, inputs.dt);
    quaternion_vector euler_inputs;
    euler_angle_vector euler_outputs;
    euler_inputs.q0_n = outputs.q0_n;
    euler_inputs.q1_n = outputs.q1_n;
    euler_inputs.q2_n = outputs.q2_n;
    euler_inputs.q3_n = outputs.q3_n;
    euler_outputs = quaternion2euler(euler_inputs);
    outputs.phi_rad = euler_outputs.phi_rad;
    outputs.theta_rad = euler_outputs.theta_rad;
    outputs.psi_rad = euler_outputs.psi_rad;

    // return statement
    return outputs;
}
