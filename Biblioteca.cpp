#include <iostream>
#include "Biblioteca.h"

Biblioteca::Biblioteca(string _nombre, string _ubicacion, int _pisos, int _estantes, int _secciones) {
    nombre = _nombre;
    ubicacion = _ubicacion;
    pisos=_pisos;
    secciones=_secciones;
    estantes=_estantes;
    divisionBiblioteca = new Catalogo***[_pisos];
    for (int i = 0; i < _pisos; i++)
    {
        divisionBiblioteca[i] = new Catalogo**[_estantes];
        for (int j = 0; j < _estantes; j++)
        {
            divisionBiblioteca[i][j] = new Catalogo*[_secciones];
            for (int k = 0; k < _secciones; k++)
            {
                divisionBiblioteca[i][j][k] = new Catalogo();
            }

        }

    }
}
string Biblioteca::getNombre() {
    return nombre;
}
string Biblioteca::getUbicacion() {
    return ubicacion;
}
int Biblioteca::getPisos() {
    return pisos;
}
int Biblioteca::getEstantes() {
    return estantes;
}
Catalogo**** Biblioteca::getDivisionBiblioteca() {
    return divisionBiblioteca;
}
int Biblioteca::getSecciones() {
    return secciones;
}
void Biblioteca::setNombre(string _newNombre) {
    nombre=_newNombre;
}
void Biblioteca::setUbicacion(string _newUbicacion) {
    ubicacion = _newUbicacion;
}
Biblioteca::~Biblioteca(){

}
