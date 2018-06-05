void znak(char data)
{
	uint8_t zero[8][8]=
	{{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0xC0,0x01,0x00},
	{0x00,0x01,0x00,0x00,0xC0,0x00,0x01,0x00},
	{0x00,0x01,0x00,0xC0,0x00,0x00,0x01,0x00},
	{0x00,0x01,0xC0,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00}};

	uint8_t jeden[8][8]=
	{{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00}};
	
	uint8_t dwa[8][8]=
	{{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00}};

	uint8_t trzy[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0xC0,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00}};

	uint8_t cztery[8][8]=
	{{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00}};

	uint8_t piec[8][8]=
	{{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00}};

	uint8_t szesc[8][8]=
	{{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00}};

	uint8_t siedem[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00}};

	uint8_t osiem[8][8]=
	{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00}};

	uint8_t dziewiec[8][8]=
	{{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
	{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00}};

	int czas=1;
	int petla = 7;
	if (data == '1') {

	for(int p=0;p<8;p++)
	{
		for(int i=0;i<8;i++)
		{
			for(int k=0;k<8;k++)
			{
				if(jeden[i][k] != 0x00) jeden[i][k]=1<<p;
			}
		}

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
	
	}}

	if (data == '2') {

	for(int p=0;p<8;p++)
	{
		for(int i=0;i<8;i++)
		{
			for(int k=0;k<8;k++)
			{
				if(dwa[i][k] != 0x00) dwa[i][k]=1<<p;
			}
		}

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
	
	}}

	if (data == '3') {

	for(int p=0;p<8;p++)
	{
		for(int i=0;i<8;i++)
		{
			for(int k=0;k<8;k++)
			{
				if(trzy[i][k] != 0x00) trzy[i][k]=1<<p;
			}
		}

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
	
	}}

}
