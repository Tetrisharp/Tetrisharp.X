
#include "PIC16F84A.h"

const double RAIO = 2.5;
const double LARGURA = 1.2;

const double MEU_PI = 3.14;

double perimetro_retangulo(Retangulo r)
{
    return 2*(r.comprimento + r.largura);
}

double area_retangulo(Retangulo r)
{
    return r.comprimento * r.largura;
}

double perimetro_circulo(Circulo c)
{
    return c.raio * 2.0 * MEU_PI;
}

double area_circulo(Circulo c)
{
    return c.raio * c.raio * MEU_PI;
}