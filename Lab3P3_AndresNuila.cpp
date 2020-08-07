#include <iostream>
#include <vector>
#include <array>

using namespace std;

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
    Catalogo();
    Catalogo(vector<Libro>);
    vector<Libro>getLibros();
    void setLibro(Libro);
};
Catalogo::Catalogo() {
}
Catalogo::Catalogo(vector<Libro>_libros) {
    libros=_libros;
}
vector<Libro> Catalogo::getLibros() {
    return libros;
}
void Catalogo::setLibro(Libro l) {
    libros.push_back(l);
}


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



int main() {
    char resp = 's';
    int opcion=0;
    vector<Biblioteca>listaBibliotecas;
    while (resp == 's')
    {
        cout<<"1. CREAR BIBLIOTECA\n2. AGREGAR LIBRO\n3. BUSCA POR TITULO\n4. BUSCAR POR AUTOR\n5. EXPLORAR BIBLIOTECA\n0->SALIR\nSeleccione una opcion"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1: {
            string nombre, ubicacion;
            int pisos, estantes, secciones;
            cout<<"Ingrese el nombre de la nueva biblioteca: "<<endl;
            cin>>nombre;
            cout<<"Ingrese la ciudad de la nueva biblioteca: "<<endl;
            cin>>ubicacion;
            cout<<"Ingrese la cantidad de pisos "<<endl;
            cin>>pisos;
            cout<<"Ingrese la cantidad de estantes "<<endl;
            cin>>estantes;
            cout<<"Ingrese la cantidad de secciones "<<endl;
            cin>>secciones;
            Biblioteca _newBbiblioteca(nombre, ubicacion, pisos, estantes, secciones);
            listaBibliotecas.push_back(_newBbiblioteca);
        }break;
        case 2: {
            int indiceBiblioteca=0, piso=0, estante=0, seccion=0;
            string tituluLibro, autorLibro, anioPublicacion;
            if (listaBibliotecas.size()==0)
            {
                cout<<"No hay bibliotecas en el sistema"<<endl;
            }
            else {
                cout<<"Ingrese el titulo"<<endl;
                cin>>tituluLibro;
                cout<<"Ingrese el autor"<<endl;
                cin>>autorLibro;
                cout<<"Ingrese el anio"<<endl;
                cin>>anioPublicacion;
                Libro _newLibro(tituluLibro, autorLibro, anioPublicacion);
                for (int i = 0; i < listaBibliotecas.size(); i++)
                {
                    cout<<listaBibliotecas.at(i).getNombre()<<endl;
                }
                cout<<"Seleccione a que biblioteca añadira el libro"<<endl;
                cin>>indiceBiblioteca;
                cout<<"Ingrese el piso"<<endl;
                cin>>piso;
                cout<<"Ingrese el estante"<<endl;
                cin>>estante;
                cout<<"Ingrese la seccion"<<endl;
                cin>>seccion;
                for (int i = 0; i < listaBibliotecas.at(indiceBiblioteca).getPisos(); i++)
                {
                    for (int j = 0; j < listaBibliotecas.at(indiceBiblioteca).getEstantes(); j++)
                    {
                        for (int k = 0; i < listaBibliotecas.at(indiceBiblioteca).getPisos(); k++)
                        {
                            if (i==piso&&j==estante&&k==seccion)
                            {
                                listaBibliotecas.at(indiceBiblioteca).getDivisionBiblioteca();
                            }
                        }
                    }
                }
            }
        }break;
        default:
            break;
        }
    }

}