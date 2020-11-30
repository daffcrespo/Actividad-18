#include "civilizacion.h"
#include "aldeano.h"
#include <fstream>
#include <algorithm>
#include <fstream>
#include <algorithm>
/*
Civilizacion::Civilizacion()
{

}*/

Civilizacion::Civilizacion(const string &nombre,
                float ubiX,
                float ubiY,
                int puntuacion)
{
    this->nombre = nombre;
    this->ubiX = ubiX;
    this->ubiY = ubiY;
    this->puntuacion = puntuacion;
}
bool Civilizacion::empty()
{
    return aldeanos.empty();
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setubiX(float v)
{
    ubiX = v;
}

float Civilizacion::getubiX()
{
    return ubiX;
}

void Civilizacion::setubiY(float v)
{
    ubiY = v;
}

float Civilizacion::getubiY()
{
    return ubiY;
}

void Civilizacion::setpuntuacion(int v)
{
    v = v+(aldeanos.size()*100);
    puntuacion = v;
}

void Civilizacion::setPunt2(int v, const Aldeano &a)
{
    //v = v+(aldeanos.size()*100);
    puntuacion = v;
}

int Civilizacion::getpuntuacion()
{
    return puntuacion = puntuacion+(aldeanos.size()*100);
}
/*
Aldeano& Civilizacion::getAldeano(int pos)
{
    return aldeanos[pos];
}*/


void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(10) << "Genero";
    cout << setw(8) << "Salud";
    cout << setw(3) << "Edad";
    cout << endl;
    cout << "-----------------------------------------" << endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
    cout << endl;
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() <= salud;});
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscarA(const Aldeano &a)
{
    // vector<Civilizacion>::iterator
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if (it == aldeanos.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

