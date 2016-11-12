/** @brief fichero de implementacion de la clase enfermedad

*/

/**
@brief constructor por defecto de la clase enfermedad
*/

enfermedad::enfermedad(){}
/**
@brief constructor por parametros de la clase enfermedad
@param[in] name nombre de la enfermedad
@param[in] ID identificador de la enfermedad
@param[in] database base de datos que provee el ID
*/
enfermedad::enfermedad(const std::string & name, const std::string & ID, const std::string & database){
  this->name=name;
  this->ID=ID;
  this->database=database;
}

/**
@brief metodo para devolver el nombre de una enfermedad
@return name nombre de la enferdad
*/
std::string enfermedad::getName( )const{
  return this->name;
}
/**
@brief metodo para devolver el ID de una enfermedad
@return ID de la enfermedad
*/
std::string enfermedad::getID( )const{
  return this->ID;
}
/**
@brief metodo para devolver el nombre de la base de datos  que proporciona el id
@return database nombre de la base de datos que proporciona el id
*/
std::string enfermedad::getDatabase( )const{
  return this->database;
}
/**
@brief asigna el nombre pasado por pametro al atributo nombre de la clase correspondiente
@param[in] name nombre de la nueva enfermedad
*/
void enfermedad::setName(const std::string & name){
  this->name=name;
}
/**
@brief asigna el ID pasado por pametro al atributo ID de la clase correspondiente
@param[in] ID de la nueva enfermedad
*/
void enfermedad::setID(const std::string & ID){
  this->ID=ID;
}
/**
@brief asigna el nombre pasado por pametro al atributo database de la clase correspondiente
@param[in] database de la nueva enfermedad
*/
void enfermedad::setDatabase(const std::string & database){
  this->database=database;
}

/**
@brief operador de asignacion de la clase enfermedad
@param[in] e objeto enfermedad que se le pasa por parametro al metodo
@return objeto enfermedad resultante
*/
enfermedad & enfermedad::operator=(const enfermedad & e){
  if(this!=&e){
      this->name=e.name;
      this->ID=e.ID;
      this->database=e.database;
    }
    return (*this);
}
/**
@brief operador de comparacion de la clase enfermedad
@param[in] e objeto enfermedad que se le pasa por parametro al metodo
@return true devuelve si se cumplen las condiciones
@return false devuelve si no se cumplen las conficiones
*/
bool enfermedad::operator==(const enfermedad & e) const{
  return this->ID==e.getID()&&this->name==e.getName()&&this->database==e.getDatabase();
}
/**
@brief metodo que devuelve todos los elementos de la clase
@return string con todas las variables y sus contenidos asociados
*/
std::string enfermedad::toString() const{
  return "\n\tNombre -> "+getName()+"\n\tID -> "+getID()+"\n\tDatabase -> "+getDatabase();
}
/**
@brief operador de negacion de la clase enfermedad que comparara dos enfermedades
@param[in] e objeto enfermedad que se le pasa por parametro al metodo
@return devolvera true si se cumple la condicion
*/
bool enfermedad::operator!=(const enfermedad & e) const{
  return !(this->ID==e.getID()&&this->name==e.getName()&&this->database==e.getDatabase());
}
/**
@brief operador de inferioridad de la clase enfermedad que comprobara si un objeto enfermedad es menor que otro
@param[in] e objeto enfermedad que se le pasa por parametro al metodo
@return objeto enfermedad resultante de la comparacion
*/
bool enfermedad::operator<(const enfermedad & e) const{	//Orden alfabético por campo name.
  return this->name<e.getName();//duda, preguntar
}
/**
@brief operador de asignacion de la clase enfermedad
@param[in] str string
@return find true si la cadena se ha encontrado dentro de la cadena pasada por parametro y false si no se ha encontrado
*/
bool enfermedad::nameContains(const std::string & str) const{   //Devuelve True si str está incluido en el nombre de la enfermedad, aunque no se trate del nombre completo. No debe ser sensible a mayúsculas/minúsculas.
  bool find;
  if(name.find(str) == std::string::npos){
    find=false;
  }else{
    find=true;
  }return find;
}
/**
@brief operador de salida para imprimir los atriubtos de una clase enfermedad
@param[in] os objeto ostream
@param[in] e obeto enfermedad
@return devuelve la salida con la cadena asociada
*/
std::ostream& operator<< ( std::ostream& os, const enfermedad & e){
    std::string cadena=e.toString();
    os << cadena;
    return os;
 }
