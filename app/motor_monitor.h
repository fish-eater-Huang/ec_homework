//
// Created by 15795 on 2023/12/24.
//
#include "can.h"
#include "stm32f4xx_hal_can.h"

#ifndef EC_HOMEWORK_MOTOR_MONITOR_H
#define EC_HOMEWORK_MOTOR_MONITOR_H
void motorsCanRxMsgHandle(CAN_HandleTypeDef* hcan,
                          CAN_RxHeaderTypeDef rx_header, uint8_t* rx_data);
#endif //EC_HOMEWORK_MOTOR_MONITOR_H
