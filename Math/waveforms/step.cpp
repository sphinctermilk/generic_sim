#include "step.h"
#include "time_vector.h"

// the purpose of this function is to make a step output vector
float[] generate_step_vector (float start_time, float end_time, float step_time, float IC, float step_value, float dt) {
    // calculate time and step vectors
    float time_vector[];
    time_vector = generate_time_vector(start_time, end_time, dt);
    num_time_steps = static_cast<int>((end_time-start_time)/dt)+1;
    float step_vector[num_time_steps];
    for (int index; index<num_time_steps; index++) {
        if (time_vector[index] >= step_time) {
            step_vector[index] = step_value;
        } else {
            step_vector[index] = IC;
        }
    }

    // return statement
    step_function_output_bus step_output;
    step_function_output_bus.time_vector = time_vector;
    step_function_output_bus.step_vector = step_vector;
    return step_function_output_bus;
}
