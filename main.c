#include <avr/io.h>
#include <util/delay.h>

void UART_Intialise()
{
	UCSRB |= (1<<TXEN)|(1<<RXEN)|(1<<RXCIE);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRH = 0;
	UBRRL = 51;
}

void UART_Tx_data(char ch)
{
	UDR = ch;
	while(!(UCSRA & (1<<UDRE)));
}

char UART_Rx_data()
{
	while(!(UCSRA & (1<<RXC)));
	return (UDR);
}

void UART_string(char *c)
{
	while(*c != '\0')
	UART_Tx_data(*c++);
}

int main()
{
	
		UART_Intialise();
		UART_string("GOVIND");
		UART_Tx_data(UDR);
		 
		while(1)
		{
			char Rx_data = UART_Rx_data();
			UART_Tx_data(Rx_data);
			
	}
}