// Nombre: César, Apellidos: Muñoz Reinoso, DNI/pasaporte: 32090924J (DDGG IG curso 20-21)

#include "ig-aux.h"
#include "matrices-tr.h"
#include "grafo-escena.h"
#include "modelo-jer.h"

Construccion::Construccion() {
    ponerNombre("Flexo");

    auto flexo = new Flexo;
    agregar(flexo);

    trasladarFlexo = flexo -> trFlexo;
    rotacionFlexo = flexo -> rtFlexo;
    trasladarLuz = flexo -> trLuz;
    trasladarPatas = flexo -> trPatas;

}

unsigned Construccion::leerNumParametros() const {
    return 4;
}

void Construccion::actualizarEstadoParametro(const unsigned iParam, const float t_sec) {
    assert(iParam < leerNumParametros());
    switch (iParam) {
    case 0:
        * trasladarFlexo = MAT_Traslacion(0.0, 0.0 , 10*sin(2 * M_PI * t_sec * 0.1));
        break;
    case 1:
        *trasladarLuz = MAT_Traslacion(0.0, -3 / 2 + 3 / 2 * sin(2 * M_PI * t_sec * 0.1),0.0);
        break;
    case 2:
        * rotacionFlexo = MAT_Rotacion(10 * t_sec, 0.0, 1.0, 0.0);
        break;
    case 3:
        *trasladarPatas = MAT_Traslacion(0.0, -3 / 2 + 3 / 2 * sin(2 * M_PI * t_sec * 0.1), 0.0);
        break;
    default:
        break;
    }
}

Base::Base()
{
    agregar(MAT_Escalado(1.5, 0.5, 1.5));
    auto cilindro = new Cilindro(10, 100);
    cilindro->ponerColor({ 1.0, 0.0, 0.0 });
    agregar(cilindro);
}

Pata::Pata(float lon) 
{
    agregar(MAT_Escalado(0.1, lon, 0.1));
    auto pata = new Cilindro(10, 100);
    pata->ponerColor({ 0.0,0.0,0.0 });
    agregar(pata);
}

EstructuraInf::EstructuraInf()
{
    agregar(MAT_Traslacion(0.2, 0.4, 0.2));
    agregar(MAT_Rotacion(-30.0, 0.0, 0.0, 1.0));
    auto pata1 = new Pata(4.0);
    agregar(pata1);

    agregar(MAT_Traslacion(0.0, 0.0, -0.4));
    auto pata2 = new Pata(4.0);
    agregar(pata2);
}

EstructuraSup::EstructuraSup()
{
    int indice = agregar(MAT_Traslacion(0.0, 0.0, 0.0));
    trPatas = leerPtrMatriz(indice);

    agregar(MAT_Traslacion(2.2, 3.6, 0.0));
    agregar(MAT_Rotacion(45.0, 0.0, 0.0, 1.0));
    auto pata3 = new Pata(2.5);
    agregar(pata3);
}
Carcasa::Carcasa() {

    int indice = agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
    trLuz = leerPtrMatriz(indice);

    agregar(MAT_Traslacion(-0.4, 5.5, 0.0));
    agregar(MAT_Rotacion(-15.0, 0.0, 0.0, 1.0));
    auto carcasa = new MediaEsfera(10, 100);
    carcasa->ponerColor({ 1.0, 0.0, 0.5 });
    agregar(carcasa);
}

Flexo::Flexo() {

    int indice1 = agregar(MAT_Traslacion(0.0, 0.0, 0.0));
    trFlexo = leerPtrMatriz(indice1);

    int indice2 = agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));
    rtFlexo = leerPtrMatriz(indice2);

    auto base = new Base();
    agregar(base);

    auto estructinf = new EstructuraInf();
    agregar(estructinf);

    auto estructsup = new EstructuraSup();
    agregar(estructsup);

    auto carcasa = new Carcasa;
    agregar(carcasa);

    trLuz = carcasa->trLuz;
    trPatas = estructsup->trPatas;
}