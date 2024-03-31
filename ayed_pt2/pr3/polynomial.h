// AUTOR: Margarita Blanca Escobar Alonso
// FECHA: 8 marzo 2024
// EMAIL: alu0101567211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
  void morethan(const int n) const;
  void pair (const int n) const;
  void impar(const int) const;
  void monomio(const int n) const;
  void mayormenormon() const;
  void coefgradoi(const int n) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for(int i{0}; i < get_size();i++ ){
    if(IsNotZero(at(i))){
      result += pow(x,i) * get_val(i);
    }
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
    for (int i{0}; i < get_size(); i++){
      if(IsNotZero(at(i))){
        if(fabs(get_val(i) - pol.get_val(i))>eps){
          return differents;
        }
      }
    }
    return !differents; 
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
    for (int i{0}; i < get_nz(); i++){
    result += at(i).get_val()*pow(x,at(i).get_inx());
    }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  if(get_nz() == spol.get_nz()){
    for(int i{0}; i < get_nz(); i++){
      if((at(i).get_inx() != spol.at(i).get_inx()) || (at(i).get_val() != spol.at(i).get_val())){
        return differents;
      }
    }
    return !differents;
  }
  return differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int number{0};
    for(int i{0}; i < get_nz(); i++){
      if(IsNotZero(pol[i])){
        if((i != at(number).get_inx())|| (pol.at(i) != at(number).get_val())){
          return differents;
        }
        number ++;
      }
    }
  return !differents;
}

//modificaciones

//mostrar los eleento a partir de la n posisicon

void SparsePolynomial::morethan(const int n) const {
  std::cout << "[";
  for(int i{n}; i < get_nz(); i++){
      std::cout << at(i) << ",";
    }
  std::cout << "]" << std::endl; 
}

//muestras los valores que esten en posiciones pares

void SparsePolynomial::pair(const int ) const {

std::cout << "[";
for(int i{0}; i < get_nz(); i++){
  if ( (at(i).get_inx() % 2) == 0)
    std::cout << at(i) << "," ;
}
std::cout << "]" << std::endl;
}

//muestra los valores que esten en posiciones impares

void SparsePolynomial::impar(const int ) const {

std::cout << "[";
for(int i{0}; i < get_nz(); i++){
  if ( (at(i).get_inx() % 2) != 0)
    std::cout << at(i) << "," ;
}
std::cout << "]" << std::endl;
}

// imprimir el coeficiente que corresoponda con el monomio introducido
void SparsePolynomial::monomio(const int n) const {

std::cout << "[";
for(int i{0}; i < get_nz(); i++){
  if (at(i).get_inx() == n)
    std::cout << at(i) << "," ;
  else if (at(i).get_inx() != n)
    std::cout << "no,";
}
std::cout << "]" << std::endl;

}

void SparsePolynomial::mayormenormon() const {
  int mayor = at(0).get_inx();
  for(int i{0} ; i < get_nz();i++){
    if(at(i).get_inx() > mayor){
      mayor = i;
    }
  }

  int menor = mayor;
  for(int i{0}; i < get_nz() ; i++){
    if(at(i).get_inx() < menor){
      menor = i;
    }
  }
  std::cout << "menor monomio" << at(menor) << std::endl;
  std::cout << "mayor monomio" << at(mayor) << std::endl; 
}

void SparsePolynomial::coefgradoi(const int n) const {
  for(int i{0}; i < get_nz(); i++){
    if (at(i).get_inx() == n){
        std::cout << at(i) << std::endl;
    }
  }
}

#endif  // POLYNOMIAL_H_
