/*****************************************************************************************
*                                      menu_manager.c                                          *
******************************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: The menu manager prints all the available files via serie
* manages the file selection process
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

/* Module declarations */
#include "menu_manager.h"

#include "../io/stream.h"

#include "../hw_abstraction/console_stream.h"
#include "../hw_abstraction/file_stream.h"

#include <stdio.h>
#include <string.h>

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */     
/*--------------------------------------------------------------------------------------*/

/** @brief Displays the header (author, version and date) and a list of available files if possible
 *  @return A flag which will determine if the SD card is readable (STATUS_ERR|STATUS_OK).
 */
static int display_menu();

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/
static char filenames[MAXFILES][NAMELENGTH];
static int sel_filenames;

static int console_initialized = 0;
static output_stream_t console_out;
static input_stream_t console_in;
static char msg[100];

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

int display_menu(void){
	
	int status, i;

	// Get all the available files
	status = get_filenames("0:/",filenames,&sel_filenames);

	// Print menu header
	stream_write(console_out,"\x1B[H",100); //Set cursor to top left of terminal
	stream_write(console_out,"\x1B[2J",100); //Clear terminal
	stream_write(console_out,"**************************************************\n\r",100);
	stream_write(console_out,"*         SPATIAL CORRELATOR PROJECT             *\n\r",100);
	stream_write(console_out,"**************************************************\n\r",100);
	stream_write(console_out,"* Author:   Joseba Osa                           *\n\r",100);
	stream_write(console_out,"* Version:  3                                    *\n\r",100);
	stream_write(console_out,"* Date:     10/01/2018                           *\n\r",100);
	stream_write(console_out,"**************************************************\n\r",100);
	stream_write(console_out,"\n\r",100);

	// Print the remaining part of the menu
	if(status == STATUS_OK){
		stream_write(console_out,"SELECT YOUR FILE: \n\r",100);
		for(i=1; i <= sel_filenames; i++){
			sprintf(msg,"%i - %s\n\r",i,filenames[i-1]);
			stream_write(console_out,msg,100);
		}
		stream_write(console_out,"0 - Exit\n\r\n\r",100);
		stream_write(console_out,"Enter a selection: ",100);
	}else{
		if(status == -1){
			stream_write(console_out,"ERROR!! It seems that the template.bmp file does not exist."
					   	   	   	   	 " Please add it and restart the application",100);
		}else{
			sprintf(msg,"Error code %i while trying to access to the SD card.",status);
			stream_write(console_out,msg,100);
		}
	}

	return status;
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

int select_file(char *selection){

	int selected = 0, status, sel;

	// Initialize console streams if needed
	if(!console_initialized){
		console_stream_input(&console_in);
		console_stream_output(&console_out);
		console_initialized = 1;
	}

	while(selected == 0){
		status = display_menu();
		if(status == STATUS_ERR){
			selected = 1;
		}else{
			stream_read(console_in,msg,100);
			sscanf(msg,"%i",&sel);
			if(sel == 0){
				status = STATUS_ERR;
				selected = 1;
			}else{
				if(sel <= sel_filenames){
					strcpy(selection,filenames[sel-1]);
					selected = 1;
				}else{
					stream_write(console_out,"ERROR! The selection is out of the bounds. Press enter to continue...\n\r",100);
					stream_read(console_in,msg,100);
				}
			}
		}
	}

	return status;
}

/****************************************************************************************/
/*                                      menu_manager.c                                        */
/****************************************************************************************/
