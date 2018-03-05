 /*
                                        *******************
 ***************************************** C HEADER FILE ****************************************
 **                                     *******************                                    **
 **                                                                                            **
 ** project    : General template                                                              **
 ** filename   : TPL.H                                                                         **
 ** version    : 1                                                                             **
 ** date       : 19/11/2015                                                                    **
 **                                                                                            **
 ************************************************************************************************
 **                                                                                            **
 ** Copyright (c) 2015, Sainz Oruna, Markel                                                    **
 ** All rights reserved.                                                                       **
 **                                                                                            **
 ************************************************************************************************

 VERSION HISTORY:
 -- -- -- -- -- --

 Version     : 1
 Date        : 19/11/2015
 Revised by  : Sainz Oruna, Markel
 Description : Original version.

 */
 #ifndef STATE_MACHINE_H
 #define STATE_MACHINE_H

 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                MODULES USED                                              **/
 /**                                                                                          **/
 /**********************************************************************************************/

 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                DEFINITIONS AND MACROS                                    **/
 /**                                                                                          **/
 /**********************************************************************************************/

 #define ITEM_EAC(ident,event,acci) { ident, #event, event, acci }

 #define ESTADO(nombre)                             \
        const TS_EVEACC x##nombre[] = {

 #define FIN_ESTADO(nombre, ident, control)         \
	,{0,NULL,NULL,NULL} };                     \
       const TS_ESTADO nombre =            \
      {ident, #ident, control, (TS_EVEACC *) x##nombre};


 #define MACHINE(nombre)                           \
	const TS_ESTADO * const (x##nombre[]) = {

 #define FIN_MACHINE(nombre,ident, StopC)          \
	   ,NULL };                                \
	 const TS_MACHINE nombre =          \
      {ident, 0 ,#nombre, StopC, (TS_ESTADO **) x##nombre};


 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                TYPEDEFS AND STRUCTURES                                   **/
 /**                                                                                          **/
 /**********************************************************************************************/

 typedef void            (*TPFN_ACC)(void); /* Puntero a una función acción */
 typedef int        	 (*TPFN_EVE)(void); /* Puntero a una función evento */

 typedef struct {
 	  int          id;             /* Identificador del estado destino */
 	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
 	  TPFN_EVE      evento;         /* Puntero a la funci¢n evento */
 	  TPFN_ACC      accion;         /* Puntero a la funci¢n acci¢n */
 } TS_EVEACC;

 typedef struct {
 	  int          id;             /* Identificador del estado */
 	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
 	  TPFN_ACC      controles;      /* Funci¢n de control del estado */
 	  TS_EVEACC   * funcion;        /* Punteros las funciones del estado */
 } TS_STATE;

 typedef struct {
	  int          id;             /* Identificador del automata */
 	  int			id_estado_actual;
 	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
 	  //TPFN_EVE      StopCond;       /* Condici¢n necesaria para la ejecuci¢n */
 	  TS_STATE   **estado;         /* Matriz de punteros a los ESTADOS */
 } TS_MACHINE;


 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                EXPORTED VARIABLES                                        **/
 /**                                                                                          **/
 /**********************************************************************************************/

 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                EXPORTED FUNCTIONS                                        **/
 /**                                                                                          **/
 /**********************************************************************************************/

 void STATE_MACHINE_ejecutar(TS_MACHINE *la_maquina);
 void STATE_MACHINE_ejecuta_estado(TS_STATE *el_estado, TS_MACHINE *la_maquina);



 #endif /* STATE_MACHINE_H */

 /**********************************************************************************************/
 /**                                                                                          **/
 /**                                       EOF                                                **/
 /**                                                                                          **/
 /**********************************************************************************************/
