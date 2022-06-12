/*
 * arrayPassenger.h
 *
 ============================================================================

 ALUMNO      : Serrano Belloso Sebastian
 DNI         : 42810404
 DIVISION	 : K-1

 LABORATORIO DE PROGRAMACION 1
 TRABAJO PRACTICO N-2
 UTN-FRA -- 2022 --
 ============================================================================
 */


#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


//===========  DEFINES  ============
//IsEmpty
#define OCCUPIED 1
#define REMOVED -1
#define EMPTY 0

//flightStatus
#define ACTIVE 1
#define CANCELED -1
#define DELAYED 0

//elementos de estructura
#define MAX_PASSENGERS 1999
#define MAX_FLIGHTS 3

//==========  ENTIDADES  ==========

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;

}sPassenger;


typedef struct{
	char flycode[12];
	int flightStatus;

}sFlight;

//========== FUNCIONES PEDIDAS POR LA CATEDRA ===========
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(sPassenger list[], int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok

*/
int addPassenger(sPassenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger[]
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger[]
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(sPassenger list[], int len, int id);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersBySurname(sPassenger list[], int len, int order);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN

Programación I – Laboratorio I

UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 7
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByFlightCode(sPassenger list[], int len, int order);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger[]
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(sPassenger list[], int len, int id);

#endif /* ARRAYPASSENGER_H_ */
