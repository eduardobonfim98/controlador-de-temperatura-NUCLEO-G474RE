#ifndef COMMUNICATION_STATE_MACHINE_H
#define COMMUNICATION_STATE_MACHINE_H

#include "stm32g4xx_hal.h"

#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define SEND '5'
#define VALUE '6'
#define SET2 '7'

#define MAX_VALUE_LENGTH 7

extern UART_HandleTypeDef hlpuart1;
extern unsigned char ucUartState;
extern unsigned char ucValueCount;
extern unsigned char c;

extern float fActualTemp;
extern float fDesiredTemp;
extern unsigned int uiCoolerSpeed;
extern unsigned char ucButtonState;
extern unsigned char ucDutyCycleCooler;
extern unsigned char ucDutyCycleHeather;

// Function prototypes
void vCommunicationStateMachineInit(UART_HandleTypeDef *huart);
void vCommunicationStateMachineProcessByteCommunication(unsigned char ucByte);
void vCommunicationStateMachineReturnParam(unsigned char param);
void vCommunicationStateMachineSetParam(unsigned char param, unsigned char *value);
void vCommunicationStateMachineTransmit(const char* data);

#endif // COMMUNICATION_STATE_MACHINE_H
