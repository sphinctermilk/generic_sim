#ifndef STEP_H_INCLUDED
#define STEP_H_INCLUDED


class step_function_output_bus {
public:
    float[] time_vector;
    float[] step_vector;
};

step_function_output_bus generate_step_vector (float, float, float, float, float, float);

#endif
