#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#define F_CPU 8000000UL
#define OCIE2   7

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


void system_inti(void);
void timer2_inti(void);
void timer2_Enable(void);
void timer2_disable(void);
void Ext_Int_0_1_2_Init(void);
void push_to_encoder(void);
void push_to_zero(void);


#endif /* STOPWATCH_H_ */