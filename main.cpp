#include "lista.h"

int main(int argc, char *argv[])
{
	ListaDoble * clientes = new ListaDoble(); //lista creada pn es null
	Cliente * ptPaco = new Cliente(1, "Paco", 10000);
	clientes->insertarAlInicio(ptPaco);
	clientes->insertarAlInicio(new Cliente(2, "Hugo", 5000));
	clientes->insertarAlInicio(new Cliente(3, "Luisa", 12000));
	clientes->insertarAlInicio(new Cliente(4, "Paula", 9000));
	
	/*
		usando el puntero ptPaco que es el ultimo de la lista
		de clientes, insertare 3 hijos. Esta forma lo insertara
		pero no es lo correcto, debe hacerse un procedimiento
		que dado un cliente y las informacion de hijos, inserte
		ese hijo al cliente
	*/
	ptPaco->hijos->insertar(new Hijo(1,"Paco Jr", 10));
	ptPaco->hijos->insertar(new Hijo(2,"Paquita", 8));
	ptPaco->hijos->insertar(new Hijo(3,"Paquete", 6));
	
	clientes->insertarHijo("Paco", 4,"Paquinha", 11);
	clientes->insertarHijo("Luisa", 4,"Luisita", 11);
	clientes->insertarHijo("Paula", 4,"Paulie", 11);


	clientes->insertarHobby(1, "Paquinha", new Hobby("tennis", 2));
	clientes->insertarHobby(1, "Paquinha", new Hobby("PS4", 4));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("futbol", 6));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("tennis", 8));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("PS4", 8));
	clientes->insertarHobby(1, "Paquita", new Hobby("tennis", 9));
	clientes->insertarHobby(1, "Paquita", new Hobby("ajedrez", 3));
	clientes->insertarHobby(1, "Paquete", new Hobby("tennis", 3));
	clientes->insertarHobby(3, "Luisita", new Hobby("tennis", 2));
	clientes->insertarHobby(3, "Luisita", new Hobby("futbol", 2));
	clientes->insertarHobby(4, "Paulie", new Hobby("tennis", 5));
	
	// clientes->imprimir();
	
	cout <<"-------------------------------"<<endl;
	cout <<"----- GET DISTINCT HOBBIES -----"<<endl;
	/* 1.  ListaSimpleHobbies * getDistinctHobbies()
	Haga un procedimiento que retorne una lista de los hobbies que practican
	lo hijos de los clientes. Los hijos pueden repetir hobbies, por ejemplo, varios de ellos
	practican tennis, se requiere que solo una vez aparezca tennis en esta lista, es decir,
	una lista de los distintos hobbies que se practican. 
	NOTA> no hace falta hacer algo con la frecuencia, solo se requiere el nombre de los
	distintos hobbies de los hijos de los clientes. 
	Ejemplo de uso:
	*/

	ListaSimpleHobbies * distintos = clientes->getDistinctHobbies();
	distintos->imprimir();
		
	
	cout <<"-------------------------------"<<endl;
	cout <<"----- GET AVERAGE FREQUENCY -----"<<endl;
	/*
	Haga un procedimiento en la lista de clientes (ListaDoble),que dado un string con el
	nombre de un hobby, retorne el promedio semanal de veces que se practica ese hobby.
	Para este caso debe recorrer toda la lista de clientes, los hijos y los hobbies para
	obtener la suma de frecuencias y la cantidad de veces que existe el hobby para retornar
	un double con el promedio. 
	Por ejemplo, si el HijoA practica tennis 6 veces, Hijo B 8 veces y el Hijo C 2 veces. 
	Esto ser�a una sumatoria de 16 veces dividido por 3 hijos que practican, el resultado
	es 5.3333 veces por semana. El promedio de veces que se practica tennis.
	
	Ejemplo de uso:
	*/

	cout << "PROMEDIO DE TENNIS ES: " << clientes->getAverageFrequency("tennis") << endl;
	cout << "PROMEDIO DE PS4 ES: " << clientes->getAverageFrequency("PS4") << endl;

	
	cout <<"\n-------------------------------"<<endl;
	cout <<"----- INCREMENT FREQUENCY -----"<<endl;
	/*
	Haga un procedimiento en la lista de clientes (ListaDoble),que dado un string con el
	nombre de un hobby busque todos los hobbies de todos los hijos
	con ese nombre e incremente en 1 la frecuncia en que se practica el hobby.
	Ejemplo de uso:
	*/

	clientes->incrementFrequency("tennis");
	clientes->imprimir();

    return EXIT_SUCCESS; 
}










