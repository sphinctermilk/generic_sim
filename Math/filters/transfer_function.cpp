#include "transfer_function.h"

// calculation of 1st order transfer function output based on Tustin approximation
float first_order_tf(float state_n_1, float input_n, float input_n_1, float tau, float dt) {
    float state_n;
    state_n = ((2*tau-dt)*state_n_1+dt*input_n_1+dt*input_n)/(2*tau+dt);
    return state_n;
}

// calculation of 2nd order transfer function output based on Tustin approximation
float second_order_tf(float state_n_1, float state_n_2, float input_n, float input_n_1, float input_n_2, float zeta, float omega_n, float dt) {
    float state_n;
    float C_state_n = 4+4*zeta*omega_n*dt+omega_n*omega_n*dt*dt;
    float C_state_n_1 = -8+2*omega_n*omega_n*dt*dt;
    float C_state_n_2 = 4-4*zeta*omega_n*dt+omega_n*omega_n*dt*dt;
    float C_input_n = omega_n*omega_n*dt*dt;
    float C_input_n_1 = 2*omega_n*omega_n*dt*dt;
    float C_input_n_2 = omega_n*omega_n*dt*dt;
    state_n = (C_input_n*input_n+C_input_n_1*input_n_1+C_input_n_2*input_n_2-C_state_n_1*state_n_1-C_state_n_2*state_n_2)/C_state_n;
    return state_n;
}
