#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "funcionesAlumno.h"


int main()
{
	setbuf(stdout, NULL);
	int loadFlag;
	int saveTextFlag;
	int saveBinFlag;
    int option;
    loadFlag = 0;
    saveTextFlag = 0;
    saveBinFlag = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	option = mainMenu();
        switch(option)
        {
            case 1:
            	if(loadFlag == 0){
            		if(controller_loadFromText("data.csv",listaPasajeros) == 0 ){
            			loadFlag = 1;
            		}
            	}
            	else{
            		printf("\nLa lista puede cargarse solo una ves.");
            	}
                break;
            case 2:
            	if(loadFlag == 0){
            		if(controller_loadFromBinary("data.bin", listaPasajeros) == 0){
            			loadFlag = 1;
            		}
            	}
            	else{
            		printf("\nLa lista puede cargarse solo una ves.");
            	}
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	break;
            case 5:
            	controller_removePassenger(listaPasajeros);
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7:
            		controller_sortPassenger(listaPasajeros);
            		break;
            case 8:
            	if(loadFlag == 1){
            		if(controller_saveAsText("data.csv",listaPasajeros) == 0){
            		saveTextFlag = 1;
            		}
            	}
            	else{
            		printf("\nCARGUE LA LISTA DE PASAJEROS ANTES DE GUARDAR.");
            	}
            	break;
            case 9:
            	if(loadFlag == 1){
            		if(controller_saveAsBinary("data.bin", listaPasajeros) == 0){
            		saveBinFlag = 1;
            		}
				}
				else{
					printf("\nCARGUE LA LISTA DE PASAJEROS ANTES DE GUARDAR.");
				}
            	break;
            case 10:
            	if(saveBinFlag == 1 && saveTextFlag == 1){
            		printf("\nHAS SALIDO DEL MENU PRINCIPAL");
            	}
            	else{
            		printf("\nGUARDE ANTES DE SALIR(TEXTO Y BINARIO).");
            	}
            	break;
        }
    }while(option != 10 || saveTextFlag == 0 || saveBinFlag == 0);

    ll_deleteLinkedList(listaPasajeros);

    return 0;
}

