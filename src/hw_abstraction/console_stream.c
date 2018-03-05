/*****************************************************************************************
*                                      console_stream.c                                          *
******************************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This file uses the structure defined in stream.h and offers
* an implementation to manage serial line communications
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

/* Module declarations */
#include "console_stream.h"

#include <stdio.h>

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */     
/*--------------------------------------------------------------------------------------*/

/** @brief This function defines how to read from the serial line.
 *  @param str Char array which will be used as the data contanier.
 *  @param size The maximum length the input data can have.
 *  @param context Required to generate the function pointer.
 *  @return In this case this value is not relevant, always 0.
 */
static size_t console_read(char *str, size_t size, void *context);

/** @brief This function defines how to write to the serial line.
 *  @param str Char array which will contain the message to output.
 *  @param size The maximum length the output data can have.
 *  @param context Required to generate the function pointer.
 *  @return In this case this value is not relevant, always 0.
 */
static size_t console_write(char *str, size_t size, void *context);

/** @brief Empties all the serial input stream buffer.
 *  @param context Required to generate the function pointer.
 *  @return Void.
 */
static void console_discard(void *context);

/** @brief Empties all the serial output stream buffer.
 *  @param context Required to generate the function pointer.
 *  @return Void.
 */
static void console_flush(void *context);

/** @brief Required by the data structure, the function is empty.
 *  @param context Required to generate the function pointer.
 *  @return Void.
 */
static void console_close(void *context);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

static size_t console_read(char *str, size_t size, void *context){

	int i = 0;
	char c = 'a';

	while(i < size && c != '\n' && c != '\r'){
		c = getchar();
		if(c != '\n' && c != '\r')
			str[i++] = c;
		else
			str[i++] = 0;
	}
	putchar('\n');

	return 0;
}

static size_t console_write(char *str, size_t size, void *context){

	int i = 0;

	while(str[i] != 0 && i <size)
		putchar(str[i++]);
	fflush(stdout);

	return 0;
}

static void console_discard(void *context){
	fflush(stdin);
}

static void console_flush(void *context){
	fflush(stdout);
}

static void console_close(void *context){
	// Do nothing
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

void console_stream_input(input_stream_t *input){
	input->read = console_read;
	input->discard = console_discard;
	input->close = console_close;
}

void console_stream_output(output_stream_t *output){
	output->write = console_write;
	output->flush = console_flush;
	output->close = console_close;
}

/****************************************************************************************/
/*                                      module.c                                        */
/****************************************************************************************/
