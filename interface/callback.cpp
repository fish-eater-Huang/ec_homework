//
// Created by 15795 on 2023/12/5.
//

#include "callback.h"
#include "usart.h"
extern uint8_t rx_buf[18];
long long t=0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    t++;
    HAL_UART_Receive_IT(&huart3,rx_buf,18); /* USER CODE END 2 */
}