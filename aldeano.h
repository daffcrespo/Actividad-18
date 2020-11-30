#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Aldeano
{
private:
    string nombre;
    string genero;
    size_t salud;
    size_t edad;

public:
    Aldeano() {}
    Aldeano(const string &nombre, const string &genero, size_t salud,  size_t edad = 0)
    : nombre(nombre), genero(genero), salud(salud), edad(edad) {}

    void setNombre(const string &nombre);
    string getNombre() const;

    void setGenero(const string &genero);
    string getGenero() const;

    void setSalud(size_t salud);
    size_t getSalud() const;

    void setEdad(size_t edad);
    size_t getEdad() const;


    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(10) << a.nombre;
        out << setw(10) << a.genero;
        out << setw(8) << a.salud;
        out << setw(3) << a.edad;

        return out;
    }
    
    bool operator<(const Aldeano &a) const
    {
        return nombre < a.getNombre();
    }

    bool operator==(const Aldeano& a)
    {
        return nombre == a.nombre;
    }
    bool operator==(const Aldeano& a) const
    {
        return nombre == a.nombre;
    }
/*
    bool operator<(const Aldeano& a)
    {
        return 2;
    }
    bool operator<(const Aldeano& a) const
    {
        return nombre < a.nombre;
    }*/

};

#endif