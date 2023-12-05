//
// Created by 15795 on 2023/12/5.
//
#include "usart.h"
#ifndef EC_HOMEWORK_REMOTE_H
#define EC_HOMEWORK_REMOTE_H

#define RC_RX_BUF_SIZE 36u
#define RC_FRAME_LEN 18u

class RC {
public:
    // remote switch 遥控器拨挡
    typedef enum RCSwitchState {
        UP,
        MID,
        DOWN,
    } RCSwitchState_e;

public:
    RC(UART_HandleTypeDef* huart = nullptr);
    void init();
    void handle();
    void reset();
    void rxCallback();

public:

    // remote channel 遥控器通道
    struct RCChannel {
        int16_t r_row;
        int16_t r_col;
        int16_t l_row;
        int16_t l_col;
        int16_t dial_wheel;
    } channel_;
    // remote switch 遥控器拨挡
    struct RCSwitch {
        RCSwitchState_e l;
        RCSwitchState_e r;
    } switch_;
    // mouse 鼠标
    struct Mouse {
        int16_t x;
        int16_t y;
        int16_t z;
        bool press_l;
        bool press_r;
    } mouse_;

private:
    UART_HandleTypeDef* huart_;
    uint8_t rx_buf_[RC_RX_BUF_SIZE], rx_data_[RC_FRAME_LEN];
    volatile uint8_t rx_len_;

    struct RCRaw {
        int16_t ch[5];
        uint8_t s[2];
    } rc_raw_;
};
#endif //EC_HOMEWORK_REMOTE_H
