/***********************************************************************
*                            console_stream.h   		          		  	   *
************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This file uses the structure defined in stream.h and offers
* an implementation to manage serial line communications
*
***********************************************************************/

#ifndef CONSOLE_STREAM_H
#define CONSOLE_STREAM_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/

#include "../io/stream.h"

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/


/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */     
/*---------------------------------------------------------------------*/

/** @brief This function sets the functions to handle the serial input stream.
 * 	@param input Data structure containing the serial input management functions.
 * 	@return Void.
 */
void console_stream_input(input_stream_t *input);

/** @brief This function sets the functions to handle the serial output stream.
 * 	@param output Data structure containing the serial output management functions.
 * 	@return Void.
 */
void console_stream_output(output_stream_t *output);

#endif
/**********************************************************************/
/*                                console_stream.h                            */
/**********************************************************************/
