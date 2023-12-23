//
// Created by 15795 on 2023/12/23.
//

#include "PID.h"

PID::PID(float kp, float ki, float kd, float i_max, float out_max)
{
    kp_ = kp;
    kd_ = kd;
    ki_ = ki;
    i_max_ = i_max;
    out_max_ = out_max;
    err_ = 0;
    last_err_ = 0;
    err_sum_ = 0;
}
