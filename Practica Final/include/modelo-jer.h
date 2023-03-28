// Nombre: César, Apellidos: Muñoz Reinoso, DNI/pasaporte: 32090924J (DDGG IG curso 20-21)

#ifndef MODELO_JER_H
#define MODELO_JER_H

#include "grafo-escena.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "objeto3d.h"

class Construccion : public NodoGrafoEscena
{
public:
    Construccion();

private:
    Matriz4f* trasladarFlexo = nullptr;		
    Matriz4f* trasladarLuz = nullptr;	
    Matriz4f* trasladarPatas= nullptr;
    Matriz4f* rotacionFlexo = nullptr;
    Matriz4f* rotacionPatas = nullptr;


protected:
    void actualizarEstadoParametro(const unsigned iParam, const float t_sec);
    unsigned leerNumParametros() const;
};


class Base : public NodoGrafoEscena
{
    public:
        Base();
};

class Pata : public NodoGrafoEscena
{
    public:
        Pata(float lon);
};

class EstructuraInf : public NodoGrafoEscena
{
public:
    EstructuraInf();
};

class EstructuraSup : public NodoGrafoEscena
{
public:
    EstructuraSup();
    Matriz4f* trPatas = nullptr;

};

class Carcasa : public NodoGrafoEscena
{
    public:
        Carcasa();
        Matriz4f* trLuz = nullptr;
};

class Flexo : public NodoGrafoEscena
{
    public:
        Flexo();
        Matriz4f* trFlexo = nullptr;
        Matriz4f* rtFlexo = nullptr;
        Matriz4f* trLuz = nullptr;
        Matriz4f* trPatas = nullptr;
};
#endif // MODELO_JER_H
