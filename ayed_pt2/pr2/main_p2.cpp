// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 28/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// Comments style : ambos tipos de comentarios son validos, tanto "/* */" como "//".

#include <iostream>
#include <cmath>

// Include Files And Include Statements: Los includes tiene que estar ordenados y agrupados por tipos.
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w, z;
  v.read(), v.write();
  w.read(), w.write();
  z.read(), z.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C, D, E, F, G, H, I, J, K, M;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  //modificaciones

/*
  D.read(), D.write();
  E.read(), E.write(); // Se leen y muestran por pantalla las matrices 
  
   F.sum_mat(E,D);
   cout << "Suma de matrices D Y E: " << endl; // Se muestra por pantalla la suma de las matrices
   F.write();

   G.sub_mat(D,E);
   cout << "Resta de matrices D Y E: " << endl; // Se muestra por pantalla la resta de las matrices
   G.write();

   H.diagonal_prin(F);
   cout << "Diagonal principal de F: " << endl; // Se muestra por pantalla la diagonal principal de la matriz F
   H.write();

   I.diagonal_sec(F);
   cout << "Diagonal secundaria de F: " << endl; // Se muestra por pantalla la diagonal secundaria de la matriz F
   I.write();

   J.sub_triangular_inf(G);
   cout << "Submatriz triangular inferior de G: " << endl; // Se muestra por pantalla la submatriz triangular inferior de la matriz G
   J.write();

   K.sub_triangular_sup(G); // Se muestra por pantalla la submatriz triangular superior de la matriz G
   cout << "Submatriz triangular superior de G: " << endl;
   K.write();

   M.traspuesta(G); // Se muestra por pantalla la traspuesta de la matriz G
   cout << "Traspuesta de G: " << endl;
   M.write();
  

   v.suma_vector(v);


   std::cout << "suma de la submatriz inferior: " << std::endl;
   D.sum_sub_trian_inf(D);
   std::cout << "suma de la submatriz superior: " << std::endl;
   E.sum_sub_trian_sup(E);
   std::cout << " numero maximo y numero minimo: " << std::endl;
   A.max_min(A);
   std::cout << "suma de la diagonal `principal: " << std::endl;
   E.sum_diagon_prin(E);
   std::cout << "suma de la diagonal segundaria: " << std::endl;
   D.sum_diagon_secun(D);
   std::cout << "buscar l numero: " << std::endl;
   A.busc_num(A,0.00);
   std::cout << "suma de elementos de indice impar: " << std::endl;
   B.sum_elem_ind_imp(B);
   std::cout << "suma de elementos de indice par: " << std::endl;
   A.sum_elem_ind_par(A); 
   std::cout << "suma de perimetro: " << std::endl;
   D.sum_per(D);
*/

v.sum_dos_elem(v);

  return 0;
}