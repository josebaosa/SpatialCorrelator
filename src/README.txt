SPATIAL CORRELATOR PROJECT
==========================

Finalidad de la aplicaci�n
==========================
La aplicaci�n est� pensada para testear el algoritmo de correlaci�n de imagenes que se piensa
utilizar para el proyecto. Para ello, se van a utilizar una serie de imagenes almacenados en
formato BMP junto con una plantilla. El usuario seleccionar� cualquiera de las imagenes mediante
la comunicaci�n serial, y la aplicaci�n mostrar� mediante VGA la ilustraci�n seleccionada
remarcando el area de mejor correlaci�n con la plantilla.

Estructura de carpetas
======================
APP:
----
Esta carpeta solamente contiene el main, que se encarga �nicamente de interactuar con la m�quina de
estados. --- FUNCIONAL ---

DOMAIN:
-------
Esta carpeta almacena dos conjuntos de ficheros. Por una parte est� el c�digo fsm.c/.h, que
almacena la m�quina de estados. Para esta versi�n ya he integrado el motor que me has mencionado 
(los ficheros se encuentran en lib), y tambi�n he separado la funci�n visualize en 2 diferentes para
que sea m�s legible. --- FUNCIONAL ---

Por otra parte est�n los ficheros menu_manager.c/.h. Estos ficheros se encargan de gestionar la 
comunicaci�n serie con el usuario. --- FUNCIONAL ---

* INFO: Como mencion� en la versi�n anterior, estas funciones utilizaban xil_printf. Para esta versi�n
ya he arreglado esto con los ficheros console_stream.c/.h que comentar� m�s tarde --- CORREGIDO ---

HW ABSTRACTION:
---------------
Por una parte esta carpeta contiene el gestor de VGA. Para llevar a cabo esta parte se va a
utilizar el c�digo desarrollado por Jon Ayerdi. --- FUNCIONAL ---

Por otra parte esta carpeta contiene el gestor de ficheros para leer BMP. Se ha utilizado el
c�digo de Jon Ayerdi para esta secci�n. Aparte del c�digo de Jon, se ha introducido una
funcionalidad extra para leer todos los ficheros BMP en un directorio concreto. --- FUNCIONAL ---

Finalmente he creado el conjunto console_stream.c/.h. Estos ficheros utilizan la estructura del c�digo
de Jon y sirven para ofrecer una capa de abstracci�n a la hora de leer/escribir por la l�nea serie. Las
funciones utilizadas en domain est�n definidas aqui. --- FUNCIONAL ---

IO:
---
Por una parte contiene ficheros que dan una capa de abstracci�n al controlador de VGA. Al igual
que el controlador, esta parte tambi�n ha sido importada del c�digo de Jon. --- FUNCIONAL ---

Por otra parte, tambi�n contiene otros ficheros encargados de gestinar la memoria para el
almacenamiento de imagenes. Tambi�n ha sido importado del c�digo de Jon. --- FUNCIONAL ---

LIB:
----
Esta carpeta se divide en 5 secciones. Por una parte contiene el fichero font8x8.h, que define la
estructura de los car�cteres para poder printarlos por VGA. Este c�digo ha sido importado de una
fuente externa. --- FUNCIONAL ---

Aparte de esto, tambi�n est�n los ficheros bmp.c/.h, que ofrecen funciones para leer y escribir
en ese tipo de fichero. Estos ficheros han sido importados del c�digo de Jon. --- FUNCIONAL ---

* En la versi�n anterior coment� que hab�a visto que los bmp.c/.h no me le�an bien algunos ficheros. He
quedado con Jon y ya me ha explicado el porqu�. Resulta que la aplicaci�n no ten�a memor�a suficiente
como para cargar m�s de una imagen. Para solucionarlo basta con acceder al fichero lscript.ld e
incrementar el par�metro HeapSize a 0x10000000

Por otra parte est�n los ficheros image.c/.h. Estos se encargan de almacenar la estructura de las
imag�nes. --- FUNCIONAL ---

Adem�s est�n los ficheros spatial_correlator.c/.h, que son los que contienen los algoritmos
encargados de realizar la correlaci�n de imagenes. --- FUNCIONAL ---

Finalmente est�n los ficheros state_machine.c/.h. Estos ficheros almacenan el motor de la m�quina de
estados utilizado, y al igual que otras partes de la aplicaci�n el c�digo ha sido importado.
--- FUNCIONAL ---

Estado actual
=============
Actualmente la aplicaci�n est� terminada y funciona correctamente. Para poder ejecutar un ejemplo hay 
que realizar dos pasos antes de nada:

 [1] - Introducir un tarjeta SD con un contenido v�lido. Este proyecto incluye una carpeta denominada
 	   Img. Hay que copiar su contenido al directorio raiz de la tarjeta para tener los datos disponibles.
 	   
 [2] - Comprobar que el fichero lscript.ld tenga un tama�o adecuado. Como se ha comentado anteriormente,
 	   este fichero tiene un par�metro denominado HeapSize, cuyo valor tiene que ser 0x10000000.
 	   
Una vez realizadas las dos tareas bastar�a con programar la FPGA, lanzar la aplicaci�n y seleccionar la
imagen a visualizar. La imagen se visualiza por VGA.