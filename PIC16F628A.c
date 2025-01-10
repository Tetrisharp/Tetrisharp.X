#include "PIC16F628A.h"
#include "PlayField.h"
#include <string.h>

void usart_print_char(const char msg)
{
    TXIF = 0;
    TXREG = msg;
    while(TXIF == 0);
}

void usart_printf(const char msg[])
{
    for (int i = 0; i< strlen(msg); i++)
    {
        usart_print_char(msg[i]);
    }
}

void usart_print_int(int num)
{
    usart_print_char(num+48);
}



void init_chip()
{
    PORTA = 0x00;
    TRISA = 0x1F;    
    PORTB = 0x0F;
    TRISB = 0xDF;    
    CMCON = 0x07;
    
    OPTION_REGbits.nRBPU = 0; // Habilita resistores de pull-up
    
    TXSTAbits.TXEN = 1; //habilita transmissao
    TXSTAbits.BRGH = 1; //high speed
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1; //habilitar serial
    RCSTAbits.CREN = 1; //habilitar recepcao
    
    SPBRG = (int)(((_XTAL_FREQ/9600)/16)-1);
}