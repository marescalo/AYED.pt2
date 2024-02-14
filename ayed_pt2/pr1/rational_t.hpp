// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 08/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// Comments style : ambos tipos de comentarios son validos, tanto "/* */" como "//".

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// Constant Names: empiezan por una "k" y el nombre que le queramos dar poniendomla primera letra de cada palabra en mayúscula.
# define EPSILON 1e-6

using namespace std;

class rational_t
{
    // Order Declaration: primero public, luego protected y por último private.
public: // Elementos publicos
  rational_t(const int = 0, const int = 1); //constructor
  ~rational_t() {} //destructor
  
  // Spaces vs Tabs : se usan 2 espacios para identar.
  // getters
  // los getters son métodos que retornan el atributo al que pertenecen
  int get_num() const; // este método retorna el valor de num
  int get_den() const; // este método retorna el valor del den
  
  // setters
  // los setters son métodos cambian el valor del atributo al que pertenecen
  void set_num(const int); // este método cambia el valor del atributo num
  void set_den(const int); // este método cambia el valor del atributo den

  double value(void) const; //metodo para obtener el valor real de una fraccion

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const; //método para ver si es igual
  bool is_greater(const rational_t&, const double precision = EPSILON) const; //método para ver si es mayor
  bool is_less(const rational_t&, const double precision = EPSILON) const; //método para ver si es menor
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  //modificaciones
  rational_t inversa(const rational_t&);
  rational_t cuadrado(const rational_t&);
  rational_t raiz(const rational_t&);
  bool comprobar(const rational_t&);
  
  void write(ostream& = cout) const; //lectura desde teclado  //ostream y cout llevan std::
  void read(istream& = cin); //scritura a pantalla  // istream y cin llevan std::
  
private: // Elementos privados 
// Class Data Members: todas las variables privadas tiene que tener "_"
  int num_, den_; // atributos
};