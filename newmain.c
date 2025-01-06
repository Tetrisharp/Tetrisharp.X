/*
 * Project:   newmain.c
 * Author: Renato Lobo
 *
 * Created on January 4, 2025, 6:39 PM
 */

#include <xc.h>
#include "PIC16F628A.h"
#include "PlayField.h"



void main(void)
{
    init_chip();
    
    do //
    {
        //have_colision = 0;
        DrawThePiece();
        __delay_ms(1);
        //do
        //{
            //__delay_ms(1000);
        //}while(1);;
        
        render();
        
    }while(1);
    
    /*char resposta = 0;    
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
    }*/
}