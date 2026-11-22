#include "time_vector.h"

// the purpose of this function is to generate an evenly spaced time vector from start time to end time
float[] generate_time_vector (float start_time, float end_time, float dt) {
    int time_steps;
    num_time_steps = static_cast<int>((end_time-start_time)/dt)+1;
    float time_steps[num_time_steps];
    for (int time_index=0; time_index<num_time_steps; time_index++) {
        time_steps[time_index] = start_time+time_index*dt;
    }
    return time_steps;
}
