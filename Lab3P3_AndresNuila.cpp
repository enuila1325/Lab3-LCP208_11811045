#include <iostream>
#include <vector>
#include <array>
#include<algorithm>

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
    vector<Libro*>libros;
public:
    Catalogo();
    Catalogo(vector<Libro*>);
    vector<Libro*>getLibros();
    void setLibro(Libro*);
};
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
            string tituluLibro="", autorLibro="", anioPublicacion="";
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
                Libro* libroNuevo= new Libro(tituluLibro, autorLibro, anioPublicacion);
                for (int i = 0; i < listaBibliotecas.size(); i++)
                {
                    cout<<i<<"-->"<<listaBibliotecas.at(i).getNombre()<<endl;
                }
                cout<<"Seleccione a que biblioteca se pondra el libro"<<endl;
                cin>>indiceBiblioteca;
                cout<<"Ingrese el piso"<<endl;
                cin>>piso;
                cout<<"Ingrese el estante"<<endl;
                cin>>estante;
                cout<<"Ingrese la seccion"<<endl;
                cin>>seccion;

                listaBibliotecas.at(indiceBiblioteca).getDivisionBiblioteca()[piso][estante][seccion]->setLibro(libroNuevo);
            }
        }break;
        case 3:
        {
            string tituloABuscar;
            cout<<"Ingrese el titulo del libro que desea encontar";
            cin>>tituloABuscar;
            for (int i = 0; i < listaBibliotecas.size(); i++)
            {
                for (int j = 0; j < listaBibliotecas.at(i).getPisos(); j++)
                {
                    for (int k = 0; k < listaBibliotecas.at(i).getEstantes(); k++)
                    {
                        for (int l = 0; l < listaBibliotecas.at(i).getSecciones(); l++)
                        {
                            for (int m = 0; m < listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().size(); i++)
                            {
                                if (listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getTitulo()==tituloABuscar)
                                {
                                    cout<<"Titulo: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getTitulo()<<endl;
                                    cout<<"Autor: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getAutor()<<endl;
                                    cout<<"Anio: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getAnio()<<endl;
                                    cout<<"Biblioteca: "<<listaBibliotecas.at(i).getNombre()<<endl;
                                    cout<<"Ubicado en el piso "<<j<<" de la estanteria "<<k<<" de la seccion "<<l<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
        case 4:
        {
            string autorABuscar;
            cout<<"Ingrese el autor que desea encontar";
            cin>>autorABuscar;
            for (int i = 0; i < listaBibliotecas.size(); i++)
            {
                for (int j = 0; j < listaBibliotecas.at(i).getPisos(); j++)
                {
                    for (int k = 0; k < listaBibliotecas.at(i).getEstantes(); k++)
                    {
                        for (int l = 0; l < listaBibliotecas.at(i).getSecciones(); l++)
                        {
                            for (int m = 0; m < listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().size(); i++)
                            {
                                if (listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getAutor()==autorABuscar)
                                {
                                    cout<<"Titulo: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getTitulo()<<endl;
                                    cout<<"Autor: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getAutor()<<endl;
                                    cout<<"Anio: "<<listaBibliotecas.at(i).getDivisionBiblioteca()[j][k][l]->getLibros().at(m)->getAnio()<<endl;
                                    cout<<"Biblioteca: "<<listaBibliotecas.at(i).getNombre()<<endl;
                                    cout<<"Ubicado en el piso "<<j<<" de la estanteria "<<k<<" de la seccion "<<l<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
        case 5:
        {
            int indiceBiblioteca=0, pisoABUscar=0, estanteABuscar=0, seccionABuscar=0;
            vector<Libro*>librosEnSeccion;
            if (listaBibliotecas.size()==0)
            {
                cout<<"No hay bibliotecas en el sistema"<<endl;
            }
            else {
                for (int i = 0; i < listaBibliotecas.size(); i++)
                {
                    cout<<i<<"-->"<<listaBibliotecas.at(i).getNombre()<<endl;
                }
                cout<<"Seleccione a que biblioteca se pondra el libro"<<endl;
                cin>>indiceBiblioteca;
                cout<<"Ingrese el piso"<<endl;
                cin>>pisoABUscar;
                cout<<"Ingrese el estante"<<endl;
                cin>>estanteABuscar;
                cout<<"Ingrese la seccion"<<endl;
                cin>>seccionABuscar;
                for (int i = 0; i <
                    listaBibliotecas.at(indiceBiblioteca).getDivisionBiblioteca()[pisoABUscar][estanteABuscar][seccionABuscar]->getLibros().size(); i++)
                {
                    librosEnSeccion.push_back(
                        listaBibliotecas.at(indiceBiblioteca).getDivisionBiblioteca()[pisoABUscar][estanteABuscar][seccionABuscar]->getLibros().at(i));
                }
                Libro* tempo;
                for (int i = 0;i < librosEnSeccion.size(); i++) {//Bubble sort
                    for (int j = 0; j< librosEnSeccion.size()-1; j++) {
                        if (librosEnSeccion[j]->getTitulo() > librosEnSeccion[j+1]->getTitulo()) {
                            tempo = librosEnSeccion[j];
                            librosEnSeccion[j] = librosEnSeccion[j+1];
                            librosEnSeccion[j+1] = tempo;
                        }
                    }
                }
                for (int i = 0; i < librosEnSeccion.size(); i++)
                {
                    cout<<"Titulo: "<<librosEnSeccion.at(i)->getTitulo()<<endl;
                    cout<<"Autor: "<<librosEnSeccion.at(i)->getAutor()<<endl;
                    cout<<"Anio: "<<librosEnSeccion.at(i)->getAnio()<<endl;
                }
            }
            break;
        }
        default:
            break;
        }

    }
}