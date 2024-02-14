// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 08/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// Comments style : ambos tipos de comentarios son validos, tanto "/* */" como "//".

#include <iostream>
#include <cmath>

// Include Files And Include Statements: Los includes tiene que estar ordenados y agrupados por tipos.
#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c; //valores que se le pasan a la clase

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  // se contruyen las fracciones con los valores pasados
  cout << "a: ";
  a.write(); 
  cout << "b: ";
  b.write();
  // se piden los valores para poder crear una tercera fraccion
  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();
  
  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();
  
  cout << "a / b: ";
  a.divide(b).write();

//MODIFICACION
//inversa
  cout << "inversa de a ";
  a.inversa(a).write();

  cout << "inversa de b ";
  b.inversa(b).write();

  cout << "inversa de c ";
  c.inversa(c).write();
  
//cuadrada
  cout << "cuadrado de a ";
  a.cuadrado(a).write();

  cout << "cuadrado de b ";
  b.cuadrado(b).write();

  cout << "cuadrado de c ";
  c.cuadrado(c).write();

//raiz cuadrada
  cout << "raiz de a ";
  a.raiz(a).write();

  cout << "raiz de b ";
  b.raiz(b).write();

  cout << "raiz de c ";
  c.raiz(c).write();

//comprobacion
  cout << "comprobar si es entero" << endl;;
  bool result = a.comprobar(a);

  if(result == true){
    cout << "TRUE" << endl;
  }
  else{
    cout << "FALSE" << endl;
  }

  return 0;
}