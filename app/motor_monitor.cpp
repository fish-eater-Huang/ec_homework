//
// Created by 15795 on 2023/12/24.
//

#include "motor_monitor.h"
#include  "../PID/pid.h"
#include "../Motor/motor.h"
#include "../Motor/Driver/dji_motor_driver.h"
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

// DJI Motor id config, M3508/M2006: 1~8, GM6020: 5~11
// DJI电机ID配置，M3508，M2006可配置范围为1~8，GM6020可配置范围为5~11
Motor* can1_dji_motor[11] = {
        &FRICL,   // id:1
        &FRICR,   // id:2
        nullptr,  // id:3
        nullptr,  // id:4
        &STIR,    // id:5
        &GMP,     // id:6
        nullptr,  // id:7
        &m1,      // id:8
        nullptr,  // id:9
        nullptr,  // id:10
        nullptr   // id:11
};
Motor* can2_dji_motor[11] = {
        &CMFL,    // id:1
        &CMFR,    // id:2
        &CMBL,    // id:3
        &CMBR,    // id:4
        &GMY,     // id:5
        nullptr,  // id:6
        nullptr,  // id:7
        nullptr,  // id:8
        nullptr,  // id:9
        nullptr,  // id:10
        nullptr   // id:11
};

DJIMotorDriver dji_motor_driver(can1_dji_motor, can2_dji_motor);

void motorsCanRxMsgHandle(CAN_HandleTypeDef* hcan,
                          CAN_RxHeaderTypeDef rx_header, uint8_t* rx_data) {
    if (dji_motor_driver.canRxMsgCheck(hcan, rx_header)) {
        dji_motor_driver.canRxMsgCallback(hcan, rx_header, rx_data);
    }
}