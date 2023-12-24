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