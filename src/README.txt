SPATIAL CORRELATOR PROJECT
==========================

Finalidad de la aplicación
==========================
La aplicación está pensada para testear el algoritmo de correlación de imagenes que se piensa
utilizar para el proyecto. Para ello, se van a utilizar una serie de imagenes almacenados en
formato BMP junto con una plantilla. El usuario seleccionará cualquiera de las imagenes mediante
la comunicación serial, y la aplicación mostrará mediante VGA la ilustración seleccionada
remarcando el area de mejor correlación con la plantilla.

Estructura de carpetas
======================
APP:
----
Esta carpeta solamente contiene el main, que se encarga únicamente de interactuar con la máquina de
estados. --- FUNCIONAL ---

DOMAIN:
-------
Esta carpeta almacena dos conjuntos de ficheros. Por una parte está el código fsm.c/.h, que
almacena la máquina de estados. Para esta versión ya he integrado el motor que me has mencionado 
(los ficheros se encuentran en lib), y también he separado la función visualize en 2 diferentes para
que sea más legible. --- FUNCIONAL ---

Por otra parte están los ficheros menu_manager.c/.h. Estos ficheros se encargan de gestionar la 
comunicación serie con el usuario. --- FUNCIONAL ---

* INFO: Como mencioné en la versión anterior, estas funciones utilizaban xil_printf. Para esta versión
ya he arreglado esto con los ficheros console_stream.c/.h que comentaré más tarde --- CORREGIDO ---

HW ABSTRACTION:
---------------
Por una parte esta carpeta contiene el gestor de VGA. Para llevar a cabo esta parte se va a
utilizar el código desarrollado por Jon Ayerdi. --- FUNCIONAL ---

Por otra parte esta carpeta contiene el gestor de ficheros para leer BMP. Se ha utilizado el
código de Jon Ayerdi para esta sección. Aparte del código de Jon, se ha introducido una
funcionalidad extra para leer todos los ficheros BMP en un directorio concreto. --- FUNCIONAL ---

Finalmente he creado el conjunto console_stream.c/.h. Estos ficheros utilizan la estructura del código
de Jon y sirven para ofrecer una capa de abstracción a la hora de leer/escribir por la línea serie. Las
funciones utilizadas en domain están definidas aqui. --- FUNCIONAL ---

IO:
---
Por una parte contiene ficheros que dan una capa de abstracción al controlador de VGA. Al igual
que el controlador, esta parte también ha sido importada del código de Jon. --- FUNCIONAL ---

Por otra parte, también contiene otros ficheros encargados de gestinar la memoria para el
almacenamiento de imagenes. También ha sido importado del código de Jon. --- FUNCIONAL ---

LIB:
----
Esta carpeta se divide en 5 secciones. Por una parte contiene el fichero font8x8.h, que define la
estructura de los carácteres para poder printarlos por VGA. Este código ha sido importado de una
fuente externa. --- FUNCIONAL ---

Aparte de esto, también están los ficheros bmp.c/.h, que ofrecen funciones para leer y escribir
en ese tipo de fichero. Estos ficheros han sido importados del código de Jon. --- FUNCIONAL ---

* En la versión anterior comenté que había visto que los bmp.c/.h no me leían bien algunos ficheros. He
quedado con Jon y ya me ha explicado el porqué. Resulta que la aplicación no tenía memoría suficiente
como para cargar más de una imagen. Para solucionarlo basta con acceder al fichero lscript.ld e
incrementar el parámetro HeapSize a 0x10000000

Por otra parte están los ficheros image.c/.h. Estos se encargan de almacenar la estructura de las
imagénes. --- FUNCIONAL ---

Además están los ficheros spatial_correlator.c/.h, que son los que contienen los algoritmos
encargados de realizar la correlación de imagenes. --- FUNCIONAL ---

Finalmente están los ficheros state_machine.c/.h. Estos ficheros almacenan el motor de la máquina de
estados utilizado, y al igual que otras partes de la aplicación el código ha sido importado.
--- FUNCIONAL ---

Estado actual
=============
Actualmente la aplicación está terminada y funciona correctamente. Para poder ejecutar un ejemplo hay 
que realizar dos pasos antes de nada:

 [1] - Introducir un tarjeta SD con un contenido válido. Este proyecto incluye una carpeta denominada
 	   Img. Hay que copiar su contenido al directorio raiz de la tarjeta para tener los datos disponibles.
 	   
 [2] - Comprobar que el fichero lscript.ld tenga un tamaño adecuado. Como se ha comentado anteriormente,
 	   este fichero tiene un parámetro denominado HeapSize, cuyo valor tiene que ser 0x10000000.
 	   
Una vez realizadas las dos tareas bastaría con programar la FPGA, lanzar la aplicación y seleccionar la
imagen a visualizar. La imagen se visualiza por VGA.