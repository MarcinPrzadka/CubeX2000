static inline void SPI_SET_SS()		// ustawienie spi 
{
	PORTB|=(1<<PB4);
}

void SPI_master_init()           // ustawienie spi 
{
	SPI_SET_SS();
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPI2X); // tryb master, CLK/2 (podwojna predkosc SPI)
	SPSR;
	SPDR; // skasuj flage SPIF
}

void SPI_send(uint8_t byte)			// ustawienie spi 
{
	PORTB&=~(_BV(PB4));
	SPDR=byte;
	while(!(SPSR & _BV(SPIF)));
	PORTB|=_BV(PB4);
}

void SPI_send_no_latch(uint8_t byte)		// ustawienie spi 
{
	PORTB&=~(_BV(PB4));
	SPDR=byte;
	while(!(SPSR & _BV(SPIF)));
	
}

void zatrzask() 	// ustawienie spi 
{
	PORTB|=_BV(PB4);
	_delay_ms(1);
	PORTB&=~(_BV(PB4));
}

void shift_reset()   // ustawienie spi 
{
	for(int i=0;i<8;i++)
	{
		SPI_send_no_latch(0x00);
	}
}
