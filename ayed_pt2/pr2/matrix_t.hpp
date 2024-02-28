// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 28/02/2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0); //constructos
  ~matrix_t(); // destructor
  
  void resize(const int, const int); // elimina la matriz y la reonstrulle con unos valores distintos
  
  // getters
  int get_m(void) const; //este método obtiene el valor de m
  int get_n(void) const; // este método obtiene el valor de n
  
  // getters-setters
  T& at(const int, const int); //actua como getter o como setter en función de lo que tenga el código escrito
  T& operator()(const int, const int); // actua como el metodo at.
  
  // getters constantes
  const T& at(const int, const int) const; //getter de una posición de una matriz
  const T& operator()(const int, const int) const; // actua como el método at
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const; // m_ filas y n_ columnas
  void read(istream& = cin); // vector tipo T

  //modificaciones
  void sum_mat(const matrix_t<T>&, const matrix_t<T>&); //Método que suma dos matrices
  void sub_mat(const matrix_t<T>&, const matrix_t<T>&); //Método que resta dos matrices
  void diagonal_prin(const matrix_t<T>&); //Método que calcula la diagonal principal de una matriz
  void diagonal_sec(const matrix_t<T>&); //Método que calcula la diagonal secundaria de una matriz
  void sub_triangular_inf(const matrix_t<T>&); //Método que calcula la submatriz triangular inferior de una matriz 
  void sub_triangular_sup(const matrix_t<T>&); //Método que calcula la submatriz triangular superior de una matriz
  void traspuesta(const matrix_t<T>&); //Método que calcula la matriz traspuesta de una matriz
  void sum_sub_trian_inf(const matrix_t<T>& A);
  void sum_sub_trian_sup(const matrix_t<T>& A);
  void max_min (const matrix_t<T>& A);
  void sum_diagon_prin(const matrix_t<T>& A);
  void sum_diagon_secun(const matrix_t<T>& A);
  void busc_num(const matrix_t<T>& A, double num);
  void sum_elem_ind_par(const matrix_t<T>& A); //si la suma de i y j es par suma ese elemento
  void sum_elem_ind_imp(const matrix_t<T>& A);

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for(int i = 1; i <= A.get_m(); i++){
    for(int j = 1; j <= B.get_n(); j++){
      for(int k = 1; k <= A.get_n(); k++){
        at(i,j) = at(i,j) + A(i,k)*B(k,j);
      }
    }
  }
}

// modificaciones
template<class T>
void
matrix_t<T>::sum_mat(const matrix_t<T>& D, const matrix_t<T>& E) // Suma dos matrices
{
  assert (D.get_m()*D.get_n() == E.get_m()*E.get_n()); // Comprueba que las matrices tienen el mismo tamaño
  matrix_t F(D.get_n(), D.get_m()); // Crea una matriz de tamaño (filas de D, columnas de D)
  resize(D.get_n(), D.get_m()); // Redimensiona la matriz
  for(int i = 1; i <= get_m(); i++)
    for(int j = 1; j <= get_n(); j++)
      at(i,j) = D(i,j) + E(i,j);
}

template<class T>
void
matrix_t<T>::sub_mat(const matrix_t<T>& D, const matrix_t<T>& E) // Resta dos matrices
 {
  assert (D.get_m()*D.get_n() == E.get_m()*E.get_n()); // Comprueba que las matrices tienen el mismo tamaño
  matrix_t F(D.get_n(), D.get_m()); // Crea una matriz de tamaño (filas de D, columnas de D)
  resize(D.get_n(), D.get_m()); // Redimensiona la matriz
  for(int i = 1; i <= get_m(); i++) 
    for(int j = 1; j <= get_n(); j++)
      at(i,j) = D(i,j) - E(i,j);
}

template<class T>
void
matrix_t<T>::diagonal_prin(const matrix_t<T>& F) // Calcula la diagonal principal
{
  assert(F.get_m() == F.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t H(F.get_m(), F.get_n()); // Crea una matriz de tamaño (filas de F, columnas de F)
  resize (F.get_m(), F.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_n(); i++)
    at(i,i) = F(i,i);
}

template<class T>
void
matrix_t<T>::diagonal_sec(const matrix_t<T>& F) // Calcula la diagonal secundaria
{
  assert(F.get_m() == F.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t I(F.get_m(), F.get_n()); // Crea una matriz de tamaño (filas de F, columnas de F)
  resize (F.get_m(), F.get_n()); // Redimensiona la matriz
  for (int i = 1, j = get_m(); i <= get_m(); i++,j--)
    at(i,j) = F(i,j);
}

template<class T>
void
matrix_t<T>::sub_triangular_inf(const matrix_t<T>& G) // Calcula la supmatriz triangular inferior
{
  assert(G.get_m() == G.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t J(G.get_m(), G.get_n()); // Crea una matriz de tamaño (filas de G, columnas de G)
  resize (G.get_m(), G.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); i++) 
    for (int j = 1; j <= i; j++)
      at(i,j) = G(i,j);
}

template<class T>
void
matrix_t<T>::sub_triangular_sup(const matrix_t<T>& A) // Calcula la submatriz triangular superior
{ 
  assert(A.get_m() == A.get_n()); // Comprueba que la matriz es cuadrada
  matrix_t K(A.get_m(), A.get_n()); // Crea una matriz de tamaño (filas de G, columnas de G)
  resize (A.get_m(), A.get_n()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); i++)
    for (int j = i; j <= get_m(); j++)
      at(i,j) = A(i,j);
}


// Trasponer la matriz
template<class T>
void
matrix_t<T>::traspuesta(const matrix_t<T>& A) // Calcula la traspuesta de una matriz
{
  resize(A.get_n(), A.get_m()); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); ++i) // Recorre las filas de la matriz resultado
    for (int j = 1; j <= get_n(); ++j) // Recorre las columnas de la matriz resultado
      at(i, j) = A(j, i); // Guarda el resultado en la matriz resultado, de la posición (i, j) correspondiente
}


template <class T>
void
matrix_t<T>::sum_sub_trian_inf(const matrix_t<T>& A){

 assert(A.get_m() == A.get_n()); // Comprueba que la matriz es cuadrada
  double suma{0.00};
  for (int i = 1; i <= get_m(); i++){
    for (int j = 1; j <= i; j++){
      suma += A(i,j);
    }
  }
  std::cout << suma << std::endl;
}


template <class T>
void
matrix_t<T>::sum_sub_trian_sup (const matrix_t<T>& A){

  assert(A.get_m() == A.get_n()); // Comprueba que la matriz es cuadrada
  double suma{0.00};
  for (int i = 1; i <= get_m(); i++){
    for (int j = i; j <= get_m(); j++){
      suma += A(i,j);
    }
  }
  std::cout << suma << std::endl;
}

template <class T>
void
matrix_t<T>::max_min (const matrix_t<T>& A){
   double max{0.00};
   double min{};
  for (int i = 1; i <= get_m(); i++){
    for (int j = i; j <= get_m(); j++){
      if(A(i,j) > max){
        max = A(i,j);
      }
      else if(A(i,j) < min){
        min = A(i,j);
      }
    }
  }
  std::cout << "el valor minimo es" << min << std::endl;
  std::cout << "el valor maximo es" << max << std::endl;
}

template <class T>
void
matrix_t<T>::sum_diagon_prin(const matrix_t<T>& A){

  assert(A.get_m() == A.get_n()); // Comprueba que la matriz es cuadrada
  double suma{0.00};
  for (int i = 1; i <= get_n(); i++){
    suma += A(i,i);
  }
  std::cout << suma << std::endl;
}

template <class T>
void
matrix_t<T>::sum_diagon_secun(const matrix_t<T>& A){

  assert(A.get_m() == A.get_n()); // Comprueba que la matriz es cuadrada
  double suma{0.00};
  for (int i = 1, j = get_m(); i <= get_m(); i++,j--){
    suma += A(i,j);
  }
  std::cout << suma << std::endl;
}

template <class T>
void
matrix_t<T>::busc_num(const matrix_t<T>& A, double num){
  int contador{0};
  std::cout << "el numero se encuentra en la posicion:" << std::endl;
  for(int i = 1; i < get_n(); i++){
    for(int j=1; j < get_m(); j++){
      std::cout << "el numero se encuentra en la posicion" << std::endl;
      if(num == A(i,j)){
        std::cout << A(i,j) << std::endl;
        contador++;
      }
    }
  }

  if (contador == 0){
    std::cout<< "el numero no se encuentra en la matriz" << std::endl; 
  }
  else{
    std::cout << "el numero se encuentra " << contador << " veces en la matriz" << std::endl;
  }
}

template <class T>
void
matrix_t<T>::sum_elem_ind_par(const matrix_t<T>& A){

  double sum{0.00};
  for(int i = 1; i <= A.get_m(); i++){
    for (int j = 1; j <= A.get_n();j++){
      if(((i+j)%2) == 0){
        sum = sum + A(i,j);
      } 
      else {
        sum = sum + 0;
      }
    }
  }
  std::cout << sum << std::endl;
}

template<class T>
void 
matrix_t<T>::sum_elem_ind_imp(const matrix_t<T>& A){

  double sum{0.00};
  for(int i = 1; i <= get_m(); i++){
    for (int j = 1; j <= get_n();j++){
      if(((i%2)!=0)&&((j%2)!=0)){
        sum += A(i,j);
      }
    }
  }
  std::cout << sum << std::endl;
}
