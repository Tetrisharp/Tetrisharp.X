#include "PIC16F628A.h"
#include "PlayField.h"
#include <string.h>



void usart_printf(const char msg[])
{
    for (int i = 0; i< strlen(msg); i++)
    {
        TXIF = 0;
        TXREG = msg[i];
        while(TXIF == 0);
    }
}

void render()
{
    usart_printf("\tlines:500\r\n");
    usart_printf("|----------------------|\r\n");
    
    for (int y = 0; y < 20; y++)
    {
        usart_printf("| ");//
        
        for (int x = 512; x > 0; x>>=1)
        {
            int b = field_blocks[y]&x;

            if (b==0)
            {
                usart_printf("  ");
            }
            else
            {
                usart_printf("()");
            }
        }
        
        usart_printf(" |\r\n");
    }
    usart_printf("|______________________|\r\n");
}

void init_chip()
{
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
}