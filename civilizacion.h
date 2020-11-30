#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include "aldeano.h"

#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Civilizacion 
{
    string nombre;
    float ubiX;
    float ubiY; 
    int puntuacion;
    list<Aldeano> aldeanos;
    
public:
    Civilizacion(){}
    Civilizacion(const string &nombre,
                float ubiX,
                float ubiY,
                int puntuacion);
    void setNombre(const string &c);
    string getNombre();
    void setubiX(float c);
    float getubiX();
    void setubiY(float c);
    float getubiY();
    void setpuntuacion(int c);
    void setPunt2(int c, const Aldeano &a);
    int getpuntuacion();
    bool empty();
    Aldeano& getAldeano(int pos);
    int pos();


    ///nuevos
    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);
    void print();

    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t salud);
    void eliminarEdad();

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscarA(const Aldeano &a);


    

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left ;
        out << setw(10) << c.nombre;
        out << setw(15) << c.ubiX ;
        out << setw(15) << c.ubiY;
        out << setw(10) << c.puntuacion;
        out << endl;

        return out;
    }
    friend istream& operator>>(istream &in, Civilizacion &c)
    {

        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion X: ";
        cin >> c.ubiX;
        cout << "Ubicacion Y: ";
        cin >> c.ubiY;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c)
    {
        return 2;
    }
    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
};

#endif