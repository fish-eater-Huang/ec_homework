//
// Created by 15795 on 2023/12/24.
//

#include "motor_monitor.h"
#include  "../PID/pid.h"
#include "../Motor/motor.h"
// Motor parameter config
// 电机参数配置

// Chassis motor 底盘电机
const PID chassis_wheel_spid(40, 1, 10, 1000, 16384);
Motor CMFL(Motor::M3508, 3591.f / 187.f, Motor::SPEED,  // type, ratio, method
           PID(), PID(chassis_wheel_spid));             // ppid, spid
Motor CMFR(Motor::M3508, 3591.f / 187.f, Motor::SPEED,  // type, ratio, method
           PID(), PID(chassis_wheel_spid));             // ppid, spid
Motor CMBL(Motor::M3508, 3591.f / 187.f, Motor::SPEED,  // type, ratio, method
           PID(), PID(chassis_wheel_spid));             // ppid, spid
Motor CMBR(Motor::M3508, 3591.f / 187.f, Motor::SPEED,  // type, ratio, method
           PID(), PID(chassis_wheel_spid));             // ppid, spid

// Gimbal motor 云台电机
Motor GMY(Motor::GM6020, 1, Motor::POSITION_SPEED,   // type, ratio, method
          PID(25, 0.1, 10, 10, 1800),                // ppid
          PID(400, 2, 0, 500, 30000)               // spid
          );
Motor GMP(Motor::GM6020, -1, Motor::POSITION_SPEED,  // type, ratio, method
          PID(25, 0.1, 10, 10, 1800),                // ppid
          PID(400, 2, 0, 500, 30000)                // spid
          );

// Friction wheel motors
const PID fric_spid(6, 0.05, 2, 200, 16384);
Motor FRICL(Motor::M3508, 1, Motor::SPEED,  // type, ratio, method
            PID(), PID(fric_spid));         // ppid, spid
Motor FRICR(Motor::M3508, 1, Motor::SPEED,  // type, ratio, method
            PID(), PID(fric_spid));         // ppid, spid

// Stir motor
Motor STIR(Motor::M2006, 36, Motor::POSITION_SPEED,  // type, ratio, method
           PID(20, 0.1, 10, 10, 2500),               // ppid
           PID(60, 0.1, 200, 1000, 10000));          // spid

// Other motors
Motor m1(Motor::M3508, 1, Motor::POSITION_SPEED,  // type, ratio, method
         PID(50, 0.02, 50, 200, 36000),           // ppid
         PID(20, 0.02, 50, 200, 16384));          // spid
