/*
 * File:   newmain.c
 * Author: renat
 *
 * Created on January 4, 2025, 6:39 PM
 */

#include <xc.h>
#include <string.h>
#include "PIC16FXXX.h"

#define _XTAL_FREQ 1000000      //define para utilizar fun��es de tempo
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

#define _CHIP PIC16F629
#define _XTAL_FREQ 10000000
#define _CHIP PIC16F628

// CONFIG
#pragma config FOSC = LP        // Oscillator Selection bits (LP oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

void usart_printf(const char msg[]){
    for (int i = 0; i< strlen(msg); i++)    {
        TXIF = 0;
        TXREG = msg[i];
        while(TXIF == 0);
    }
}



void main(void){
    PORTA = 0x00;
    TRISA = 0x1F;    
    PORTB = 0x00;
    TRISB = 0xDF;    
    CMCON = 0x07;
    
    TXSTAbits.TXEN = 1; //habilita transmissao
    TXSTAbits.BRGH = 1; //high speed
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1; //habilitar serial
    RCSTAbits.CREN = 1; //habilitar recepcao
    
    SPBRG = (int)(((_XTAL_FREQ/9600)/16)-1);
    char resposta = 0;
    
    while(1)//loop principal
    {
        usart_printf(".");
        
        if (RCIF)
        {
            resposta = RCREG;
            usart_printf("\n\r Caratere digitado: ");
            
            TXIF = 0;
            TXREG = resposta;
            while(TXIF == 0);
            RCIF = 0;
        }
        
        TRISBbits.TRISB5 = ~TRISBbits.TRISB5;   //inverte estado l�gico do pino do LED
        __delay_ms(1000);                         //aguarda 1 seg
    }
}