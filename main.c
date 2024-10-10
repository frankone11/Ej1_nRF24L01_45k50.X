/*
 * File:   main.c
 * Author: paco
 *
 * Created on 25 de abril de 2022, 08:21 PM
 */
#include <stdio.h>
#include "tcb_principal.h"

uint8_t bufferRX[32];

void main(void)
{
	uint8_t dato = 0;
	TCB_Sistema_Inicializa();
	UART1_Inicializa();
	SPI1_Inicializa(); 
	
	printf("\r\n**********\r\n");
	printf("TCB Ej1. TEST MODE nRF24L01 (RX)\r\n\r\n");
	
	dato = NRF24L01_ReadRegister(CONFIG);
	
	printf("Se leyo el registro 0x%02X con valor 0x%02X\r\n", CONFIG, dato);
	
	while(1); //Ciclo infinito
	
	printf("TCB Ej1. nRF24L01 (RX)\r\n\r\n");
	printf("Iniciando nRF24L01.\r\n");
	
	NRF24L01_Init(RX_MODE, 0x40);
	printf("Esperando dato...\r\n");
	while(1)
	{
		while(NRF24L01_DataReady());
		NRF24L01_ReadData(bufferRX);
		//PORTB = bufferRX[0];
		printf("Se ha recibido el dato 0x%02X (%03d).\r\n\r\n", bufferRX[0], bufferRX[0]);
	}
}

void putch(char c)
{
	UART1_Envia(c);
	UART1_Espera();
}