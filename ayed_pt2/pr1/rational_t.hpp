// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 08/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public: // Elementos publicos
  rational_t(const int = 0, const int = 1); //constructor
  ~rational_t() {} //destructor
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const; //metodo para obtener el valor rela de una fraccion

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const; //método para ver si es igual
  bool is_greater(const rational_t&, const double precision = EPSILON) const; //método para ver si es mayor
  bool is_less(const rational_t&, const double precision = EPSILON) const; //método para ver si es menor
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const; //lectura desde teclado  //ostream y cout llevan std::
  void read(istream& = cin); //scritura a pantalla  // istream y cin llevan std::
  
private: // Elementos privados 
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; // atributos
};