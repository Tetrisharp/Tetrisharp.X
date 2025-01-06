/*
 * Project:   newmain.c
 * Author: Renato Lobo
 *
 * Created on January 4, 2025, 6:39 PM
 */

#include <xc.h>
#include "PIC16F628A.h"
#include "PlayField.h"

static Tetramino piece;

void usart_print_piece();
void render();
void DrawThePiece();

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

////////////////////////////////////////////////////////////////////////////////////////////////

void usart_print_piece()
{
    for (int i = 0; i < 4; i++)
    {
        usart_print_char('(');
        usart_print_int(piece.blocks[i].XPosition);
        usart_print_char(',');
        usart_print_int(piece.blocks[i].YPosition);
        usart_print_char(')');
    }       
    usart_printf("\r\n");
}

void render()
{
    //usart_print_int(1);
    usart_print_piece();
    usart_printf("\tlines:500\r\n");
    
    usart_printf("|----------------------|\r\n");
    
    for (int y = 0; y < 20; y++)
    {
        usart_printf("| ");//        
        int varredura = 512;
        
        for (int x = 0; x <10; x++)
        {
            int b = field_blocks[y] & varredura;
            varredura>>=1;

            if ( ((piece.blocks[0].XPosition == x) && (piece.blocks[0].YPosition == y))
               ||((piece.blocks[1].XPosition == x) && (piece.blocks[1].YPosition == y))
               ||((piece.blocks[2].XPosition == x) && (piece.blocks[2].YPosition == y))
               ||((piece.blocks[3].XPosition == x) && (piece.blocks[3].YPosition == y)))
            {
                usart_printf("()");
            }
            else
            {
                if (b==0) usart_printf("  ");
                else usart_printf("()");
            }            

        }
        
        usart_printf(" |\r\n");
    }
    usart_printf("|______________________|\r\n");
}

void DrawThePiece()
{
    srand(time(NULL));
    int x = (int)(rand()) % 7;
    Block block1;    
    Block block2; 
    Block block3;    
    Block block4;
    
    switch(x) {
        case 0:
            piece.color = 2; //  |_|_|_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;    
            break;
        case 1:              //    |_|
            piece.color = 1; //  |_|_|_|             
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;   
            break;
        case 2:              //    |_|_|
            piece.color = 1; //    |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;    
            break;
        case 3:              //  |_|
            piece.color = 1; //  |_|_|_|            
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;        
            break;
        case 4:              //      |_|    
            piece.color = 1; //  |_|_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;   
            break;
        case 5:              //  |_|_|
            piece.color = 1; //    |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;       
            break;
        case 6:              //    |_|_|
            piece.color = 1; //  |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;      
            break;
        default:            
            break;
    }
    
    piece.blocks[0]= block1;
    piece.blocks[1]= block2;
    piece.blocks[2]= block3;            
    piece.blocks[3]= block4;
}
