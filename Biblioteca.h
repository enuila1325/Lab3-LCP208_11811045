#include <iostream>
#include "Catalogo.h"

#ifndef Biblioteca_H
#define Biblioteca_H

class Biblioteca {
private:
    string nombre, ubicacion;
    Catalogo**** divisionBiblioteca;
    int pisos, secciones, estantes;

public:
    Biblioteca(string, string, int, int, int);
    string getNombre();
    string getUbicacion();
    int getPisos();
    int getEstantes();
    int getSecciones();
    void setNombre(string);
    void setUbicacion(string);
    Catalogo**** getDivisionBiblioteca();
};

#endif