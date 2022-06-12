/*
 * funcionesAlumno.h
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


#ifndef FUNCIONESALUMNO_H_
#define FUNCIONESALUMNO_H_

//========== FUNCIONES ALUMNO ==========

//==========  MENU  ==========
/**
 * @brief prints text menu and returns oprtion selected by the user
 * @param min min option
 * @param max max option
 * @param text to be printed as body of the menu
 * @return returns
 */
int menu(int min, int max, char text[]);

//==========  ENTIDAD  ==========

/**
 * @brief loads and saves one element of sPassenger array
 * @param list sPassenger array
 * @param len array lenght
 * @param idPassenger unique id of passenger to be loaded in sPassenger element
 * @return if list is NULL or lenght is < 1 returns -1, else, returns 0
 */
int add(sPassenger list[], int len, int idPassenger);

/**
 * @brief asks and loads data in an sPassenger variable, returns the sPassenger variable,
 * @return returns an sPassenger variable with the fields loaded.
 */
sPassenger loadPassenger(void);

/**
 * @brief Ask sPassenger ID to the user, ask confirmations for removing matching ID element, if its confirmed, isEmpty FIELD of sPassenger element is set to REMOVED(logic delet).
 * @param passengerList sPassenger array
 * @param passengerLen lenght of sPassenger array
 * @param flightList sFlight array
 * @param flightLen lenght of sFlight array
 * @return if passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen > 0 && there is at least one element OCCUPIED(loaded) in sPassenger array && remove is confirmed it returns 0(ok), else, returns -1
 */
int removeOption(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);

/**
 * @brief	Ask sPassenger ID to the user and modify's matching id sPassenger element, in the field the user chooses.
 * @param passengerList sPassenger array
 * @param passengerLen lenght of sPassenger array
 * @param flightList sFlight array
 * @param flightLen lenght of sFlight array
 * @return if passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen && and there is at least one element OCCUPIED(loaded) in sPassenger array, returns 0(OK), else, returns -1
 */
int modifyPassenger(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);


/**
 * @brief load's 5 pre-defined sPassenger elements.
 * @param passengerList sPassenger array
 * @param passengerLenght sPassenger array lenght
 * @param idPassenger id correspondent to sPassenger ID field.
 * @return if passengerList != NULL && passengerLenght > 0 && there is available space(EMPTY) in sPassenger array returns 0(ok), else, returns -1.
 */
int forcedEntry(sPassenger passengerList[], int passengerLenght, int idPassenger);

/**
 * @brief runs through sPassenger array searching for 5 EMPTY(not loaded) elements.
 * @param passengerList sPassenger array
 * @param passengerLenght sPassenger array lenght
 * @return if 5 elements of sPassenger array are EMPTY(not loaded), returns 0(ok), else, returns -1
 */
int freeSlot(sPassenger passengerList[], int passengerLenght);

/**
 * @brief loads pre-defined fields in 5 elements of sPassenger array.
 * @param list sPassenger array
 * @param lenght lenght of sPassenger array
 * @param idPassenger idPassenger to be matched with ID field of sPassenger element
 * @return if list != NULL && idPassenger > 0 returns 0(ok), else, returns -1.
 */
int autoLoad(sPassenger list[], int lenght, int idPassenger);

/**
 *@brief hardcode's 3 sFlight elements , givin values in every field
 * @param list	sFlight array
 * @param len array lenght
 *
 * @return if list != NULL && lenght > 0 returns 0, else, returns -1
 */
int initFlights(sFlight list[], int len);
//==========  GET/FIND ENTIDAD  ==========

/**
 * @brief Ask's the user for an ID(field of sPassenger), if it exists, it returns the index of id.
 * @param passengerList[] sPassenger array
 * @param passengerLen lenght of sPassenger array
 *
 * @return if ID(field of sPassenger) entered by the user exists in a OCCUPIED(loaded) element of sPassenger array, it returns the index, else, returns -1
 */
int getIdPassenger(sPassenger passengerList[], int passengerLen);

/**
 * @brief prints sPassenger element and ask's the user for confirmation(IS array or NOT).
 * @param passenger[] sPassenger element
 * @param list	sFlight array
 * @param len lenght of sFlight array
 * @param text text to be printed in console
 * @return returns option selected by the user
 */
char isId(sPassenger passenger, sFlight list[], int len, char text[]);



/**
 * @brief ask's sPassenger ID to the user, if ID matches with an OCCUPIED(loaded) element of sPassenger array, it returns the matching ID.
 * @param passengerList sPassenger array
 * @param passengerLen lenght of sPassenger array
 * @return if ID entered by the user matches OCCUPIED(loaded) element of sPassenger array, returns ID, else, returns -1
 */
int getId(sPassenger passengerList[], int passengerLen);

/**
 * @brief Shows flight codes available in console, ask's the user to select one and saves it.
 * @param flyCode char array where flight code is loaded
 * @return if array != NULL returns 0, else, returns -1
 */
int getFlycode(char flyCode[]);

/**
 * @brief shows types of passenger's available in console, ask's the user to select one and returns the option.
 * @return returns option selected by the user.
 */
int getTypePassenger(void);

/**
 * @brief runs through sPassenger array searching for an EMPTY(NOT LOADED) element, if it finds it, returns the index.
 * @param list[] sPassenger array
 * @param len lenght of array
 * @return returns the index of an EMPTY element of the array, else, if array is NULL , lenght < 1 or no EMPTY element returns -1
 */
int findEmptySlot(sPassenger list[], int len);

/**
 * @brief runs through the sPassenger array searching for an OCCUPIED(loaded) element, if it finds one, breaks cycle and returns 0(ok)
 * @param list sPassenger array
 * @param len lenght of array
 * @return if list is NULL, len < 1 or no OCCUPIED(LOADED) element's existing in list returns -1, else, returns 0;
 */
int isEmpty(sPassenger list[], int len);


//==========  PRINT  ==========

/**
 * @brief  prints calculations, lists and reports using sPassenger && sFlight array's data, the user chooses list format to be printed or calculation required
 * @param passengerList sPassenger array
 * @param passengerLen lenght of sPassenger array
 * @param flightList sFlight array
 * @param flightlen sFlight array lenght
 * @return if passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen > 0 && the is at least one element OCCUPIED(loaded) in sPassenger array, returns 0(ok), else, returns -1
 */
int printMenu(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightlen);

/**
 * @brief prints sPassenger array by Surname && type passenger, with format choosed by the user.
 * @param passengerList sPassenger array
 * @param passengerlength sPassenger array lenght
 * @param flightList sFlight array
 * @param flightLen lenght of sFlight array
 * @return if passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0 returns 0(ok), else, returns -1.
 */
int printBySurname(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);

/**
 * @brief prints sPassenger array by flight code && flightStatus, with format choosed by the user.
 * @param passengerList sPassenger array
 * @param passengerlength sPassenger array lenght
 * @param flightList sFlight array
 * @param flightLen sFlight array lenght
 * @return ifpassengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0 returns 0(ok), else, returns -1.
 */
int printByFlightCode(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);

/**
 * @brief Calculates and prints amounts, averages y counters with sPassernger array data.
 * @param passengerList sPassenger array
 * @param passengerlength lenght of sPassenger array
 * @param flightList sFlight array
 * @param flightLen lenght of sFlight array
 * @return if passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0 returns 0(ok), else, returns -1
 */
int printPriceCalculus(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);

/**
 * @brief prints one sPassenger element in console.
 * @param passenger sPassenger element
 * @param flights sFlight array
 * @param len lenght of sFlight array
 * @return if flight is NULL or lenght < 1 returns -1, else, returns 0.
 */
int printPassenger(sPassenger passenger, sFlight flights[], int len);

/**
 * @brief prints typePassenger of one sPassenger element in console
 * @param passenger sPassenger element
 */
void printTypePassenger(sPassenger passenger);

/**
 * @brief prints the flightStatus of one sPassenger element in console.
 * @param passenger sPassenger element
 * @param list sFlight array
 * @param len lenght of sFlight array
 */
void printFlightStatus(sPassenger passenger, sFlight list[], int len);

//=========  GETTERS/VALIDACIONES  ==========

/**
 * @brief Ask's to the user, validates and loads array of chars(string).
 * @param string array of chars
 * @param lenght max lenght of char array
 * @param text text to be printed as entry instructions for the user
 */
void getString(char string[], int lenght, char text[]);

/**
 * @brief validates emptiness of array of chars(string)
 * @param string array of chars(string)
 * @return if array of chars(string) is empty, returns 0, else, returns 1(ok).
 */
int stringEmpty(char string[]);

/**
 * @brief Validates that the string received is a valid integer number.
 * @param auxInteger array of chars(string)
 * @return if array of chars(string) is a valid integer number returns 1(ok), else, returns 0.
 */
int isInteger(char auxInteger[]);

/**
 * @brief ask's to the user, validates and returns integer.
 * @param min min integer value allowed for entry
 * @param max max integer value allowed for entry
 * @param text text to be printed as entry instructions for the user.
 * @return returns validated integer entered by the user
 */
int getInt(int min, int max, char text[]);

/**
 * @brief Validates that the array of chars(string) is a float number.
 * @param auxFloat array of chars(string)(float)
 * @return if array of chars(string) is a valid float number it returns 1(ok), else, returns 0.
 */
int isFloat(char auxFloat[]);

/**
 * @brief ask's to the user, validates and returns a float number.
 * @param min min float value allowed for entry.
 * @param max max float value allowed for entry.
 * @param text text to be printed as entry instructions for the user.
 * @return returns a validated float number, entered by the user.
 */
float getFloat(float min, float max, char text[]);

/**
 * @brief Ask's to the user and returns a char variable
 * @param text text to be printed as entry instructions for the user
 * @return returns a char variable entered by the user.
 */
char getChar(char text[]);

/**
 * @brief ask's to the user, validates and loads name
 * @param string array of char(string(name)
 * @param lenght max lenght of array of chars(string)
 * @param text text to be printed as entry instructons.
 */
void getName(char string[], int lenght, char text[]);

/**
 * @brief Validates that the array of chars(string) is a name.
 * @param string array of chars(string)
 * @return if array of chars(string) is a valid name it returns 1, else, returns 0.
 */
int isName(char string[]);

#endif /* FUNCIONESALUMNO_H_ */
