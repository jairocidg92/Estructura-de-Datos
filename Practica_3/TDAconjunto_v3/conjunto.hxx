/**
@brief constructor por defecto de la clase conjunto
*/
conjunto::conjunto(){}

/**
@brief constructor de copia de la clase conjunto
@param[in] d objeto tipo mutacion
*/
conjunto::conjunto(const conjunto & d){
  this->vm=d.vm;
}

/**
@brief metodo que obtiene las mutaciones existentes
@return devuelve un objeto mutacion
*/
const vector<mutacion> conjunto::getVM()const{
  return this->vm;
}
/**
@brief metodo begin de la clase conjunto
@return la primera posicion del vector vm
*/
conjunto::iterator conjunto::begin(){
  conjunto::iterator inicio = vm.begin();
  return inicio;
}

/**
@brief metodo end de la clase conjunto
@return la ultima posicion del vector vm
*/
conjunto::iterator conjunto::end (){
  conjunto::iterator ultimo = vm.end();
  return ultimo;
}

/**
@brief metodo cbegin de la clase conjunto
@return la primera posicion del vector vm
*/
conjunto::const_iterator conjunto::cbegin () const{
  return vm.cbegin();
}

/**
@brief metodo cend de la clase conjunto
@return la primera posicion del vector vm
*/
conjunto::const_iterator conjunto::cend () const{
  return vm.cend();
}

/**
@brief metodo fin de la clase conjunto el cual busca por el cromosoma y la posicion
@param[in] chr string constante de tipo cromosoma
@param[in] pos unsigned constante de tipo entero
@return aux devuelve las parejas con el cromosoma y posicion pasadas por parametro
*/
pair<conjunto::value_type,bool> conjunto::find(const string & chr, const unsigned int & pos)const{
  pair<value_type, bool> aux;
  aux.first=mutacion();
  aux.second=false;
  const_iterator it;

  for(it=vm.begin();it!=vm.end()&&!aux.second;it++){
    if((*it).getChr()==chr && (*it).getPos()==pos){
      aux.first=(*it);
      aux.second=true;
    }
  }return aux;
}

/**
@brief operador find de la clase conjunto el cual busca por ID
@param[in] ID objeto tipo ostream
@return aux devuelve las parejas que tiene el ID pasado por parametro
*/
pair<conjunto::value_type,bool> conjunto::find(const string & ID)const{
  pair<value_type, bool> aux;
  aux.first=mutacion();
  aux.second=false;
  const_iterator it;
  for(it=vm.begin();it!=vm.end()&&!aux.second;it++){
    if((*it).getID()==ID){
      aux.first=(*it);
      aux.second=true;
    }
  }return aux;
}

/**
@brief metodo find de la clase conjunto el cual busca el value_type pasado por parametro
@param[in] e objeto tipo value_type
@param[in] m objeto de tipo mutacion constante
@return aux devuelve las parejas que tengan el id, chr y la pos pasada por parametro
*/
pair<conjunto::value_type,bool> conjunto::find(const conjunto::value_type & e)const{
  pair<value_type, bool> aux;
  aux.first=mutacion();
  aux.second=false;
  const_iterator it;
  for(it=vm.begin();it!=vm.end()&&!aux.second;it++){
    if(((*it).getID()==e.getID())||((*it).getChr()==e.getChr()&&(*it).getPos()==e.getPos())){
      aux.first=(*it);
     }
  }return aux;
}

/**
@brief metodo find de la clase conjunto el cual busca el value_type pasado por parametro
@param[in] chr objeto de tipo string constante
@param[in] pos objeto unsigned constante de tipo entero
@return cont devuelve el numero de elemntos que coinciden con las condiciones pasadas por parametro
*/
conjunto::size_type conjunto::count(const string & chr, const unsigned int & pos)const{
  size_type cont=0;
  const_iterator it;
  bool find = false;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getChr()==chr && (*it).getPos()==pos){
      cont++;
      find=true;
    }
  }return cont;
}

/**
@brief metodo find de la clase conjunto el cual busca el ID
@param[in] ID objeto de tipo string constante
@return cont devuelve el numero de elemntos que coinciden con las condiciones pasadas por parametro
*/
conjunto::size_type conjunto::count(const string & ID)const{
  size_type cont=0;
  const_iterator it;
  bool find=false;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getID()==ID){
      cont++;
      find=true;
    }
  }return cont;
}

/**
@brief metodo find de la clase conjunto el cual busca el value_type pasado por parametro
@param[in] e objeto de tipo value_type constante
@return cont devuelve el numero de elemntos que coinciden con las condiciones pasadas por parametro
*/
conjunto::size_type conjunto::count(const conjunto::value_type & e)const{
  size_type cont=0;
  const_iterator it;
  bool find=false;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getID()==e.getID())
      cont++;
      find=true;
  }return cont;
}

/**
@brief metodo insert de la clase conjunto la clase conjunto
@param[in] e objeto de tipo value_type constante
@return encontrado objeto de tipo bool que indica si se ha insertado o no correctamente un elemento
*/
// bool conjunto::insert(const conjunto::value_type & e){
//   bool encontrado=false;
//   const_iterator it, itpos;
//
//   it=vm.begin();
//   itpos=vm.end();
//   while(it!=  vm.end() && !encontrado)
//   {
//     if((*it).getChr() < e.getChr() || ((*it).getChr() == e.getChr() && (*it).getPos() < e.getPos()))
//       itpos = it;
//     if(((*it).getChr() == e.getChr() && (*it).getPos() == e.getPos()) || (*it).getID() == e.getID())
//       encontrado = true;
//     it++;
//   }
//
//   if(!encontrado) {
//     if(itpos != vm.end())itpos++;
//     vm.insert(itpos, e);
//   }
//   return encontrado;
// }

bool conjunto::insert(const conjunto::value_type & e){
  if (!find(e.getID()).second){
    vm.push_back(e);
    return true;
  }else{
    return false;
  }
}

/**
@brief metodo erase de la clase conjunto el cual elimina por chr y pos pasada por parametro
@param[in] chr objeto de tipo string constante
@param[in] pos objeto de tipo unsigned entero constante
@return find deuelve un booleano si se ha eliminado con exito
*/
bool conjunto::erase(const string & chr, const unsigned int & pos){
  bool find=false;
  const_iterator it;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getChr()==chr && (*it).getPos()==pos){
      vm.erase(it);
      find=true;
    }
  }return find;
}

/**
@brief metodo erase de la clase conjunto el cual elimina por ID
@param[in] ID objeto de tipo string constante
@return find deuelve un booleano si se ha eliminado con exito
*/
bool conjunto::erase(const string & ID){
  bool find=false;
  const_iterator it;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getID()==ID){
      vm.erase(it);
      find=true;
    }
  }return find;
}

/**
@brief metodo erase de la clase conjunto el cual elimina por el value_type pasado por parametro
@param[in] e objeto de tipo value_type constante
@return find deuelve un booleano si se ha eliminado con exito
*/
bool conjunto::erase (const conjunto::value_type & e){
  bool find=false;
  const_iterator it;
  for(it=vm.begin();it!=vm.end();it++){
    if((*it).getID()==e.getID()){
      vm.erase(it);
      find=true;
    }
  }return find;
}
/**
@brief limpia el vector de mutaciones
*/
void conjunto::clear(){
  vm.clear();
}

/**
@brief metodo size de la clase conjunto constante
@return tamanio devuelve el tamaño del size_type pasado por parametro
*/
conjunto::size_type conjunto::size()const{
  conjunto::size_type tamanio = vm.size();
  return tamanio;
}
/**
@brief metodo empty de la clase conjunto
@return devuelve true si esta vacio y false si tiene elementos
*/
bool conjunto::empty()const{
  return vm.empty();
}

/**
@brief operador igual de la clase conjunto
@param[in] orig objeto de tipo conjunto constante
@return devuelve true si es igual y false si son distintos
*/
conjunto & conjunto::operator=(const conjunto & orig){
  if(this!= &orig){
    if(!orig.empty())
      clear();
      this->vm=orig.getVM();
  }return *this;
}

/**
@brief  metodo lower_bound de la clase conjunto
@param[in] chr objeto de tipo string constante
@param[in] pos objeto de tipo unsigned entero constante
@return iterador con las posiciones las cuales cumplen las condiciones pasadas por parametro
*/
conjunto::const_iterator conjunto::lower_bound(const string & chr, const unsigned int & pos){
  conjunto::iterator lower = begin();

   while((*lower).getChr() != chr && (*lower).getPos() != pos && lower != end() ) {
    lower++;
   }return lower;

}

/**
@brief  metodo lower_bound de la clase conjunto
@param[in] e objeto de tipo value_type constante
@return iterador con las posiciones las cuales cumplen las condiciones pasadas por parametro
*/
conjunto::const_iterator conjunto::lower_bound(const conjunto::value_type & e){
  return lower_bound(e.getChr(), e.getPos());
}

/**
@brief  metodo upper_bound de la clase conjunto
@param[in] chr objeto de tipo string constante
@param[in] pos objeto de tipo unsigned entero constante
@return iterador con las posiciones las cuales cumplen las condiciones pasadas por parametro
*/
conjunto::const_iterator conjunto::upper_bound(const string & chr, const unsigned int & pos){
  conjunto::iterator upper = begin();

   while ( (*upper).getChr() != chr && ((*upper).getPos() != pos && upper != end() ))
    upper++;


   return upper;
}

/**
@brief  metodo upper_bound de la clase conjunto
@param[in] chr objeto de tipo string constante
@param[in] pos objeto de tipo unsigned entero constante
@return iterador con las posiciones las cuales cumplen las condiciones pasadas por parametro
*/
conjunto::const_iterator conjunto::upper_bound(const conjunto::value_type & e) {
  return upper_bound(e.getChr(),e.getPos());
}

bool conjunto::cheq_rep()const{
  const_iterator it=vm.begin();
  const_iterator aux=it;
  for(aux++;it!=vm.end(); it++){
		if((((*it).getID()) != "0" ) || ( (*it).getID() != (*aux).getID() ))
			return false;
	}
  return true;
}

/**
@brief  operador de impresion de la clase conjunto
@param[in] sal operador de salida+
@param[in] C objeto de tipo conjunto constante
*/
ostream &  operator << ( ostream & sal, const conjunto & C){
  for(int i=0;i<C.size();i++){
    sal << C.getVM()[i];
  }return sal;//??
}
