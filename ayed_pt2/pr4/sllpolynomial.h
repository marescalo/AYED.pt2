// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for(int i{v.get_size()-1}; i>=0; i--){
    if(IsNotZero(v[i])){
      pair_double_t value{v[i],i};
      SllPolyNode* node = new SllPolyNode{value};
      push_front(node);
    }
  }
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux = get_head(); // aux apunta a head
  while (aux != NULL){
    result += aux->get_data().get_val()*pow(x,aux->get_data().get_inx()); // se suma en reusult la multiplicacion 9del valopr de estra posicion por la x sustituida elevada al inx
    aux = aux->get_next(); //apunta al siguiente nodo
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {
  bool differents = false;
  int count = 0;
  SllPolyNode* aux = get_head();
  while (aux != NULL){
    count ++;
    aux = aux->get_next();
  }
  int cuenta = 0;
  SllPolyNode* aux2 = sllpol.get_head();
  while (aux2 != NULL){
    cuenta ++;
    aux2 = aux2 = aux2->get_next();
  }
  if (count != cuenta){
    return differents;
  }
  else{
    aux = get_head();
    aux2 = sllpol.get_head();
    while(aux != NULL){
      if((aux->get_data().get_val() != aux2->get_data().get_val()) || (aux->get_data().get_inx() != aux2->get_data().get_inx())){
        return differents;
      }
      aux = aux->get_next();
      aux2 = aux2->get_next();
    }
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) {
  SllPolyNode* aux = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  int inx = 0;

  while(aux != NULL){
    if ((aux->get_data().get_inx()) > inx){  //si el índice de aux es menor que inx
      inx = aux->get_data().get_inx(); // iguala inx al indice de aux
    }
    aux = aux->get_next(); // apunta al siguiente nodo
  }
  while(aux2 != NULL){
    if ((aux2->get_data().get_inx()) > inx){ 
      inx = aux2->get_data().get_inx();
    }
    aux2 = aux2->get_next();
  }

  vector_t<double> v(inx+1);
  aux = get_head();
  aux2 = sllpol.get_head();

  for(int i = 0; i < v.get_size(); i++){
    v[i] = 0;
  }

  while(aux !=NULL) {
    v[aux->get_data().get_inx()] += aux->get_data().get_val();
    aux = aux->get_next();
  }

    while(aux2 !=NULL) {
    v[aux2->get_data().get_inx()] += aux2->get_data().get_val();
    aux2 = aux2->get_next();
  }
  for(int i {v.get_size()-1}; i>=0; i--){
    if(IsNotZero(v[i])){
      pair_double_t value{v[i],i};
      SllPolyNode* node = new SllPolyNode{value};
      sllpolsum.push_front(node);
    }
  }
}

//modifiación de mostrar todos los polinomios menos el primero y el último.

void SllPolynomial::MostrarIntermedio(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  aux = aux->get_next();
  while (aux->get_next() != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
      os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

//modificación de resta

void SllPolynomial::Resta(const SllPolynomial& sllpol,
			SllPolynomial& sllpolResta,
			const double eps) {

  SllPolyNode* aux = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  int inx = 0;

  while(aux != NULL){
    if ((aux->get_data().get_inx()) > inx){
      inx = aux->get_data().get_inx();
    }
    aux = aux->get_next();
  }
  while(aux2 != NULL){
    if ((aux2->get_data().get_inx()) > inx){
      inx = aux2->get_data().get_inx();
    }
    aux2 = aux2->get_next();
  }

  vector_t<double> v(inx+1);
  aux = get_head();
  aux2 = sllpol.get_head(); 

  for(int i = 0; i < v.get_size() ;i++){
    v[i] = 0;
  }

  while(aux != NULL){
    v[aux->get_data().get_inx()] += aux->get_data().get_val();
    aux = aux->get_next();
  }

  while(aux2 != NULL){
    v[aux2->get_data().get_inx()] -= aux2->get_data().get_val();
    aux2 = aux2->get_next();
  }
  for (int i {v.get_size()-1}; i >= 0; i--){
    if(IsNotZero(v[i])){
      pair_double_t value{v[i],i};
      SllPolyNode* node = new SllPolyNode{value};
      sllpolResta.push_front(node);
    }
  }
} 

//sumar los valores de los exponentes que sean consecutivos
void SllPolynomial::Consecutivo() {

SllPolyNode* aux = get_head();
SllPolyNode* next = (aux->get_next()) ;
while(next != NULL){
  if(aux->get_data().get_inx() == (next->get_data().get_inx() -1)){
    std::cout << (aux->get_data().get_val() + next->get_data().get_val()) << " / ";
  }
  aux = aux ->get_next();
  next = next->get_next();
  }
  std::cout << std::endl;
}

void SllPolynomial::Pares(SllPolynomial& sllpolPares) {
  SllPolyNode* aux{get_head()};
  SllPolyNode* node{aux};
  //SllPolyNode* node{get_head()};
  while (aux != NULL) {
    if ((aux->get_data().get_inx()%2) == 0){
      //node = aux
      sllpolPares.push_front(node);
    }
    aux = aux->get_next();
  }
  
}


/*void SllPolynomial::Pares(std::ostream& os) const {
    os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if ((aux->get_data().get_inx()%2) == 0){
      if (val > 0)
        os << (!first ? " + " : "") << val;
      else
        os << (!first ? " - " : "-") << fabs(val);
        os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
      if (inx > 1)
        os << inx;
      first = false;
    }
    
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}*/


#endif  // SLLPOLYNOMIAL_H_
