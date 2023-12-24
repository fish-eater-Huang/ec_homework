//
// Created by 15795 on 2023/12/24.
//

#include "motor.h"


Motor::Motor(const Type_e& type, const float& ratio, const ControlMethod_e& method,
      const PID& ppid, const PID& spid)
{
    info_.ratio = ratio;
    info_.type = type;
    method_ = method;
    ppid_ = ppid;
    spid_ = spid;
}

void Motor::Reset()
{
    motor_data_.angle = 0;
    motor_data_.rotate_speed = 0;

    target_angle = 0;

    target_speed = 0;

    motor_data_.angle = 0;
    motor_data_.current = 0;
    motor_data_.ecd_angle = 0;
    motor_data_.rotate_speed = 0;
    motor_data_.temp = 0;

    ppid_.reset();
    spid_.reset();
}