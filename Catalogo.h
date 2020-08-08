#include <iostream>
#include <vector>
#include"Libro.h"

using namespace std;

#ifndef Catalogo_H
#define Catalogo_H

class Catalogo {
private:
    vector<Libro*>libros;
public:
    Catalogo();
    Catalogo(vector<Libro*>);
    vector<Libro*>getLibros();
    void setLibro(Libro*);
    ~Catalogo();
};

#endif