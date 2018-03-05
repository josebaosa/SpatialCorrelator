SPATIAL CORRELATOR PROJECT
==========================

Finalidad de la aplicacion
==========================
La aplicacion esta pensada para testear el algoritmo de correlacion de imagenes que se piensa
utilizar para el proyecto. Para ello, se van a utilizar una serie de imagenes almacenados en
formato BMP junto con una plantilla. El usuario seleccionara cualquiera de las imagenes mediante
la comunicacion serial, y la aplicacion mostrara mediante VGA la ilustracion seleccionada
remarcando el area de mejor correlacion con la plantilla.

Estructura de carpetas
======================
APP:
----
Esta carpeta solamente contiene el main.c, que se encarga unicamente de interactuar con la maquina de
estados.

* Doxygen: El main no esta comentado, ya que solamente llama a la maquina de estados y no lo he visto
necesario.

DOMAIN:
-------
Esta carpeta almacena dos conjuntos de ficheros. Por una parte esta el codigo fsm.c / fsm.h, que
almacena la maquina de estados. Basicamente interactua con el motor que esta almacenado en la
carpeta lib.

Por otra parte estan los ficheros menu_manager.c / menu_manager.h. Estos ficheros se encargan de gestionar la 
comunicacion serie con el usuario.

* Doxygen: Todas las funciones de estos ficheros me han parecido lo suficientemente complejas como para no
poder entenderlas de un vistazo rapido, por lo que he comentado todo dentro de esta carpeta.

HW ABSTRACTION:
---------------
Por una parte esta carpeta contiene el gestor de VGA.

Por otra parte esta carpeta contiene el gestor de ficheros para leer BMP.

Finalmente esta el conjunto console_stream.c / console_stream.h. Estos ficheros ofrecen una capa de abstraccion 
a la hora de leer/escribir por la linea serie.

* Doxygen: Gran parte de esta carpeta es un codigo externo, por lo que esta sin comentar. Los ficheros
console_stream si estan creados por mi, y los he comentado. La razon principal para comentarlos ha sido que
las funciones tienen unas variables de entrada que en mi opinion necesitan una breve descripcion para poder
entender como funcionan.

IO:
---
Por una parte contiene ficheros que dan una capa de abstraccion al controlador de VGA.

Por otra parte, tambien contiene otros ficheros encargados de gestinar la memoria para el
almacenamiento de imagenes.

* Doxygen: Este codigo forma parte de lo que he importado para el proyecto, por lo que tampoco esta comentado.

LIB:
----
Esta carpeta se divide en 5 secciones. Por una parte contiene el fichero font8x8.h, que define la
estructura de los caracteres para poder printarlos por VGA. Este codigo ha sido importado de una
fuente externa.

Aparte de esto, tambien estan los ficheros bmp.c / bmp.h, que ofrecen funciones para leer y escribir
en ese tipo de fichero.

Por otra parte estan los ficheros image.c / image.h. Estos se encargan de almacenar la estructura de las
imagenes.

Ademas estan los ficheros spatial_correlator.c / spatial_correlator.h, que son los que contienen los algoritmos
encargados de realizar la correlacion de imagenes.

Finalmente estan los ficheros state_machine.c / state_machine.h. Estos ficheros almacenan el motor de la maquina de
estados utilizado, y al igual que otras partes de la aplicacion el codigo ha sido importado.

* Doxygen: En esta carpeta solo he creado los ficheros de correlacion espacial, ya que todo lo demas era
el motor de maquinas de estado y librerias relacionadas con la visualizacion de datos y el almacenamiento de
imagenes. Los algoritmos que he creado son relativamente complicados y por eso he visto preferible comentarlos.
Aparte de esto, estos ficheros son una libreria transversal que no dependen de este proyecto, por lo que se podrian
reutilizar en otros sitios. Esto implica que es probable que cualquier otra persona pueda utilizarlo, por lo que
facilitar esa posible labor de entender el funcionamiento tambien ha sido una razon para comentar todo.

Comentarios para doxygen
========================
Solamente quiero comentar dos puntos en esta seccion:

[1] - El proyecto no tiene ningun todo en los comentarios, por lo que he introducido dos textos manualmente para poder ver
      que se me genera la segunda pestana en el html.

[2] - El proyecto no tiene ninguna imagen. Para poder probar la agregacion de imagenes externas en doxygen he introducido el
      logotipo de MU en el fichero spatial_correlator.h