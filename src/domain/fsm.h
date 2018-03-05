/***********************************************************************
*                            fsm.h   		          		  	   *
************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This function contains all the states of the finite
* state machine and all the performed operations for every state
*
***********************************************************************/

#ifndef FSM_H
#define FSM_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/
#define FALSE 0
#define TRUE  1

#define STATE_EXIT 				   -1
#define STATE_INIT 					0
#define STATE_REQUEST_FILE 			1
#define STATE_READ_FILE 			2
#define STATE_PERFORM_CORRELATION 	3
#define STATE_VISUALIZE 			4

#define VISUALIZATION_LINE_WIDTH 7
#define VISUALIZATION_LINE_COLOR 0xFFFF0000

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */     
/*---------------------------------------------------------------------*/

/** @brief Executes one state of the finite state machine.
 *  @todo This is the test 1 for doxygen generation
 *  @return A flag indicating if the application needs to stop or not (0-Continue|1-Stop).
 */
int run_fsm(void);

#endif /* MODULE_H */
/**********************************************************************/
/*                                fsm.h                            */
/**********************************************************************/
