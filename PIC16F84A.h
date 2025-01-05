//fonte: https://www.youtube.com/watch?v=XMyU-Gz51T8
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIC16F84A_H
#define	PIC16F84A_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define PI 3.14
extern const double RAIO;
extern const double LARGURA;

typedef struct {
    double largura, comprimento;    
} Retangulo;

typedef struct {
    double raio;    
} Circulo;

double perimetro_retangulo(Retangulo);
double area_retangulo(Retangulo);
double perimetro_circulo(Circulo);
double area_circulo(Circulo);


// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

