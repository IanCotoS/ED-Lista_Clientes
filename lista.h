#include <cstdlib>
#include <iostream>
using namespace std;

// Prototipos de estructuras
// es la declaracion de estas estructuras

struct Hobby;
struct NodoHobby;
struct ListaSimpleHobbies;
struct Hijo;
struct NodoHijo;
struct ListaSimple;
struct Cliente;
struct Nodo;
struct ListaDoble;

// BEGIN: Hobby------------------------------------------------------
// TAD
struct Hobby{
	string nombre;
	int cantidad; // veces por semana
	
	Hobby (string _nombre, int _cantidad){
		nombre = _nombre;
		cantidad = _cantidad;
	}
	
	Hobby (string _nombre){
		nombre = _nombre;
		cantidad = 0;
	}
	// imprime la informacion de un hijo
	void imprimir(){
		cout <<nombre<<"\t(" << cantidad <<")"<< endl;
	}
};

// nodo para la lista simple Hobby
struct NodoHobby{
	Hobby * hobby;
	NodoHobby * siguiente;
	
	NodoHobby(Hobby * _hobby){
		hobby = _hobby;
		siguiente = NULL;
	}
};


// lista simple de hobby
struct ListaSimpleHobbies{
	NodoHobby * primerNodo, *ultimoNodo;
	ListaSimpleHobbies (){
		primerNodo = ultimoNodo = NULL;
	}
	
	//imprimir lista de hobbies
	void imprimir(){
		NodoHobby *tmp = primerNodo;
		cout << "****** HOBBIES ******"	<<endl;	
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
		   tmp->hobby->imprimir();
		   tmp = tmp->siguiente;
		}
 		cout << endl;
	}


	//exists: busca un hobby por nombre
	bool exists(string nombre){
		NodoHobby *tmp = primerNodo;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			if (tmp->hobby->nombre == nombre)
				return true;
 		   tmp = tmp->siguiente;
		}
 		return false;
	}
	

	
	//imprimir lista de hobbies
	int largo(){
		NodoHobby *tmp = primerNodo;
		int counter = 0;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			counter++;
 		   tmp = tmp->siguiente;
		}
 		return counter;
	}


	// inserta en una lista de hobbies
	void insertar(Hobby * hobby)
	{
		// si no hay elementos
		if (primerNodo == NULL)
		{
			// ambos apuntan al nuevo en memoria
			ultimoNodo = primerNodo = new NodoHobby(hobby);
		}
		else
		{
			NodoHobby *nuevo = new NodoHobby(hobby);
			nuevo->siguiente = primerNodo;
			primerNodo = nuevo; 
		}
	}
};
// END: Hobby------------------------------------------------------

// TAD Hijo
struct Hijo{
	int id;
	string nombre;
	int edad;
	ListaSimpleHobbies * hobbies; // no olvidar: tiene una lista de hobbies que practica
	
	Hijo (int _id, string _nombre, int _edad){
		id = _id;
		nombre = _nombre;
		edad = _edad;
		hobbies = new ListaSimpleHobbies(); // no olvidar
	}
	// imprime la informacion de un hijo
	void imprimir(){
		cout <<"\t\tIdentificacion de Hijo "<< id <<"\t"<<nombre<<"\t\tEdad:" << edad << endl;
		hobbies->imprimir();
	}
};

// nodo para la lista simple
struct NodoHijo{
	Hijo * hijo;
	NodoHijo * siguiente;
	
	NodoHijo(Hijo * _hijo){
		hijo = _hijo;
		siguiente = NULL;
	}
};

// lista simple de hijos
struct ListaSimple{
	NodoHijo * primerNodo, *ultimoNodo;

	ListaSimple (){
		primerNodo = ultimoNodo = NULL;
	}
	
	void imprimir();
	void insertar(Hijo*);	
	
	// busca un hijo por nombre. Retorna null si no lo encuentra
	NodoHijo * buscar(string nombre){
		NodoHijo * tmp = primerNodo;
		while (tmp!= NULL){
			if (tmp->hijo->nombre == nombre)
				return tmp;
			tmp = tmp->siguiente;
		}
		return NULL;
	}
	

};


// struct Cliente
struct Cliente{
	int id;
	string nombre;
	int salario;
	ListaSimple * hijos; // tiene una lista de hijos

	// Constructores
	Cliente(){
		id = 0;		nombre = "";	salario = 0;
		hijos = new ListaSimple ();
	}
	
	Cliente(int inID, string inNombre, int inSalario){
		id = inID;
		nombre = inNombre ;
		salario = inSalario;
		hijos = new ListaSimple ();
	}
	// Imprimir los datos del cliente	
	void imprimir (){
		
		cout << "Cliente #" << id << ":\t" << nombre;
		cout << "\tSalario: " << salario <<endl;
		hijos->imprimir();
		cout <<"-----------------------------"<<endl<<endl;
	}
};

// estructura nodo para lista simple
struct Nodo {
       //int dato; // parte de datos
       Cliente * cliente;
       Nodo* siguiente;// puntero para enlazar nodos
       Nodo* anterior;
       
       Nodo(){
       	cliente = NULL;
       	siguiente = anterior = NULL;
	   }
       // constructor
       Nodo(Cliente * inCliente) {
         cliente = inCliente; // asigna los datos
         siguiente = anterior = NULL; // sig es null       
       }
       
       Nodo (int inID, string inNombre, int inSalario){
       		siguiente = anterior = NULL;
       		cliente = new Cliente (inID, inNombre, inSalario);
	   }
};

//Lista doblemente enlazada para clientes
struct ListaDoble {
       // solo con pN es suficiente
       Nodo *primerNodo, *ultimoNodo;
       // constructor
       ListaDoble()
       {
           primerNodo = ultimoNodo = NULL;
       }
       
  //----------------------------------------------
    void insertarAlInicio (Cliente * cliente)
    {
            // si no hay elementos
       if (primerNodo == NULL)
       {
        // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(cliente);
         ultimoNodo = primerNodo; 
         // ambos apuntan al nuevo               
       }
       else{
         Nodo *nuevo = new Nodo(cliente);
         nuevo->siguiente = primerNodo;
         primerNodo ->anterior = nuevo;
         primerNodo = nuevo; 
      }            
  }// fin metodo

  //----------------------------------------------  
  void imprimir(){
     Nodo *tmp = primerNodo;

     while (tmp != NULL){
       tmp->cliente->imprimir(); // metodo de imprimir un cliente
       tmp = tmp->siguiente;
     }
     cout << endl;
  }// fin metodo imprimir
  
  //----------------------------------------------
  // largo de una lista
  int largo(){
	int i = 0;
	Nodo * temp = primerNodo;
	
	while (temp!=NULL){
		i++;
		temp = temp->siguiente;
	}
	return i;
  }   
	  
	// funcion que inserta un nodo nuevo al final de la lista
	// entradas: el dato a guardar
	// salidas: no tiene
	void insertarAlFinal (Cliente * cliente)
	{
	     // si no hay elementos
	     if (primerNodo == NULL)
	     {
	         // ambos apuntan al nuevo en memoria
	         primerNodo = new Nodo(cliente);
	         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
	     }
	     else
	     {
	         Nodo *nuevo = new Nodo(cliente);
	         ultimoNodo->siguiente = nuevo;
	         nuevo->anterior = ultimoNodo;
	         ultimoNodo = nuevo;
	     }
	}
  
  	Nodo * buscar(string nombre){
  			Nodo * tmp = primerNodo;
  			while (tmp!= NULL){
  				if (tmp->cliente->nombre == nombre)
				  return tmp;
				tmp = tmp ->siguiente;	
			}
			return NULL;
	}
	
	void insertarHijo (string father, int childId, string childName, int childAge){
		Nodo * buscado = buscar(father);
		if (buscado!=NULL)
			buscado->cliente->hijos->insertar(new Hijo(childId,childName,childAge));
	}
	
  	Nodo * buscarPorId(int id){
  			Nodo * tmp = primerNodo;
  			while (tmp!= NULL){
  				if (tmp->cliente->id == id)
				  return tmp;
				tmp = tmp ->siguiente;	
			}
			return NULL;
	}
	
	// insertar hobby: busca al cliente por id, busca al hijo por nombre, inserta hobby
	void insertarHobby(int idCliente, string nombreHijo, Hobby* hobby){
		Nodo * clienteBuscado = buscarPorId (idCliente);
		if (clienteBuscado != NULL){
			NodoHijo * hijoBuscado = clienteBuscado->cliente->hijos->buscar(nombreHijo);
			if (hijoBuscado != NULL){
				hijoBuscado->hijo->hobbies->insertar(hobby);
			}
		}
	}	 

	// Funciones
	// En todas se recorren todas las listas para poder acceder a los datos
	
	// Hobbies distintos
	ListaSimpleHobbies * getDistinctHobbies(){
		ListaSimpleHobbies * listaNueva = new ListaSimpleHobbies();
		Nodo * tmp = primerNodo;
		while (tmp != NULL){
			ListaSimple * listaHijos = tmp->cliente->hijos;
			NodoHijo * tmpHijo = listaHijos->primerNodo;
			while (tmpHijo != NULL){
				ListaSimpleHobbies * listaHobbies = tmpHijo->hijo->hobbies;
				NodoHobby * tmpHobby = listaHobbies->primerNodo;
				while (tmpHobby != NULL){
				if (!listaNueva->exists(tmpHobby->hobby->nombre)){ // Si no existe el nombre del hobby
																   // en la lista nueva
					listaNueva->insertar(tmpHobby->hobby);         // Se agrega a la listaNueva
																   // el hobby
				}
				tmpHobby = tmpHobby->siguiente;
				}
				tmpHijo = tmpHijo->siguiente;
			}
			tmp = tmp->siguiente;
		}
		return listaNueva;
	}

	// Promedio de frecuencia hobby
	double getAverageFrequency(string nombreHobby){
		double cant = 0;
		double sumatoria = 0;
		Nodo * tmp = primerNodo;
		while (tmp != NULL){
			ListaSimple * listaHijos = tmp->cliente->hijos;
			NodoHijo * tmpHijo = listaHijos->primerNodo;
			while (tmpHijo != NULL){
				ListaSimpleHobbies * listaHobbies = tmpHijo->hijo->hobbies;
				NodoHobby * tmpHobby = listaHobbies->primerNodo;
				while (tmpHobby != NULL){
				if (tmpHobby->hobby->nombre == nombreHobby){ // Si nombreHobby coincide
															 // en un nombre de la listaHobbies
					sumatoria += tmpHobby->hobby->cantidad; // Suma la frecuencia al acumular
					cant++; 								// Suma uno a cantidad
				}
				tmpHobby = tmpHobby->siguiente;
				}
				tmpHijo = tmpHijo->siguiente;
			}
			tmp = tmp->siguiente;
		}
		if (cant == 0) // Si es 0, el hobby no se encontró y por tanto el promedio es 0
			return 0;
		return sumatoria/cant; // Se retorna el promedio del hobby
	}

	// Incremeta frecuencia de hobby
	void incrementFrequency(string nombreHobby){
		Nodo * tmp = primerNodo;
		while (tmp != NULL){
			ListaSimple * listaHijos = tmp->cliente->hijos;
			NodoHijo * tmpHijo = listaHijos->primerNodo;
			while (tmpHijo != NULL){
				ListaSimpleHobbies * listaHobbies = tmpHijo->hijo->hobbies;
				NodoHobby * tmpHobby = listaHobbies->primerNodo;
				while (tmpHobby != NULL){
				if (tmpHobby->hobby->nombre == nombreHobby){ // Si nombreHobby coincide
															 // en un nombre de la listaHobbies
					tmpHobby->hobby->cantidad++; // Se le suma 1 a la frecuencia
				}
				tmpHobby = tmpHobby->siguiente;
				}
				tmpHijo = tmpHijo->siguiente;
			}
			tmp = tmp->siguiente;
		}
	}
};
