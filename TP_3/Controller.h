
/**
 * @brief Lee(texto) y carga los datos de los pasajeros en la linkedList Passengers, desde el archivo data.csv
 *
 * @param path 	direccion del archivo que sera leido.
 * @param pArrayListPassenger puntero hacia la estructura LinkedList de pasajeros
 * @return	Si puede leer y cargar los datos de los pasajeros en la estructura, retorna (0), de caso contrario, retorna (-1)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief 	lee(binario) y carga los datos de los pasajeros en la linkedList Passengers, desde el archivo datab.bin
 *
 * @param path direccion del archivo que sera leido
 * @param pArrayListPassenger puntero hacia la estructura LinkedList de pasajeros
 * @return Si puede leer y cargar los datos de los pasajeros en la estructura, retorna (0), de caso contrario, retorna (-1)
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief	Funcion que da de alta un pasajero en la estructura linkedList de pasajeros, pidiendole el ingreso de datos al usuario.
 *
 * @param pArrayListPassenger  puntero hacia la estructura LinkedList de pasajeros
 * @return	Si puede dar de alta un pasajero exitosamente, retorna (0), de no ser asi, retorna(-1)
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Funcion que le permite al usuario modificar un pasajero existente en la linkedList de pasajeros
 *
 * @param pArrayListPassenger	puntero hacia la estructura LinkedList de pasajeros
 * @return	Si el menu de modificacione es desplegado con exito y la opcion retornada es valida, el retorno es (0), de caso contrario, retorna (-1)
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief	Funcion que le permite al usuario dar de baja un pasajero de la linkedList Passengers, si es dado de baja, los datos se guardan en el archivo bajas.txt
 *
 * @param pArrayListPassenger puntero hacia la estructura linkedlist de pasajeros
 * @return	Si el pasajero seleccionado por el usuario existe y su confirmacion sobre la baja es valida, retorna(0), de caso contrario, retorna (-1)
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @brief	Funcion encargada de mostrar listados en consola los pasajeros cargados en la linkedList Passengers
 *
 * @param pArrayListPassenger puntero a la estructura linkedList passengers
 * @return Si la lista es mostrada con exito, retorna (0), de caso contrario retorna (-1)
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Funcion encargada de ordenar los indices de la lista de pasajeros por determinado criterio(nombre, apellido, precio, id)
 *
 * @param pArrayListPassenger puntero a la estructura LinkedList de pasajeros
 * @return Si la lista es ordenada exitosamente, retorna (0), de caso contrario retorna (-1)
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief	Funcion encargada de guardar los datos de la estructura linkedList pasajeros en un archivo de texto csv
 *
 * @param path direccion de el archivo donde se guardaran los datos
 * @param pArrayListPassenger puntero a la estructura linkedList de pasajeros
 * @return si la lista es guardada con exito, retorna (0), de caso contrario, retorna (-1)
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief 	Funcion encargada de guardar los datos de la estructura linkedList pasajeros en un archivo binario
 *
 * @param path	direccion de el archivo donde se guardaran los datos
 * @param pArrayListPassenger puntero a la estructura linkedList de pasajeros
 * @return	si la lista es guardada con exito, retorna(0), de caso contrario, retorna (-1)
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


