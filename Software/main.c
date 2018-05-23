#define F_CPU 16000000UL  //definiujemy F_CPU na 16MHz  
#include <avr/io.h>
#include <util/delay.h>

uint8_t byte;				// definicja zmiennej do SPI


static inline void SPI_SET_SS()
{
	PORTB|=(1<<PB4);
}

void SPI_master_init()
{
	SPI_SET_SS();
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPI2X); // tryb master, CLK/2 (podwojna predkosc SPI)
	SPSR;
	SPDR; // skasuj flage SPIF
}

void SPI_send(uint8_t byte)
{
	PORTB&=~(_BV(PB4));
	SPDR=byte;
	while(!(SPSR & _BV(SPIF)));
	PORTB|=_BV(PB4);
}

void SPI_send_no_latch(uint8_t byte)
{
	PORTB&=~(_BV(PB4));
	SPDR=byte;
	while(!(SPSR & _BV(SPIF)));
	
}

void zatrzask()
{
	PORTB|=_BV(PB4);
	_delay_ms(1);
	PORTB&=~(_BV(PB4));
}

void shift_reset()
{
	for(int i=0;i<8;i++)
	{
		SPI_send_no_latch(0x00);
	}
}

void odliczanie()
{
	int czas=1;
	int petla = 60;
	// deklaracja cyfr ==========================================

	uint8_t zero[8][8]=
	{{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0xC0,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0xC0,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0xC0,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0xC0,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00}};

	uint8_t jeden[8][8]=
	{{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00}};

	uint8_t dwa[8][8]=
	{{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00},
	{0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00}};


	uint8_t trzy[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xc0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00}};

	uint8_t cztery[8][8]=
	{{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00}};

	uint8_t piec[8][8]=
	{{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00}};

	uint8_t szesc[8][8]=
	{{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00}};

	uint8_t siedem[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00},
	{0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00}};

	uint8_t osiem[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x00,0xC0,0xC0,0xC0,0xC0,0x00,0x00}};


	uint8_t dziewiec[8][8]=
	{{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00}};

	//==================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(dziewiec[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//===================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(osiem[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(siedem[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(szesc[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(piec[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(cztery[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(trzy[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(dwa[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(jeden[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}

	//====================================================
	for(int ii=0;ii<petla;ii++)
	{
		for(int i=0;i<8;i++)
		{
			
			for(int k=0;k<8;k++)
			{
				SPI_send_no_latch(zero[i][k]);
			}
			zatrzask();
			PORTC = 1<<i;
			_delay_ms(czas);
		}
	}
	//====================================================
	PORTC=0x00;
	shift_reset();
}

void kostka()
{
	shift_reset();
	int czas=30;

	for(int a=0;a<5;a++)
	{
		// narysuj kostke 4x4
		for(int i=0;i<4;i++)
		{
			SPI_send(0xF);
		}
		//===================
		PORTC=0xf; // wlacz 4 warstwy
		_delay_ms(czas);
		shift_reset();
		//przesowanie kostki do przodu
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x1E);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x3C);
		}
		
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x78);
		}
		
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF0);
		}
		zatrzask();
		_delay_ms(czas);
		// ruch kostki w g�re
		PORTC=0x1E;
		_delay_ms(czas);
		PORTC=0x3C;
		_delay_ms(czas);
		PORTC=0x78;
		_delay_ms(czas);
		PORTC=0xF0;
		_delay_ms(czas);
		//====================

		// ruch w prawo na g�re
		for(int i=0;i<4;i++)
		{
			SPI_send(0x00);
			_delay_ms(czas);
		}
		//=====================
		//ruch w d� ==========
		PORTC=0xF0;
		_delay_ms(czas);
		PORTC=0x78;
		_delay_ms(czas);
		PORTC=0x3C;
		_delay_ms(czas);
		PORTC=0x1E;
		_delay_ms(czas);
		PORTC=0xF;
		_delay_ms(czas);
		//=====================

		// cofanie do ty�u kostki

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x78);
		}
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x3C);
		}
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x1E);
		}
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();


		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF);
		}
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();
		
		// ruch kostki w g�re
		PORTC=0x1E;
		_delay_ms(czas);
		PORTC=0x3C;
		_delay_ms(czas);
		PORTC=0x78;
		_delay_ms(czas);
		PORTC=0xF0;
		_delay_ms(czas);
		//====================
		
		// ruch kostki w lewo=================
		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF);
		}
		for(int i=0;i<3;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF);
		}
		for(int i=0;i<2;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF);
		}
		for(int i=0;i<1;i++)
		{
			SPI_send_no_latch(0x00);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		for(int i=0;i<4;i++)
		{
			SPI_send_no_latch(0xF);
		}
		zatrzask();
		_delay_ms(czas);
		shift_reset();

		//ruch w d� ==========
		PORTC=0xF0;
		_delay_ms(czas);
		PORTC=0x78;
		_delay_ms(czas);
		PORTC=0x3C;
		_delay_ms(czas);
		PORTC=0x1E;
		_delay_ms(czas);
		PORTC=0xF;
		_delay_ms(czas);
		//=====================
	}

}



int main(void)
{
	DDRC = 0xFF;
	DDRB = 0xBF; // MISO jako wej�cie, reszta wyj�cia
	DDRD = 0xFF;
	PORTC = 0x00; // Warstwy nie aktywne
	PORTD = 0x00;
	
	SPI_master_init();		// inicjacja SPI tryb master
	SPDR=0;					// bufor SPI = 0;

	while(1)
	{
		odliczanie();
		_delay_ms(100);
		kostka();
		_delay_ms(100);
	}
}


