#include "StopWatch.h"

volatile unsigned int counter =0;
volatile unsigned int time_sec = 0;
volatile unsigned char _1s=0;
volatile unsigned char _10s=0;
volatile unsigned char _100s=0;


int main(void)
{
	system_inti();
	push_to_zero();
	while(1);
}
void system_inti(void)
{
	DDRA |= 0xEF;
	PORTA = 0x00;
	DDRC |= 0x07;
	timer2_inti();
	Ext_Int_0_1_2_Init();
	sei();
}
void push_to_encoder(void)
{
	PORTA = _1s;
	PORTC |= 0x01;
	PORTC &= ~(1<<0);
	
	PORTA = _10s;
	PORTC |= 0x02;
	PORTC &= ~(1<<1);
	
	PORTA = _100s;
	PORTC |= 0x04;
	PORTC &= ~(1<<2);
}
void push_to_zero(void)
{
	PORTA = 0;
	PORTC |= 0x01;
	PORTC &= ~(1<<0);
	
	PORTA = 0;
	PORTC |= 0x02;
	PORTC &= ~(1<<1);
	
	PORTA = 0;
	PORTC |= 0x04;
	PORTC &= ~(1<<2);
}
void timer2_inti(void)
{
	OCR2 = 124;            // to get delay 1ms
	TCCR2 =0x0C;           // N=64, CTC mode , OC2 disconnected
}
void timer2_Enable(void)
{
	TCNT2 = 0;             // start from zero
	TIMSK |= (1<<OCIE2);   // Disable compare match interrupt
}
void timer2_disable(void)
{
	TIMSK &= ~(1<<OCIE2);   // Disable compare match interrupt
	TCNT2 = 0;              // start from zero
}
ISR(TIMER2_COMP_vect)
{
	time_sec ++;
	if(time_sec==100)
	{
		_1s   =   counter%10;
		_10s  =  (counter%100)/10;
		_100s = ((counter%1000)/100);
		push_to_encoder();
		counter ++;
		counter %= 1000;
	}
	time_sec %= 100;
}
void Ext_Int_0_1_2_Init(void)
{
	//ext int 0
	MCUCR |= (1<<1);  // sense falling edge
	MCUCR &= ~(1<<0); // sense falling edge
	GICR |= (1<<6);
	PORTD |= (1<<2);  // pull-up resistor
	//ext int 1
	MCUCR |= (1<<3);  // sense falling edge
	MCUCR &= ~(1<<2); // sense falling edge
	GICR |= (1<<7);
	PORTD |= (1<<3);  // pull-up resistor
	//ext int 2
	MCUCSR &= ~(1<<6); // sense falling edge
	GICR |= (1<<5);
	PORTB |= (1<<2);  // pull-up resistor
}
ISR(INT0_vect)
{
	counter = 0;
	timer2_disable();
	push_to_zero();
	PORTA ^= (1<<7);
}
ISR(INT1_vect)
{
	timer2_Enable();
	PORTA ^= (1<<6);
}
ISR(INT2_vect)
{
	timer2_disable();
	PORTA ^= (1<<5);
}