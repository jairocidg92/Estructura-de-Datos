/**
@brief constructor por defecto de la clase mutacion
*/
mutacion::mutacion(){
  ID="";
  chr="";
  pos=0;
  common=false;
}
/**
@brief constructor de copia de la clase mutacion
@param[in] m objeto tipo mutacion
*/
mutacion::mutacion(const mutacion& m){
  this->ID=m.ID;
  this->chr=m.chr;
  this->pos=m.pos;
  this->ref_alt=m.ref_alt;
  this->genes=m.genes;
  this->common=m.common;
  this->caf=m.caf;
  this->enfermedades=m.enfermedades;
  this->clnsig=m.clnsig;
}
/**
@brief constructor por parametros de la clase mutacion
@param[in] str objeto string
*/
mutacion::mutacion(const std::string & str){//para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada

  int posicion = 0;
  const char * cadena;
  std::string aux;

  //chr
  this->chr=str.substr(0,str.find("\t",0));
  posicion=str.find("\t", 0);//actualizamos la posicion

  //pos
  aux=str.substr(posicion+1,(str.find("\t",posicion+1)-(posicion+1)));
  cadena=aux.c_str();//pasamos la cadena string a vector de char para poder convertirla posteriormente a int
  this->pos=atoi(cadena);//conversor de char a int
  posicion=str.find("\t", posicion+1);

  //ID
  this->ID=str.substr(posicion+1,(str.find("\t",posicion+1)-(posicion+1)));
  posicion=str.find("\t", posicion+1);

  //ref_alt
  this->ref_alt.push_back(str.substr(posicion+1,(str.find("\t",posicion+1)-(posicion+1))));
  aux=str.substr(posicion+1,(str.find("\t",posicion+1)-(posicion+1)));
  posicion=str.find("\t",posicion+1);

  int comas=0, barras=0;
  for(unsigned int i=0; i<aux.size();i++){
    if(aux[i]==',')
    comas++;
  }

  for(int i=0;i<comas;i++){
      this->ref_alt.push_back(str.substr(posicion+1,(str.find(",",posicion+1)-(posicion+1))));
      posicion+=2;
  }
  this->ref_alt.push_back(str.substr(posicion+1,(str.find("\t",posicion+1)-(posicion+1))));

  // //genes
  posicion=str.find("GENEINFO=",0);
  aux=str.substr(posicion+9,(str.find(";",posicion+9)-(posicion+9)));
  posicion+=8;

  for(unsigned int i=0; i<aux.size();i++){
    if(aux[i]==',')
    comas++;
  }
  for(unsigned int i=0; i<aux.size();i++){
    if(aux[i]=='|')
    barras++;
  }
  for(int i=0;i<comas+barras;i++){
    if(comas){
        genes.push_back(str.substr(posicion+1,(str.find(",",posicion+1)-(posicion+1))));
        posicion=str.find(",",posicion+1);
    }
  }
  this->genes.push_back(str.substr(posicion+1,(str.find(";",posicion+1)-(posicion+1))));

  //common
  posicion=str.find("COMMON=",0);
  aux=str.substr(posicion+7,(str.find(";",posicion+7)-(posicion+7)));
  posicion+=6;
  if(aux=="1"){
    this->common=true;
  }else{
    this->common=false;
  }

  //caf
  posicion=str.find("CAF=",0);
  if(posicion!=-1){
  aux=str.substr(posicion+4,(str.find(";",posicion+4)-(posicion+4)));
  cadena=aux.c_str();
    this->caf.push_back(atof(cadena));
  }else{
    this->caf.push_back(0.0);
  }

  //ENFERMEDAD
  string idEnfermedad, nameEnfermedad, dbEnfermedad;
  posicion=str.find("CLNDSDBID=",0);
  idEnfermedad=str.substr(posicion+10, str.find(";", posicion+10)-(posicion+10));

  nameEnfermedad=str.substr(posicion+7, str.find(";", posicion+7)-(posicion+7));
  posicion=str.find("CLNDBN=",0);

  posicion=str.find("CLNDSDB=",0);
  dbEnfermedad=str.substr(posicion+8, str.find(";", posicion+8)-(posicion+8));

  enfermedad enf = enfermedad(nameEnfermedad, idEnfermedad, dbEnfermedad);

  enfermedades.push_back(enf);

  //clnsig
  posicion=str.find("CLNSIG=",0);
  aux=str.substr(posicion+7,(str.find(";",posicion+7)-(posicion+7)));
  cadena=aux.c_str();
  posicion+=6;

  for(unsigned int i=0; i<aux.size();i++){
    if(aux[i]=='|')
    barras++;
  }
  for(int i=0;i<barras;i++){
    if(barras){
        clnsig.push_back(atoi(cadena));
        posicion=str.find(",",posicion+1);
    }
  }
  this->clnsig.push_back(atoi(cadena));
}

/**
@brief metodo de asinacion del ID de la clase
@param[in] id objeto string constante
*/
void mutacion::setID(const std::string & id){
  this->ID=id;
}
/**
@brief metodo de asinacion del chr
@param[in] chr objeto string constante
*/
void mutacion::setChr(const std::string & chr){
  this->chr=chr;
}
/**
@brief metodo de asinacion de la posicion
@param[in] pos ojeto int constante sin signo
*/
void mutacion::setPos(const unsigned int & pos){
  this->pos=pos;
}
/**
@brief metodo de asinacion de la base de asignacion en el genoma de referencia y alternativas posibles
@param[in] ref_alt vector constante de string
*/
void mutacion::setRef_alt(const std::vector<std::string> & ref_alt){
  this->ref_alt=ref_alt;
}
/**
@brief metodo de asinacion de los genes asociados de la clase mutacion
@param[in] genes vector constante de string
*/
void mutacion::setGenes (const std::vector<std::string> & genes){
  this->genes=genes;
}
/**
@brief metodo de asinacion del snp comun en la poblacion
@param[in] common objeto constante booleano
*/
void mutacion::setCommon (const bool & common){
  this->common=common;
}
/**
@brief metodo de asinacion de la frecuencia del spn en la poblacion
@param[in] caf vector constante de float
*/
void mutacion::setCaf (const std::vector<float> & caf){
  this->caf=caf;
}
/**
@brief metodo de asinacion de la enfermedad
@param[in] enfermedades vector constante de enfermedades
*/
void mutacion::setEnfermedades (const std::vector<enfermedad> & enfermedades){
  this->enfermedades=enfermedades;
}
/**
@brief metodo de asinacion de la relevacia clinica del snp para cada enfermedad
@param[in] clnsig vector constante de enteros
*/
void mutacion::setClnsig (const std::vector<int> & clnsig){
  this->clnsig=clnsig;
}
/**
@brief metodo retorno para el ID de la clase
@return devuelve el ID de la clase
*/
std::string mutacion::getID( ) const{
  return this->ID;
}
/**
@brief metodo retorno para el cromosoma de la clase
@return devuelve el cromosoma de la clase
*/
std::string mutacion::getChr( ) const{
  return this->chr;
}
/**
@brief metodo retorno para la posicion
@return devuelve el atributo posicion de la clase
*/
unsigned int mutacion::getPos( ) const{
  return this->pos;
}
/**
@brief metodo retorno para la asinacion de la base en el genoma de refencia
@return devuelve el atributo ref_alt de la clase
*/
const std::vector<std::string> &mutacion:: getRef_alt () const{
  return this->ref_alt;
}
/**
@brief metodo retorno para los genes
@return devuelve atributo gen de la clase
*/
const std::vector<std::string> &mutacion:: getGenes () const{
  return this->genes;
}
/**
@brief metodo retorno para el snp de la clase
@return devuelve atributo common de la clase
*/
bool mutacion::getCommon () const{
  return this->common;
}
/**
@brief metodo retorno para la frecuencia de cada base del snp
@return devuelve atributo caf de la clase
*/
const std::vector<float> &mutacion:: getCaf () const{
  return this->caf;
}
/**
@brief metodo retorno para las enfermedades
@return devuelve atributo enfermedades
*/
const std::vector<enfermedad> &mutacion:: getEnfermedades () const{
  return this->enfermedades;
}
/**
@brief metodo retorno para la relevancia clinica del snp para cada enfermedad
@return devuelve atributo clnsig de la case
*/
const std::vector<int> &mutacion:: getClnsig () const{
  return this->clnsig;
}
/**
@brief operador de asignacion de la clase mutacion
@param[in] m objeto mutacion que se le pasa por parametro al metodo
@return atributos de la clase
*/
mutacion &mutacion::operator=(const mutacion & m){
  if(this!=&m){
    this->ID=m.ID;
    this->chr=m.chr;
    this->pos=m.pos;
    this->ref_alt=m.ref_alt;
    this->genes=m.genes;
    this->common=m.common;
    this->caf=m.caf;
    this->enfermedades=m.enfermedades;
    this->clnsig=m.clnsig;
  }return *this;
}
/**
@brief operador de comparacion de la clase mutacion
@param[in] m objeto mutacion que se le pasa por parametro al metodo
@return true devuelve si se cumplen las condiciones
@return false devuelve si no se cumplen las conficiones
*/
bool mutacion::operator==(const mutacion & m) const{
  return this->ID==m.getID() && this->chr==m.getChr() && this->pos==m.getPos() && this->ref_alt==m.getRef_alt() && this->genes==m.getGenes()
  && this->common==m.getCommon() && this->caf==m.getCaf() && this->enfermedades==m.getEnfermedades() && this->clnsig==m.getClnsig();
}
/**
@brief operador de inferioridad de la clase mutacion que comprobara si un objeto mutacion es menor que otro
@param[in] m objeto mutacion que se le pasa por parametro al metodo
@return objeto mutacion resultante de la comparacion
*/
bool mutacion::operator<(const mutacion & m) const{//El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT".
//Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros).
  return (this->chr<m.getChr()) || (this->chr==m.getChr() && this->pos<m.getPos());
  //a parte de tener numeros 1-22 tambien puedes almacenar x,y,mt (que los pondremos como 23,24,25)
}
/**
@brief metodo get de tipo plantilla para poder usarlo con distintos tipo de objeto
@param[in] temp vector constante de tipo plantilla
@param[in] posicion posicion a devolver del vector
@return posicion resultante del vector
*/
template <typename T>
const T& getVectorData(const std::vector<T> & temp, int posicion)
{
      return temp[posicion];
}
/**
@brief operador de salida para la impresion de los atributos de la clase mutacion
@param[in] os objeto tipo ostream
@param[in] m objeto de tipo mutacion constante
@return os devuelve los valores asociados a m
*/
std::ostream& operator<<(std::ostream& os, const mutacion& m)
{
  os << "-ID :"<<m.getID()<< endl;
  os << "-CHR :"<<m.getChr()<< endl;
  os << "-POS :"<<m.getPos() << endl;

  os << "-REF_ALT :";
   for(int i=0; i<m.getRef_alt().size(); i++)
      os << getVectorData(m.getRef_alt(), i);
  os << endl<< "-GENEINFO :";
   for(int i=0; i<m.getGenes().size(); i++)
      os << getVectorData(m.getGenes(), i);

  os << endl<<"-CMON :"<< m.getCommon();
  os << endl<<"-CAF :";
   for(int i=0; i<m.getCaf().size(); i++)
      os << getVectorData(m.getCaf(), i);
  os <<endl<< "-ENFERMEDADES :";
   for(int i=0; i<m.getEnfermedades().size(); i++)
    os << getVectorData(m.getEnfermedades(), i);
      os <<endl<< "-CLNSIG :";
   for(int i=0; i<m.getClnsig().size(); i++){
    if(i==m.getClnsig().size()-1){
      cout << getVectorData(m.getClnsig(),i) << "";
    }else{
      cout << getVectorData(m.getClnsig(),i) << "|";}
    }

   return os;
}
