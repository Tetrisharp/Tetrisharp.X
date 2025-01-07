#ifndef PLAYFIELD_H
#define	PLAYFIELD_H

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

#include <stdlib.h>
#include <time.h>  

extern const double EXEMPLO;
extern int field_blocks[FIELD_HEIGHT];  

typedef struct {
    int XPosition, YPosition;    
} Block;

typedef struct {
    Block blocks[4];
    int color;
} Tetramino;

//void DrawThePiece();

//void weldTheBlocks(Tetramino);
//void RemoveLine(int);
//void FallingDown(int);

//bool OverFlow();
//bool HaveEdgesOnRight(Tetramino);
//bool HaveEdgesOnLeft(Tetramino);
//bool CantSpin(Tetramino);
//bool PredicColision(Tetramino);
//bool IsLineComplete(int);
//char[] ToString();


//double perimetro_retangulo(Retangulo);
//double area_retangulo(Retangulo);
//double perimetro_circulo(Circulo);
//double area_circulo(Circulo);


#endif

