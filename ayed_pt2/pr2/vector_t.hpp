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

using namespace std;

template<class T>
class vector_t
{
public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

  // modificaciones
  
  void suma_vector (const vector_t<T>&) const;
  void sum_dos_elem(const vector_t <T>& v) const;


private:
  T *v_; // vector de tipo T
  int sz_; // esto es un atributo que representa el tamaño del vector.
  
  void build(void); // crea el vector
  void destroy(void); // destruye el vector creado por build. 
};



template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}



template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}



template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}



template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}



template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  T sum{0};
  for(int position{0}; position < v.get_size(); position++){
    sum = sum + (v[position]*w[position]);
  }
  return sum;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  double sum{0};
  for(int position{0}; position < v.get_size(); position++){
    sum = sum + (v[position]*w[position]).value();
  }
  return sum;
}


//modificaciones

template <class T>
void vector_t<T>::suma_vector (const vector_t<T>& v) const {
  double resultado;
  for (int i = 0; i < v.get_size(); i+=2) {
   resultado += v[i]; 
  }
  std::cout << resultado << std::endl;
}


template <class T>
void vector_t<T>::sum_dos_elem(const vector_t<T>& v) const {
  vector_t<T> result;
  for (int i{1}; i <= v.get_size(); i++){
    vector_t sum = v[i-1]+v[i];
    result = sum;
    //std::cout << result <<std::endl;
    result.write();
  }
  std::cout << std::endl;
}