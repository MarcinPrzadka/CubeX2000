void USART_Init( uint16_t baud){  // inicjalizacja UART
	UBRRH = (uint16_t)(baud>>8);
	UBRRL = (uint16_t)baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void USART_Transmit( char buflen) {		// wysy³anie uart
	while( !(UCSRA & (1<<UDRE)) );
	UDR = buflen;
}
	
unsigned char USART_Receive( void ){ 	// odbieranie uart
    
	while( !(UCSRA & (1<<RXC)) );		
	return UDR; 
}
