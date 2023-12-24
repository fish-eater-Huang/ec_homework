//
// Created by 15795 on 2023/12/24.
//

#include "motor.h"
#include "../Math/math.h"

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

void Motor::SetAngle(const float& target_angle)
{
    this->target_angle = target_angle;
}

void Motor::SetSpeed(const float &target_speed)
{
    this->target_speed = target_speed;
}

void Motor::CANIdConfig(const uint8_t& can_channel, const uint8_t& id) {
    info_.can_channel = can_channel;
    info_.id = id;
}

void Motor::Handle() {


    // Update control feedback (fdb_src->fdb)
    // 更新控制反馈 (fdb_src->fdb)
    // 提取fdb_angle(两次指针取值间fdb_angle_src的值可能被改变)
//    float fdb_angle_src = *motor_data_.angle_src;
//    motor_data_.angle +=
//            math::degNormalize180(fdb_angle_src - control_data_.last_fdb_angle);
//    control_data_.fdb_speed = *control_data_.fdb_speed_src;
//    control_data_.last_fdb_angle = fdb_angle_src;

    // Calculateulate intensity(control value)
    // 计算控制量
    if (mode_ == WORKING) {
        if (method_ == Motor::POSITION_SPEED) {  // 位置速度双环
            target_speed =
                    ppid_.Calculate(target_angle, motor_data_.angle);
            intensity_float_ =
                    spid_.Calculate(target_speed, motor_data_.rotate_speed);
        } else if (method_ == Motor::SPEED) {  // 单速度环
            target_angle = motor_data_.angle;
            intensity_float_ = spid_.Calculate(target_speed, motor_data_.rotate_speed);
        }


    } else if (mode_ == STOP) {
        if (method_ == Motor::POSITION_SPEED || method_ == Motor::SPEED) {
            target_speed = 0;
            intensity_float_ =
                    spid_.Calculate(target_speed, motor_data_.rotate_speed);
        }

        // 设定控制信号最大范围
        if (info_.type == Motor::M3508) {
            info_.max_intensity = 16384;
        } else if (info_.type == Motor::M2006) {
            info_.max_intensity = 10000;
        } else if (info_.type == Motor::GM6020) {
            info_.max_intensity = 30000;
        }
        }
        // 根据减速比确定输出方向
        intensity_float_ = math::limit(intensity_float_ * math::sign(info_.ratio),
                                       -info_.max_intensity, info_.max_intensity);

        intensity_ = intensity_float_;
    }
