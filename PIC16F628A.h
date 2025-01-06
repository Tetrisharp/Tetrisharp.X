//fonte: https://www.youtube.com/watch?v=XMyU-Gz51T8
// This is a guard condition so that contents of this file are not included
// more than once.  

#ifndef PIC16F628A_H
#define	PIC16F628A_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define _XTAL_FREQ 1000000      //define para utilizar fun��es de tempo
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

// CONFIG
#pragma config FOSC = LP        // Oscillator Selection bits (LP oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

void usart_print_char(const char);
void usart_printf(const char[]);
void usart_print_piece();
void usart_print_int(int);
void init_chip();

//void render();

#endif	

