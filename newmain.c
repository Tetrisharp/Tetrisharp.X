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
static int have_colision;

void usart_print_piece();
void render();
void gravity();
void WeldTheBlocks();
void verify_full_lines();
int OverFlow();
void DrawThePiece();
void AguardaTeclas();
void moveDown();
void moveLeft();
void moveRight();
void Rotate();

void main(void)
{
    srand(time(NULL)); //semente do random
    init_chip();
    
    do
    {
        have_colision = 0;
        DrawThePiece();
        do
        {
            render();
            gravity();
            int timeout=0;
            do{
                AguardaTeclas();
                __delay_ms(200);
                timeout++;
            }while(timeout==5);
            
            
            
        }while(!have_colision);;
        
        verify_full_lines();
        
    }while(!OverFlow());
    usart_printf("=========== GAME  OVER ===========\r\n");
    while(1);
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

void verify_full_lines()
{
    for (int y = 0; y < 20; y++)
    {
        if (field_blocks[y] == 1023)
        {
            for (int f = y; f >= 0; f--)
            {
                if(f==0) field_blocks[f] = 0;
                else field_blocks[f] = field_blocks[f-1];
            }
        }        
    }    
}

int OverFlow()
{
    return (field_blocks[0] & 1023);
}

void WeldTheBlocks(){
    for (int i=0;i<4;i++) //para cada bloco
    {
        int posicaoY = piece.blocks[i].YPosition;
        int posicaoX = 512 >> piece.blocks[i].XPosition;
        
        field_blocks[posicaoY] |= posicaoX;        
    }
}

void gravity()
{
    for (int i=0;i<4;i++) //para cada bloco
    {
        int novaPosicaoY = piece.blocks[i].YPosition + 1;
        int posicaoX = 512 >> piece.blocks[i].XPosition;
        
        if (novaPosicaoY>=20) have_colision = 1;
        if ((field_blocks[novaPosicaoY] & posicaoX)!= 0) have_colision = 1;
    }
    
    if (have_colision)
    {
        WeldTheBlocks();
        //beep;
    }
    else
    {
        for (int i=0;i<4;i++) piece.blocks[i].YPosition++;
    }    
}

void render()
{
    //usart_print_int(1);
    //usart_print_piece();
    usart_printf("\t     lines:");
    usart_print_int(5);
    usart_print_int(0);
    usart_print_int(0);
    usart_printf("\r\n");
    
    usart_printf("|--------------------------------|\r\n");
    
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
                usart_print_char('(');
                usart_print_int(piece.color);
                usart_print_char(')');
            }
            else
            {
                if (b==0) usart_printf("   ");
                else usart_printf("(0)");
            }            

        }
        
        usart_printf(" |\r\n");
    }
    usart_printf("|________________________________|\r\n");
}

void DrawThePiece()
{    
    Block block1;    
    Block block2; 
    Block block3;    
    Block block4;
        
    int teste = rand();
    int TESTE2 = teste % 7;
    int x = (int)(rand()) % 7;
    
    switch(x) {
        case 0:
            piece.color = 1; //  |_|_|_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;    
            break;
        case 1:              //    |_|
            piece.color = 2; //  |_|_|_|             
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;   
            break;
        case 2:              //    |_|_|
            piece.color = 3; //    |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;    
            break;
        case 3:              //  |_|
            piece.color = 4; //  |_|_|_|            
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;        
            break;
        case 4:              //      |_|    
            piece.color = 5; //  |_|_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;   
            break;
        case 5:              //  |_|_|
            piece.color = 6; //    |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 1;
            block3.XPosition = 5; block3.YPosition = 2;
            block4.XPosition = 5; block4.YPosition = 3;       
            break;
        case 6:              //    |_|_|
            piece.color = 7; //  |_|_|           
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

void AguardaTeclas()
{
    if (PORTBbits.RB0 == 1) ;//gravity();
    if (PORTBbits.RB1 == 1) moveLeft();
    if (PORTBbits.RB2 == 1) moveRight();    
    if (PORTBbits.RB3 == 1) Rotate();  
}

void moveLeft()
{
    for (int i=0;i<4;i++)
    {
        int posX = 1024 >> piece.blocks[i].XPosition;
        posX <<= 1;
        
        int wall = posX & field_blocks[piece.blocks[i].YPosition];
        
        if ((posX>=2048)||(wall==posX))
        {            
            //beep();)
        }
        else piece.blocks[i].XPosition--;
    }    
}    

void moveRight()
{
    for (int i=0;i<4;i++)
    {
        int posX = 1024 >> piece.blocks[i].XPosition;
        posX >>= 1;
        
        int wall = posX & field_blocks[piece.blocks[i].YPosition];
        
        if ((posX<=1)||(wall==posX))
        {            
            //beep();        
        }
        else piece.blocks[i].XPosition++;
    }
}

void Rotate()
{
    int minX = 99; 
    int minY = 99;
    int maxX = -1; 
    int maxY = -1;

    for (int i=0;i<4;i++)
    {
        if ( minY > piece.blocks[i].YPosition) minY = piece.blocks[i].YPosition;
        if ( maxY < piece.blocks[i].YPosition) maxY = piece.blocks[i].YPosition;

        if ( minX > piece.blocks[i].XPosition) minX = piece.blocks[i].XPosition;
        if ( maxX < piece.blocks[i].XPosition) maxX = piece.blocks[i].XPosition;        
    }

    int axisX = (maxX + minX) / 2;
    int axisY = (maxY + minY) / 2;

    for (int i=0;i<4;i++)
    {
        int oldX = piece.blocks[i].XPosition;
        int oldY = piece.blocks[i].YPosition;

        piece.blocks[i].XPosition = (axisX - axisY + oldY);
        piece.blocks[i].YPosition = (axisX + axisY - oldX);
    }
}
