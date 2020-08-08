#include <iostream>
using namespace std;

#ifndef Libro_H
#define Libro_H

class Libro {
private:
    string titulo, autor, anio;
public:
    Libro(string, string, string);
    string getTitulo();
    string getAutor();
    string getAnio();
    void setTitulo(string _titulo);
    void setAutor(string _autor);
    void setAnio(string _anio);
    ~Libro();
};

#endif