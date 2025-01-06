#include "PlayField.h"

const double EXEMPLO = 3.14;
int field_blocks[FIELD_HEIGHT] =  {0,0,0,0,0,0,0,16,24,8,0,0,0,0,0,0,0,0,0,0};

//void weldTheBlocks(Tetramino t)
//{
    //for(int i=0;i<4;i++)
    //{
        
    //}
    
    //return t.blocks[];
//}


//double perimetro_retangulo(Retangulo r)
//{
//    return 2*(r.comprimento + r.largura);
//}

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
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;    
            break;
        case 1:              //    |_|
            piece.color = 1; //  |_|_|_|             
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;    
            break;
        case 2:              //    |_|_|
            piece.color = 1; //    |_|_|             
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;    
            break;
        case 3:              //  |_|
            piece.color = 1; //  |_|_|_|          
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;            
            break;
        case 4:              //      |_|    
            piece.color = 1; //  |_|_|_|            
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;    
            break;
        case 5:              //  |_|_|
            piece.color = 1; //    |_|_|            
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;     
            break;
        case 6:              //    |_|_|
            piece.color = 1; //  |_|_|           
            block1.XPosition = 5; block1.YPosition = 0;
            block2.XPosition = 5; block2.YPosition = 0;
            block3.XPosition = 5; block3.YPosition = 0;
            block4.XPosition = 5; block4.YPosition = 0;      
            break;
        default:            
            break;
    }
    
    piece.blocks[0]= block1;
    piece.blocks[1]= block2;
    piece.blocks[2]= block3;            
    piece.blocks[3]= block4;
}