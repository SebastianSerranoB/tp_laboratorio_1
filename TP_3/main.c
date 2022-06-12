#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "funcionesAlumno.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	option = mainMenu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.csv", listaPasajeros);
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 8:

            	//guardar archivo en texto
            	//Si realiza un alta, no puede guardar sin antes haber cargado la lista porque sino esta se sobreescribe solo con los nuevos passengers en alta(perdiendo el resto de la lista)
            	break;
            case 9:
            	//guardar archivo en binario
            	break;
        }
    }while(option != 10);
    return 0;
}

