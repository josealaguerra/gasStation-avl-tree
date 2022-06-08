#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex>



/*
Esta aplicacion tiene como proposito el poder
guardar la informacion diaria de cada estacion
de gasolineras llevando el registro de cada
combustible en dichas gasoilneas.


Jose Alfredo Guerra Gomez



*/

// AVL tree implementation in C++



using namespace std;

class nodeGasStation {
	public:
		//Informacion
		int GasStationID;
		string GasStationName ;
		string GasStationDepartamento ;
		string GasStationMunicipio ;
		int GasStationZona ;
		double GasStationLatitud ;
		double GasStationLongitud ;
		int GasStationAnio ;
		int GasStationMes ;
		int GasStationDia ;
		double GasStationDiesel ;
		double GasStationRegular ;
		double GasStationSuper ;
		//Nodos
		nodeGasStation *nodoIzquierda;
		nodeGasStation *nodoDerecha;
		int altura;
};


// Variables que guardan temporalmente la altura de los nodos
//de la izquierda y derecha respectivamente.
int alturaNodoIzquierda=0, alturaNodoDerecha=0 ;
// Variable temporal para definir la raiz
int esRaiz = 0 ;
bool seEncontroLlave = false ;
//int max(int paramNum1, int paramNum2);


std::string ltrim(const std::string& s)
{
    static const std::regex lws{"^[[:space:]]*", std::regex_constants::extended};
    return std::regex_replace(s, lws, "");
}

std::string rtrim(const std::string& s)
{
    static const std::regex tws{"[[:space:]]*$", std::regex_constants::extended};
    return std::regex_replace(s, tws, "");
}

std::string trim(const std::string& s)
{
    return ltrim(rtrim(s));
}









// Descripción: Calcula la altura de un nodo con respecto a la raiz
// Parametro entrada: nodo
// Devuelve la altura
int calculaAltura(nodeGasStation *paramNodo) {
	if (paramNodo == NULL)
		return 0;
	return paramNodo->altura;
}



// Descripción: Compara dos numeros y devuelve el mayor de ellos
// Parametro entrada: numero 1 y numero 2
// Devuelve el numero con mayor valor entre 2
int max(int paramNum1, int paramNum2) {
	return (paramNum1 > paramNum2) ? paramNum1 : paramNum2;
}






//Solicita información en pantalla y
//agrega al arbol
nodeGasStation *setNodeData(nodeGasStation *paramNodoOrigen, nodeGasStation *paramNodoDestino) {

	paramNodoDestino->GasStationID 			= paramNodoOrigen->GasStationID ;
	paramNodoDestino->GasStationName		= paramNodoOrigen->GasStationName ;
	paramNodoDestino->GasStationDepartamento= paramNodoOrigen->GasStationDepartamento ;
	paramNodoDestino->GasStationMunicipio 	= paramNodoOrigen->GasStationMunicipio ;
	paramNodoDestino->GasStationZona 		= paramNodoOrigen->GasStationZona ;
	paramNodoDestino->GasStationLatitud 	= paramNodoOrigen->GasStationLatitud ;
	paramNodoDestino->GasStationLongitud 	= paramNodoOrigen->GasStationLongitud ;
	paramNodoDestino->GasStationAnio 		= paramNodoOrigen->GasStationAnio ;
	paramNodoDestino->GasStationMes 		= paramNodoOrigen->GasStationMes ;
	paramNodoDestino->GasStationDia 		= paramNodoOrigen->GasStationDia ;
	paramNodoDestino->GasStationDiesel 		= paramNodoOrigen->GasStationDiesel ;
	paramNodoDestino->GasStationRegular 	= paramNodoOrigen->GasStationRegular ;
	paramNodoDestino->GasStationSuper 		= paramNodoOrigen->GasStationSuper ;

	return paramNodoDestino ;
}




// Descripción: Crea un nuevo nodo
// Parametro entrada: el valor llave a guardar dentro del nodo
// Devuelve la instancia de un objeto nodo
nodeGasStation *nodoNuevo(nodeGasStation *paramNewGasStation) {
	nodeGasStation *nodoTemporal = new nodeGasStation();
	//nodoTemporal->GasStationID = paramLlave;

	nodoTemporal = setNodeData(paramNewGasStation, nodoTemporal);
	nodoTemporal->nodoIzquierda = NULL;
	nodoTemporal->nodoDerecha = NULL;
	nodoTemporal->altura = 1;
	return (nodoTemporal);
}



// Descripción: Rota un nodo hacia la derecha
// Parametro entrada: objeto de clase nodo
// Devuelve un nodo rotado hacia la derecha
nodeGasStation *rotarDerecha(nodeGasStation *paramNodo) {
	nodeGasStation *nodoTemporal1 = paramNodo->nodoIzquierda;
	nodeGasStation *nodoTemporal2 = nodoTemporal1->nodoDerecha;
	nodoTemporal1->nodoDerecha = paramNodo;
	paramNodo->nodoIzquierda = nodoTemporal2;
	//Recalcula la altura del nodo que fue enviado por parametro
	alturaNodoIzquierda= calculaAltura(paramNodo->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(paramNodo->nodoDerecha)  ;
	paramNodo->altura = max(alturaNodoIzquierda, alturaNodoDerecha) + 1;
	//Recalculan la altura del nodo que es devuelto
	alturaNodoIzquierda= calculaAltura(nodoTemporal1->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(nodoTemporal1->nodoDerecha)  ;
	nodoTemporal1->altura = max(alturaNodoIzquierda, alturaNodoDerecha) + 1;

	return nodoTemporal1;
}



// Descripción: Rota un nodo hacia la izquierda
// Parametro entrada: objeto de clase nodo
// Devuelve un nodo rotado hacia la izquierda
nodeGasStation *rotarIzquierda(nodeGasStation *paramNodo) {
	nodeGasStation *nodoTemporal1 = paramNodo->nodoDerecha;
	nodeGasStation *nodoTemporal2 = nodoTemporal1->nodoIzquierda;
	nodoTemporal1->nodoIzquierda = paramNodo;
	paramNodo->nodoDerecha = nodoTemporal2;
	//Recalcula la altura del nodo que fue enviado por parametro
	alturaNodoIzquierda= calculaAltura(paramNodo->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(paramNodo->nodoDerecha)  ;
	paramNodo->altura = max(alturaNodoIzquierda, alturaNodoDerecha) + 1;
	//Recalculan la altura del nodo que es devuelto
	alturaNodoIzquierda= calculaAltura(nodoTemporal1->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(nodoTemporal1->nodoDerecha)  ;
	nodoTemporal1->altura = max(alturaNodoIzquierda, alturaNodoDerecha) + 1;

	return nodoTemporal1;
}



// Descripción: Obtiene el factor de balanceo de un nodo
// Parametro entrada: objeto de clase nodo
// Devuelve el valor de balanceo de un nodo podria ser 0, 1, 2, etc...
int obtenerFactorDeBalanceo(nodeGasStation *paramNodo) {
	if (paramNodo == NULL)
		return 0;
	return calculaAltura(paramNodo->nodoIzquierda) -
	       calculaAltura(paramNodo->nodoDerecha);
}



// Descripción: Inserta un nodo en el arbol AVL
// Parametro entrada: objeto de clase nodo y un numero de llave
// Devuelve un nodo
nodeGasStation *insertaNodo(nodeGasStation *paramNodo, nodeGasStation *paramNewGasStation) {
	if (paramNodo == NULL)
		return (nodoNuevo(paramNewGasStation));
	if (paramNewGasStation->GasStationID < paramNodo->GasStationID)
		paramNodo->nodoIzquierda = insertaNodo(paramNodo->nodoIzquierda, paramNewGasStation);
	else if (paramNewGasStation->GasStationID > paramNodo->GasStationID)
		paramNodo->nodoDerecha = insertaNodo(paramNodo->nodoDerecha, paramNewGasStation);
	else
		return paramNodo;

	alturaNodoIzquierda= calculaAltura(paramNodo->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(paramNodo->nodoDerecha)  ;
	paramNodo->altura = max(alturaNodoIzquierda, alturaNodoDerecha) + 1;
	int balanceFactor = obtenerFactorDeBalanceo(paramNodo);
	if (balanceFactor < -1) {
		if (paramNewGasStation->GasStationID > paramNodo->nodoDerecha->GasStationID) {
			return rotarIzquierda(paramNodo);
		} else if (paramNewGasStation->GasStationID < paramNodo->nodoDerecha->GasStationID) {
			paramNodo->nodoDerecha = rotarDerecha(paramNodo->nodoDerecha);
			return rotarIzquierda(paramNodo);
		}
	}
	if (balanceFactor > 1) {
		if (paramNewGasStation->GasStationID < paramNodo->nodoIzquierda->GasStationID) {
			return rotarDerecha(paramNodo);
		} else if (paramNewGasStation->GasStationID > paramNodo->nodoIzquierda->GasStationID) {
			paramNodo->nodoIzquierda = rotarIzquierda(paramNodo->nodoIzquierda);
			return rotarDerecha(paramNodo);
		}
	}

	return paramNodo;
}



// Descripción: Busca el nodo con el valor más pequeño
// Parametro entrada: objeto de clase nodo
// Devuelve el nodo más a la izquierda
// es decir el que tenga el valor más pequeño.
nodeGasStation *nodoMasPequenio(nodeGasStation *paramNodo) {
	nodeGasStation *nodoActual = paramNodo;
	while (nodoActual->nodoIzquierda != NULL)
		nodoActual = nodoActual->nodoIzquierda;
	return nodoActual;
}



// Descripción: Busca el nodo con la llave enviada
// Parametro entrada: objeto de clase nodo y la llave a eliminar
// Devuelve el arbol sin el nodo eliminado
nodeGasStation *eliminaNodo(nodeGasStation *root, int GasStationID) {
	// Busca el nodo y lo borra
	if (root == NULL)
		return root;
	if (GasStationID < root->GasStationID)
		root->nodoIzquierda = eliminaNodo(root->nodoIzquierda, GasStationID);
	else if (GasStationID > root->GasStationID)
		root->nodoDerecha = eliminaNodo(root->nodoDerecha, GasStationID);
	else {
		if ((root->nodoIzquierda == NULL) ||
		        (root->nodoDerecha == NULL)) {
			nodeGasStation *temp = root->nodoIzquierda ? root->nodoIzquierda : root->nodoDerecha;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else
				*root = *temp;
			free(temp);
		} else {
			nodeGasStation *temp = nodoMasPequenio(root->nodoDerecha);
			//ASIGNA OTROS CAMPOS
			//root->GasStationID = temp->GasStationID;
			root = setNodeData(temp, root) ;
			root->nodoDerecha = eliminaNodo(root->nodoDerecha, GasStationID);
		}
	}

	if (root == NULL)
		return root;

	// Actualiza el factor de balance y recalcula el arbol
	alturaNodoIzquierda= calculaAltura(root->nodoIzquierda);
	alturaNodoDerecha  = calculaAltura(root->nodoDerecha)  ;
	root->altura = 1 + max(alturaNodoIzquierda, alturaNodoDerecha);
	int balanceFactor = obtenerFactorDeBalanceo(root);
	if (balanceFactor > 1) {
		if (obtenerFactorDeBalanceo(root->nodoIzquierda) >= 0) {
			return rotarDerecha(root);
		} else {
			root->nodoIzquierda = rotarIzquierda(root->nodoIzquierda);
			return rotarDerecha(root);
		}
	}
	if (balanceFactor < -1) {
		if (obtenerFactorDeBalanceo(root->nodoDerecha) <= 0) {
			return rotarIzquierda(root);
		} else {
			root->nodoDerecha = rotarDerecha(root->nodoDerecha);
			return rotarIzquierda(root);
		}
	}
	return root;
}



string lefPadTo(std::string &str, const size_t num, const char paddingChar = ' ') {
	if(num > str.size())
		str.insert(0, num - str.size(), paddingChar);

	return str;
}

string padTo(std::string &str, const size_t num, const char paddingChar = ' ') {
	if(num > str.size())
		str.append(num - str.length() - 1, paddingChar);
	//str.insert(0, num - str.size(), paddingChar);

	return str;
}




int obtieneEnteroValido(string nameField) {
	int responseValue=0;

	//printf("\nIngrese %s de la gasolinera:\n", nameField);
	cout << "\nIngrese " << nameField << " de la gasolinera:\n" << endl;

	scanf("%d", &responseValue);

	return responseValue ;
}



string obtieneCadenaDeCaracteresValido(string nameField) {
	string responseValue;

	//printf("\nIngrese %s de la gasolinera:\n", nameField);
	//scanf("%s", &responseValue);
	//cout << "\nIngrese " << nameField << " de la gasolinera:\n" << endl;
	//cin >> responseValue ;
	
	cout << "\nIngrese "<<nameField << " de la gasolinera: " << endl ;
	//getline(std::cin, responseValue);
	cin >> responseValue ;

	cout << "\nIngrese "<<nameField << " de la gasolinera: " << endl ;
	cout << "\nIngrese "<<nameField << " de la gasolinera: " << endl ;
	cout << "\nIngrese "<<nameField << " de la gasolinera: " << endl ;

	return responseValue ;
}



double obtieneNumeroDobleValido(string nameField) {
	double responseDoubleValue=0.00;

	//printf("\nIngrese %s de la gasolinera:\n", nameField);
	cout << "\nIngrese " << nameField << " de la gasolinera:\n" << endl;
	scanf("%lf", &responseDoubleValue);

	return responseDoubleValue ;
}












// Descripción: reporte de informacion enviado a consola
// Parametro entrada: raiz del arbol
void escribeDetalle(nodeGasStation *nodoDetalle) {

	printf("%d |%s |%s |%s |%d |   %.2f |   %.2f |%d |%d |%d |   %.2f |   %.2f |   %.2f\n",
	       nodoDetalle->GasStationID,
	       padTo(nodoDetalle->GasStationName, 15).c_str(),
	       padTo(nodoDetalle->GasStationDepartamento, 5).c_str(),
	       padTo(nodoDetalle->GasStationMunicipio, 10).c_str(),
	       nodoDetalle->GasStationZona,
	       nodoDetalle->GasStationLatitud,
	       nodoDetalle->GasStationLongitud,
	       nodoDetalle->GasStationAnio,
	       nodoDetalle->GasStationMes,
	       nodoDetalle->GasStationDia,
	       nodoDetalle->GasStationDiesel,
	       nodoDetalle->GasStationRegular,
	       nodoDetalle->GasStationSuper ) ;

}



// Descripción: Imprime el arbol en consola
// Parametro entrada: objeto de clase nodo
// Devuelve en consola el arbol dibujado
bool buscarNodo(nodeGasStation *root, bool last, int opcionDeBusqueda, int valorEntero, string valorStr) {

	if (root != nullptr) {
		if (!seEncontroLlave) {
			root->GasStationDepartamento = trim(root->GasStationDepartamento) ;
			valorStr = trim(valorStr) ;
			switch(opcionDeBusqueda) {
				case 1:
					//Departamento
					//if (root->GasStationDepartamento==valorStr) {
					//if (strcmp(root->GasStationDepartamento, valorStr)==0) {
					if (root->GasStationDepartamento.compare(valorStr)==0) {
						seEncontroLlave = true;
					}

					break;
				case 2:
					//Municipio
					//if (root->GasStationMunicipio==valorStr) {
					//if (strcmp(root->GasStationMunicipio, valorStr)==0) {
					if (root->GasStationMunicipio.compare(valorStr)==0) {
						seEncontroLlave = true;
					}
					break;
				case 3:
					//Zona
					if (root->GasStationZona==valorEntero) {
						seEncontroLlave = true;
					}
					break;

				default:
					opcionDeBusqueda=0;
					break;
			}

			if(seEncontroLlave) {
				escribeDetalle(root);
				seEncontroLlave = false;
			}

			seEncontroLlave = buscarNodo(root->nodoIzquierda, false, opcionDeBusqueda, valorEntero, valorStr);
			seEncontroLlave = buscarNodo(root->nodoDerecha, true, opcionDeBusqueda, valorEntero, valorStr);
		}
	}
	return seEncontroLlave;
}





void Encabezado() {
	system("cls");

	printf("\n%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s",
	       "ID",
	       "Nombre        ",
	       "Dep.",
	       "Municipio",
	       "Zona",
	       "Latitud",
	       "Longitud",
	       "Anio",
	       "Mes",
	       "Dia",
	       "Diesel",
	       "Regular",
	       "Super" ) ;
	printf("\n------------------------------------------------------------------------------------------------------\n") ;


}





bool buscarNodoPideData(nodeGasStation *root, bool last, int opcionDeBusqueda) {
	bool pideDatos=false;
	system("cls");
	int enteroIngresadoPorElUsuario = 0;
	string strIngresadoPorElUsuario = "";

	//Paso 1, pedimos llave al usuario
	printf("%s","***** BUSCA DATOS *****\n");
	switch(opcionDeBusqueda) {
		case 1:
			//Departamento
			strIngresadoPorElUsuario	= obtieneCadenaDeCaracteresValido("departamento (ubicacion)");
			//strIngresadoPorElUsuario	= "GT";
			break;
		case 2:
			//Municipio
			strIngresadoPorElUsuario	= obtieneCadenaDeCaracteresValido("municipio (ubicacion)");
			//strIngresadoPorElUsuario	= "GT";
			break;
		case 3:
			//Zona
			enteroIngresadoPorElUsuario	= obtieneEnteroValido("zona (ubicacion)");
			//enteroIngresadoPorElUsuario	= 6;
			break;

		default:
			opcionDeBusqueda=0;
			break;
	}

	Encabezado();
	seEncontroLlave = false ;
	seEncontroLlave = buscarNodo(root, true, opcionDeBusqueda, enteroIngresadoPorElUsuario, strIngresadoPorElUsuario);

	if(seEncontroLlave) {
		printf("SI SE ENCONTRO !!!\n");
	} else {
		printf("ERROR AL BUSCAR, NO SE ENCONTRO !!!\n");
	}

	getch();
	pideDatos = true;
	return pideDatos ;
}




void busca(nodeGasStation *root) {

	int opcionDeBusqueda=0;
	while(opcionDeBusqueda != 4) {
		system("cls");
		printf("%s\n","1.Departamento");
		printf("%s\n","2.Municipio");
		printf("%s\n","3.Zona");
		printf("%s\n","4.Salir de la busqueda");
		printf("%s\n","Seleccione una opcion");
		scanf("%d", &opcionDeBusqueda);

		switch(opcionDeBusqueda) {
			case 1:
				seEncontroLlave = buscarNodoPideData(root, true, opcionDeBusqueda);
				break;
			case 2:
				seEncontroLlave = buscarNodoPideData(root, true, opcionDeBusqueda);
				break;
			case 3:
				seEncontroLlave = buscarNodoPideData(root, true, opcionDeBusqueda);
				break;
			case 4:
				break;

			default:
				printf("%s\n","4.Salir");
				//getch();
				opcionDeBusqueda=0;
				break;
		}
	}

}




// Descripción: Imprime el arbol en consola
// Parametro entrada: objeto de clase nodo
// Devuelve en consola el arbol dibujado
void imprimirEnConsola(nodeGasStation *root, string indent, bool last) {
	if (root != nullptr) {
		cout << indent;
		if (last) {
			if(esRaiz == 0) {
				cout << "Raiz---";
				esRaiz = 1;
			} else {
				cout << "Der(->)----";
			}
			indent += "   ";
		} else {
			cout << "Izq(<-)----";
			indent += "|  ";
		}
		cout << root->GasStationID << endl;
		imprimirEnConsola(root->nodoIzquierda, indent, false);
		imprimirEnConsola(root->nodoDerecha, indent, true);
	}
}




void imprimeEnConsola(nodeGasStation *root) {
	esRaiz = 0 ;
	imprimirEnConsola(root, "", true);
}





// Descripción: reporte de informacion enviado a consola
// Parametro entrada: raiz del arbol
void reporteInfo(nodeGasStation *root, string indent, bool last) {
	if (root != nullptr) {

		escribeDetalle(root);
		/*
				printf("%d |%s |%s |%s |%d |   %.2f |   %.2f |%d |%d |%d |   %.2f |   %.2f |   %.2f\n",
				       root->GasStationID,
				       padTo(root->GasStationName, 15).c_str(),
				       padTo(root->GasStationDepartamento, 5).c_str(),
				       padTo(root->GasStationMunicipio, 10).c_str(),
				       root->GasStationZona,
				       root->GasStationLatitud,
				       root->GasStationLongitud,
				       root->GasStationAnio,
				       root->GasStationMes,
				       root->GasStationDia,
				       root->GasStationDiesel,
				       root->GasStationRegular,
				       root->GasStationSuper ) ;
		*/
		reporteInfo(root->nodoIzquierda, indent, false);
		reporteInfo(root->nodoDerecha, indent, true);
	}
}




//Genera el reporte de informacion
void ReporteDeInformacion(nodeGasStation *root) {
	esRaiz = 0 ;
	//Encabezado
	Encabezado();
	/*
	system("cls");

	printf("\n%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s |%s",
	       "ID",
	       "Nombre        ",
	       "Dep.",
	       "Municipio",
	       "Zona",
	       "Latitud",
	       "Longitud",
	       "Anio",
	       "Mes",
	       "Dia",
	       "Diesel",
	       "Regular",
	       "Super" ) ;
	printf("\n------------------------------------------------------------------------------------------------------\n") ;
	*/
	reporteInfo(root, "", true);
	getch();
}


nodeGasStation *Demo(nodeGasStation *root) {

	nodeGasStation *nuevaGasolinera = new nodeGasStation() ;

	nuevaGasolinera->GasStationDepartamento	= "GT" ;
	nuevaGasolinera->GasStationZona 		= 6 ;
	nuevaGasolinera->GasStationAnio 		= 2022 ;
	nuevaGasolinera->GasStationMes 			= 6 ;
	nuevaGasolinera->GasStationDia 			= 5 ;

	//SANARATECA
	nuevaGasolinera->GasStationID 			= 10 ;
	nuevaGasolinera->GasStationName 		= "Sanarateca" ;
	nuevaGasolinera->GasStationMunicipio 	= "Chinautla" ;
	nuevaGasolinera->GasStationLatitud 		= 6.26 ;
	nuevaGasolinera->GasStationLongitud 	= 26.6 ;
	nuevaGasolinera->GasStationDiesel 		= 15.15 ;
	nuevaGasolinera->GasStationRegular 		= 23.40 ;
	nuevaGasolinera->GasStationSuper 		= 25.40 ;
	root = insertaNodo(root, nuevaGasolinera);
	//TEXACO
	nuevaGasolinera->GasStationID 			= 20 ;
	nuevaGasolinera->GasStationName 		= "Texaco" ;
	nuevaGasolinera->GasStationLatitud 		= nuevaGasolinera->GasStationLatitud * 3 ;
	nuevaGasolinera->GasStationLongitud 	= nuevaGasolinera->GasStationLongitud * 3 ;
	nuevaGasolinera->GasStationDiesel 		= nuevaGasolinera->GasStationDiesel * 4 ;
	nuevaGasolinera->GasStationRegular 		= nuevaGasolinera->GasStationRegular * 4 ;
	nuevaGasolinera->GasStationSuper 		= nuevaGasolinera->GasStationSuper * 4 ;
	root = insertaNodo(root, nuevaGasolinera);
	//PUMA
	nuevaGasolinera->GasStationID 			= 30 ;
	nuevaGasolinera->GasStationName 		= "Puma" ;
	nuevaGasolinera->GasStationLatitud 		= 3.33 ;
	nuevaGasolinera->GasStationLongitud 	= 3.33 ;
	nuevaGasolinera->GasStationDiesel 		= 20.15 ;
	nuevaGasolinera->GasStationRegular 		= 29.30 ;
	nuevaGasolinera->GasStationSuper 		= 30.30 ;
	root = insertaNodo(root, nuevaGasolinera);


	//SHELL ZONA 2
	root = insertaNodo(root, nuevaGasolinera);
	nuevaGasolinera->GasStationID 			= 40 ;
	nuevaGasolinera->GasStationName 		= "Shell Z2" ;
	nuevaGasolinera->GasStationMunicipio 	= "GT" ;
	nuevaGasolinera->GasStationZona 		= 2 ;
	nuevaGasolinera->GasStationLatitud 		= 50.50 ;
	nuevaGasolinera->GasStationLongitud 	= 50.50 ;
	nuevaGasolinera->GasStationDiesel 		= 50.50 ;
	nuevaGasolinera->GasStationRegular 		= 50.50 ;
	nuevaGasolinera->GasStationSuper 		= 50.50 ;
	root = insertaNodo(root, nuevaGasolinera);
	//SHELL MAJADAS
	nuevaGasolinera->GasStationID 			= 50 ;
	nuevaGasolinera->GasStationName 		= "Shell Majadas" ;
	nuevaGasolinera->GasStationMunicipio 	= "GT" ;
	nuevaGasolinera->GasStationLatitud 		= 9.99 ;
	nuevaGasolinera->GasStationLongitud 	= 9.99 ;
	nuevaGasolinera->GasStationDiesel 		= 99.99 ;
	nuevaGasolinera->GasStationRegular 		= 99.99 ;
	nuevaGasolinera->GasStationSuper 		= 99.99 ;
	root = insertaNodo(root, nuevaGasolinera);

	//TEXACO ZONA 18
	root = insertaNodo(root, nuevaGasolinera);
	nuevaGasolinera->GasStationID 			= 18 ;
	nuevaGasolinera->GasStationName 		= "TEXACO ZONA 18" ;
	nuevaGasolinera->GasStationMunicipio 	= "GT" ;
	nuevaGasolinera->GasStationZona 		= 18 ;
	nuevaGasolinera->GasStationLatitud 		= 18.18 ;
	nuevaGasolinera->GasStationLongitud 	= 18.18 ;
	nuevaGasolinera->GasStationDiesel 		= 18.18 ;
	nuevaGasolinera->GasStationRegular 		= 18.18 ;
	nuevaGasolinera->GasStationSuper 		= 18.18 ;
	root = insertaNodo(root, nuevaGasolinera);
	//PUMA KERNS
	nuevaGasolinera->GasStationID 			= 48 ;
	nuevaGasolinera->GasStationName 		= "Puma KERNS" ;
	nuevaGasolinera->GasStationLatitud 		= 48.48 ;
	nuevaGasolinera->GasStationLongitud 	= 148.48 ;
	nuevaGasolinera->GasStationDiesel 		= 22.22 ;
	nuevaGasolinera->GasStationRegular 		= 48.50 ;
	nuevaGasolinera->GasStationSuper 		= 52.50 ;
	root = insertaNodo(root, nuevaGasolinera);
	//TEXACO PARAISO
	nuevaGasolinera->GasStationID 			= 58 ;
	nuevaGasolinera->GasStationName 		= "TEXACO PARAISO" ;
	nuevaGasolinera->GasStationLatitud 		= 23.33 ;
	nuevaGasolinera->GasStationLongitud 	= 31.33 ;
	nuevaGasolinera->GasStationDiesel 		= 30.15 ;
	nuevaGasolinera->GasStationRegular 		= 38.30 ;
	nuevaGasolinera->GasStationSuper 		= 39.30 ;
	root = insertaNodo(root, nuevaGasolinera);
	//SHELL PARAISO
	nuevaGasolinera->GasStationID 			= 78 ;
	nuevaGasolinera->GasStationName 		= "SHELL PARAISO" ;
	nuevaGasolinera->GasStationLatitud 		= 33.33 ;
	nuevaGasolinera->GasStationLongitud 	= 81.33 ;
	nuevaGasolinera->GasStationDiesel 		= 90.15 ;
	nuevaGasolinera->GasStationRegular 		= 98.30 ;
	nuevaGasolinera->GasStationSuper 		= 99.30 ;
	root = insertaNodo(root, nuevaGasolinera);

	return root ;
	/*
	esRaiz = 0 ;
	imprimeEnConsola(root);
	root = eliminaNodo(root, 13);
	cout << "After deleting " << endl;
	imprimeEnConsola(root);
	*/

}








//Solicita información en pantalla y
//agrega al arbol
nodeGasStation *insertar(nodeGasStation *paramNodo) {

	system("cls");
	nodeGasStation *nuevaGasolinera = new nodeGasStation() ;
	//Paso 1, pedimos informacion al usuario
	printf("%s","***** INGRESO DE DATOS *****\n");
	nuevaGasolinera->GasStationID 			= obtieneEnteroValido("ID");
	nuevaGasolinera->GasStationName 		= obtieneCadenaDeCaracteresValido("nombre");
	nuevaGasolinera->GasStationDepartamento	= obtieneCadenaDeCaracteresValido("departamento (ubicacion)");
	nuevaGasolinera->GasStationMunicipio 	= obtieneCadenaDeCaracteresValido("municipio (ubicacion)");
	nuevaGasolinera->GasStationZona 		= obtieneEnteroValido("zona (ubicacion)");
	nuevaGasolinera->GasStationLatitud 		= obtieneNumeroDobleValido("latitud (geolocalizacion)");
	nuevaGasolinera->GasStationLongitud 	= obtieneNumeroDobleValido("longitud (geolocalizacion)");
	nuevaGasolinera->GasStationAnio 		= obtieneEnteroValido("anio");
	nuevaGasolinera->GasStationMes 			= obtieneEnteroValido("mes");
	nuevaGasolinera->GasStationDia 			= obtieneEnteroValido("dia");
	nuevaGasolinera->GasStationDiesel 		= obtieneNumeroDobleValido("precio diesel");
	nuevaGasolinera->GasStationRegular 		= obtieneNumeroDobleValido("precio gasolina regular");
	nuevaGasolinera->GasStationSuper 		= obtieneNumeroDobleValido("precio gasolina super");

	return insertaNodo(paramNodo, nuevaGasolinera) ;
}














//Se busca una llave dentro del arbol
bool buscar() {
	bool seBusca = false;



	return seBusca ;
}


//Se elimina una llave dentro del arbol
nodeGasStation *eliminar(nodeGasStation *paramNodo) {
	system("cls");
	int llaveIngresadaPorElUsuario = 0;

	//Paso 1, pedimos llave al usuario
	printf("%s","***** ELIMINAR DATOS *****\n");
	printf("%s","\nIngrese llave:\n");
	scanf("%d", &llaveIngresadaPorElUsuario);

	return eliminaNodo(paramNodo, llaveIngresadaPorElUsuario) ;
}





//Se imprime el arbol que se tiene en este momento
bool Recorrido(nodeGasStation *paramNodo) {
	bool seRecorrio = false;

	system("cls");
	printf("%s","***** DIBUJANDO EL ARBOL *****\n");

	esRaiz = 0 ;
	imprimeEnConsola(paramNodo);
	getch();

	return seRecorrio ;
}



//Se imprime el arbol que se tiene en este momento usando GraphViz
bool RecorridoMejorado() {
	bool seRecorrio = false;



	return seRecorrio ;
}












int main() {

	nodeGasStation *raiz = NULL;

	int opcion=0;
	while(opcion != 5) {
		system("cls");
		printf("%s\n","1.Ingresar información");
		printf("%s\n","2.Consultar información");
		printf("%s\n","3.Reporte de información");
		printf("%s\n","4.Llenar información predeterminada (demo)");
		printf("%s\n","5.Salir");
		printf("%s\n","Seleccione una opcion");
		scanf("%d", &opcion);

		switch(opcion) {
			case 1:
				raiz = insertar(raiz);
				break;
			case 2:
				busca(raiz);
				break;
			case 3:
				ReporteDeInformacion(raiz);
				break;
			case 4:
				raiz = Demo(raiz);
				break;
			case 5:
				break;

			default:
				printf("%s\n","6.Salir");
				//getch();
				opcion=0;
				break;
		}
	}

	return 0;
}

