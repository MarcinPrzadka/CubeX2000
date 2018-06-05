#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "uart.h"
#include "znak.h"

#define F_CPU 16000000UL  // F_CPU na 16MHz  
#define FOSC 1843200 
#define BAUD 9600
#define MYUBRR ((F_CPU+BAUD*8UL) / (16UL*BAUD)-1) 

uint8_t byte;				// definicja zmiennej do SPI

int main(void)
{
	DDRC = 0xFF;
	DDRB = 0xBF; // MISO jako wej?cie, reszta wyj?cia
	DDRD = 0xFF;
	PORTC = 0x00; // Warstwy nie aktywne
	PORTD = 0x00;
	
	USART_Init(MYUBRR);		// inicjacjia UART
	SPI_master_init();		// inicjacja SPI tryb master
	SPDR=0;					// bufor SPI = 0;

	unsigned char data;	

	while(1)
	{
		data = USART_Receive();
		//if(data = "a") kostka();
		USART_Transmit(data);
		znak(data);
	}
}



