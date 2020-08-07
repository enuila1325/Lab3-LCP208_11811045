#include <iostream>
#include <vector>

using namespace std;

class Biblioteca {
private:
    string nombre, ubicacion;
public:
    Biblioteca(string, string);
    string getNombre();
    string getUbicacion();
    void setNombre(string);
    void setUbicacion(string);
};
Biblioteca::Biblioteca(string _nombre, string _ubicacion) {
    nombre = _nombre;
    ubicacion = _ubicacion;
}
string Biblioteca::getNombre() {
    return nombre;
}
string Biblioteca::getUbicacion() {
    return ubicacion;
}
void Biblioteca::setNombre(string _newNombre) {
    nombre=_newNombre;
}
void Biblioteca::setUbicacion(string _newUbicacion) {
    ubicacion = _newUbicacion;
}

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
};

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

class Catalogo {
private:
    vector<Libro>libros;
public:
    Catalogo(vector<Libro>);
    vector<Libro>getLibros();
    void setLibro(Libro);
};
Catalogo::Catalogo(vector<Libro>_libros) {
    libros=_libros;
}
vector<Libro> Catalogo::getLibros() {
    return libros;
}
void Catalogo::setLibro(Libro l) {
    libros.push_back(l);
}
int main() {

}