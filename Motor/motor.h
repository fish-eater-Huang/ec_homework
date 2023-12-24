//
// Created by 15795 on 2023/12/24.
//

#include "../PID/PID.h"
#include "main.h"
#ifndef EC_HOMEWORK_MOTOR_H
#define EC_HOMEWORK_MOTOR_H

class Motor {
public:
    typedef enum Type {
        M3508,
        M2006,
        GM6020,
    }Type_e;
    typedef enum ControlMethod {
        POSITION_SPEED, // 位置， 速度双环 PID 控制
        SPEED, // 速度单环 PID 控制
    }ControlMethod_e;
    enum Mode {
        POWER_OFF, // 断电， 控制量置零
        STOP, // 将目标速度置零， 计算得出控制量， 使得电机停转
        WORKING, // 电机正常工作
    };
public:
    Motor(const Type_e& type, const float& ratio, const ControlMethod_e& method,
          const PID& ppid, const PID& spid);
    void Reset(void); // 重置电机所有状态
    void Handle(void); // 根据当前 mode_ 计算控制量
    void SetAngle(const float& target_angle); // 设置目标角度
    void SetSpeed(const float& target_speed); // 设置目标速度
    void CANIdConfig(const uint8_t& can_channel, const uint8_t& id);
public:
    struct MotorInfo {
        Type type;
        float ratio; // 减速比
        float max_intensity;  // 控制信号限幅
        uint8_t can_channel;
        uint8_t id;
    } info_;
    Mode mode_;
    ControlMethod method_;
    int16_t intensity_; // 控制量
    float  intensity_float_;
    float target_angle, target_speed; // 期望角度、 速度
    struct MotorData {
        float angle; // 减速后的输出端角度
        float ecd_angle; // 编码器角度float last_ecd_angle;
        float rotate_speed; // 减速后的输出端转速
        float current; // 转矩电流
        float temp; // 电机温度
    } motor_data_;
    PID ppid_, spid_;
};
#endif //EC_HOMEWORK_MOTOR_H
