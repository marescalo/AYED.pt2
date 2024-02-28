// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 28/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// Comments style : ambos tipos de comentarios son validos, tanto "/* */" como "//".

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// Constant Names: empiezan por una "k" y el nombre que le queramos dar poniendola primera letra de cada palabra en mayúscula.
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // Order Declaration: primero public, luego protected y por último private.
public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // Spaces vs Tabs : se usan 2 espacios para identar.
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const; // este método te devuelve el número racional en decimal
  rational_t opposite(void) const; // este método calcula el número opuesto del racional
  rational_t reciprocal(void) const; // este método calcula el inverso del número racional

  bool is_equal(const rational_t&, const double precision = EPSILON) const; // este método compara si ambos números son iguales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // este método compara si el primer número es mayor que el segundo
  bool is_less(const rational_t&, const double precision = EPSILON) const; // este método compara sin el primer número es menor que el segundo


  rational_t add(const rational_t&) const; // este método realiza la suma entre dos números racionales
  rational_t substract(const rational_t&) const; // este método realiza la resta entre dos números racionales
  rational_t multiply(const rational_t&) const; // este mético realiza la multiplicación entre dos números racionales
  rational_t divide(const rational_t&) const; // este método realiza la división entre dos números racionales

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:
  // Class Data Members: todas las variables privadas tiene que tener "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); // el operador de suma está siendo sobrecargado
rational_t operator-(const rational_t&, const rational_t&); // el operador de resta está siendo sobrecargado
rational_t operator*(const rational_t&, const rational_t&); // el operador de multiplicación está siendo sobrecargado
rational_t operator/(const rational_t&, const rational_t&); // el operador de división está siendo sobrecargado

