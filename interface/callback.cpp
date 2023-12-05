//
// Created by 15795 on 2023/12/5.
//

#include "callback.h"
#include "usart.h"
#include "../remote/remote.h"

extern uint8_t rx_buf[18];
extern RC rc;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart3) {
        rc.rxCallback();
    }
    /*
    if (cv_comm.uartCheck(huart)) {
        cv_comm.rxCallback();
    }
    if (referee.uartCheck(huart)) {
        referee.rxCallback();
    }
    if (serial_tool.uartCheck(huart)) {
        serial_tool.uartRxCallback();
    }
    */
}