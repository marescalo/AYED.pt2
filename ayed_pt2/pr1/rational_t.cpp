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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) //constructor que se asegura q ambos numeros sean distintos de 0
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// no existe en la guía de google

// Type Return TYpe Sintax: el return aparece antes que el nombre de la función.
int
rational_t::get_num() const //getter con el que se obtiene el valor para el numerador
{
  return num_;
}



int
rational_t::get_den() const //getter con el que se obtiene el numero del denominador
{
  return den_;
}


  
void
rational_t::set_num(const int n)  // setter para  asignarle un valor a n
{
  num_ = n;
}


  
void
rational_t::set_den(const int d) //setter para asignarle un valor a n que sea distinto de 0
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const //metodo que devuelve el valor real de una fraccion
{ 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const //metodo que mira si son iguales
{ 
  if(fabs(value()-r.value())<precision){
    return true;
  }
  else {return false;}
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const // metodo que compara si x es mayor que y
{
  if((value()-r.value())>precision){
    return true;
  }
  else{return false;}
}



bool
rational_t::is_less(const rational_t& r, const double precision) const // metodo que compara si y es mayor que x
{
  if(r.value()-value()>precision){
    return true;
  }
  else {return false;}
}


// operaciones
rational_t
rational_t::add(const rational_t& r) // este método realiza la suma entre el valor a y b
{
  rational_t solve{((get_num() * r.get_den())+(r.get_num() * get_den())) , (get_den() * r.get_den())};
  return solve;
}



rational_t
rational_t::substract(const rational_t& r) //metodo que realiza la resta entre a y b
{
  rational_t solve {((r.get_num() * get_den())-(get_num() * r.get_den())) , (get_den() * r.get_den())};
  return solve; 
}



rational_t
rational_t::multiply(const rational_t& r) //metodo que realiza la multiplicacion entre a y b
{
  rational_t solve {(get_num() * r.get_num()) , (get_den() * r.get_den())};
  return solve;  
}



rational_t
rational_t::divide(const rational_t& r) // método que realiza la division entre a y b
{
  rational_t solve {(get_num() * r.get_den()) , (get_den() * r.get_num())};
  return solve;
}

//MODIFICACIÓN

rational_t
rational_t::inversa(const rational_t& r){
  rational_t solve(r.get_den(),r.get_num());
  return solve;
}

rational_t
rational_t::cuadrado(const rational_t& r){
  rational_t solve(pow(r.get_num(),2),pow(r.get_den(),2));
  return solve;
}

rational_t
rational_t::raiz(const rational_t& r){
  rational_t solve(r.get_num(),sqrt(r.get_den()));
  return solve;
}

// modificacion comprobación
bool rational_t::comprobar(const rational_t& r){
  if (r.get_num() % r.get_den() == 0){
    //std::cout<< "es entero" << endl;
    return true;
  }
  else{
    //std::cout<<"no es entero";
    return false;
  }
  
}

// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}