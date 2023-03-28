// Nombre: César, Apellidos: Muñoz Reinoso, DNI/pasaporte: 32090924J (DDGG IG curso 20-21)

// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"
#include <cmath>

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   // COMPLETAR: Práctica 2: completar: creación de la malla....
	vertices.clear();
	float angulo = 2 * M_PI;

	for (unsigned int i = 0; i < num_copias; i++) {
		for (int j = 0; j < perfil.size(); j++) {
			vertices.push_back(Tupla3f(perfil[j](0) * cos((angulo * i) / (num_copias - 1)) + sin((angulo * i) / (num_copias - 1)) * perfil[j](2),
												perfil[j](1),
												-sin((angulo * i) / (num_copias - 1)) * perfil[j](0) + cos((angulo * i) / (num_copias - 1)) * perfil[j](2)
												));
		
		}
	}

	triangulos.clear();

	for (unsigned int i = 0; i < num_copias - 1; i++) {
		for (int j = 0; j < perfil.size() - 1; j++) {
			triangulos.push_back(Tupla3i(i * perfil.size() + j,
											i * perfil.size() + j + perfil.size(), 
											i * perfil.size() + j + perfil.size() + 1));
			triangulos.push_back(Tupla3i(i * perfil.size() + j,
											i * perfil.size() + j + perfil.size() + 1,
											i * perfil.size() + j + 1));
		}
	}

}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   std::vector<Tupla3f> perfil;

   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   // ...........................
   LeerVerticesPLY(nombre_arch, perfil);
   inicializar(perfil, nperfiles);

}

Cilindro::Cilindro
(
	const int num_verts_per,
	const unsigned nperfiles
)
{
	assert(num_verts_per >= 4);
	std::vector<Tupla3f> perfil;
	
	perfil.push_back({ 0.0, 0.0, 0.0 }); 
	
	for (float i = 0; i <= 1; i += (1.0 / (num_verts_per - 3))) { 
		perfil.push_back({ 1.0, i, 0.0 });
	}
	
	perfil.push_back({ 0.0, 1.0, 0.0 });

	inicializar(perfil, nperfiles);
}

Cono::Cono
(
	const int num_verts_per,
	const unsigned nperfiles
)
{
	assert(num_verts_per >= 3);
	std::vector<Tupla3f> perfil;

	for (float i = 0; i < 1; i += (1.0 / (num_verts_per - 1))) {
		perfil.push_back({ (float)1.0 - i, i, 0.0 });
	}
	perfil.push_back({ 0.0, 1.0, 0.0 });

	inicializar(perfil, nperfiles);
}

Esfera::Esfera
(
	const int num_verts_per,
	const unsigned nperfiles
)
{
	assert(num_verts_per >= 3);
	std::vector<Tupla3f> perfil;

	float angulo = M_PI / (num_verts_per - 1);

	for (float i = 0; i < num_verts_per; i ++) {
		perfil.push_back({ -sin(angulo * i), cos(angulo * i), 0.0 });
	}

	inicializar(perfil, nperfiles);
}

MediaEsfera::MediaEsfera
(
	const int num_verts_per,
	const unsigned nperfiles
)
{
	assert(num_verts_per >= 2);
	std::vector<Tupla3f> perfil;

	float angulo = M_PI / (2*(num_verts_per - 1));
	
	for (float i = 0; i <= num_verts_per - 1; i++) {
		perfil.push_back({ -sin(angulo * i),cos(angulo * i), 0.0 });
	}
	
	inicializar(perfil, nperfiles);
}