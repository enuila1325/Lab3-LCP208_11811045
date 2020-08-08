#include <iostream>
#include "Libro.h"

Libro::Libro(string _titulo, string _autor, string _anio) {
    titulo = _titulo;
    autor = _autor;
    anio = _anio;
}
string Libro::getTitulo() {
    return titulo;
}
string Libro::getAutor() {
    return autor;
}
string Libro::getAnio() {
    return anio;
}