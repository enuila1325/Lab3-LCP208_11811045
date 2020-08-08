#include <iostream>
#include "Catalogo.h"

Catalogo::Catalogo() {
}
Catalogo::Catalogo(vector<Libro*>_libros) {
    libros =_libros;
}
vector<Libro*> Catalogo::getLibros() {
    return libros;
}
void Catalogo::setLibro(Libro* l) {
    libros.push_back(l);
}
