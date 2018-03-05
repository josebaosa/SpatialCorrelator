/*****************************************************************************************
*                                      fsm.c                                          *
******************************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This function contains all the states of the finite
* state machine and all the performed operations for every state
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/

/* Module declarations */
#include "fsm.h"
#include "menu_manager.h"

#include "../lib/state_machine.h"
#include "../lib/bmp.h"
#include "../lib/image.h"
#include "../lib/spatial_correlator.h"

#include "../io/stream.h"
#include "../io/graphics.h"

#include "../hw_abstraction/console_stream.h"
#include "../hw_abstraction/file_stream.h"
#include "../hw_abstraction/vga_graphics.h"

#include <stdio.h>

/*--------------------------------------------------------------------------------------*/
/*                        FSM PRIVATE FUNCTION DECLARATIONS                             */
/*--------------------------------------------------------------------------------------*/

/** @brief This function detects if a state has finished with an internal flag.
 *  @return A flag indicating if a state has finished or not (FALSE|TRUE).
 */
static int fsm_change_event(void);

/** @brief Intialization state. The function initializes the serial output stream.
 *  @return Void.
 */
static void fsm_action_init(void);

/** @brief Request file state. The function manages the file selection process.
 *  @return Void.
 */
static void fsm_action_request_file(void);

/** @brief Read file state. The function reads the template and the given file form the SD card.
 *  @return Void.
 */
static void fsm_action_read_file(void);

/** @brief Perform correlation state. The function calls to the spatial correlator library and finds the position
 * 		   with the greatest likelihood between the image and the template.
 *  @return Void.
 */
static void fsm_action_perform_correlation(void);

/** @brief Visualize state. The function sends the obtanied result via VGA or HDMI.
 *	@return Void.
 */
static void fsm_action_visualize(void);

/** @brief Empty function required for the state machine engine.
 *  @return Void.
 */
static void fsm_void();

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */     
/*--------------------------------------------------------------------------------------*/

/** @brief Reads a BMP file from a given name and stores the data in an image data structure.
 *  @oaram img The data structure which will contain the acquired image.
 *  @param filename The name of the requested file.
 *  @return A flag which determines if the process has been succesful or not (0-OK|1-Error).
 */
static int read_file(image_t *img, char filename[]);

/** @brief This function gets and image, a pattern and the coordinates of the best correlation,
 * 		   and it draws the image via VGA or HDMI highlighting the coordinates.
 *  @param img Data structure containing the image.
 *  @param template Data structure containing the pattern.
 *  @param pos Data structure containing the coordinates of the best correlation in the image.
 *	@return A flag indicating if the process has been succesful or not (0-OK|1-Error).
 */
static int visualize(image_t img, image_t template, position_t pos);

/** @brief This function draws an empty rect on an image. The rect is drawn in the coordinates of
 * 		   the best correlation and has the same size of the template. The width and color of the
 * 		   rect are defined in the fsm.h and can be modified.
 *  @param img Data structure containing the image.
 *  @param template Data structure containing the pattern.
 *  @param pos Data structure containing the coordinates of the best correlation in the image.
 */
static void mark_image_position(image_t *img, image_t template, position_t pos);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/
static int fsm_stop = FALSE;
static int fsm_event_flag = TRUE;
static TS_EVEACC e_init			 	 =	   {STATE_REQUEST_FILE, "Initialization", fsm_change_event, fsm_action_init};
static TS_EVEACC e_request_file 	     = {STATE_READ_FILE, "Request file", fsm_change_event, fsm_action_request_file};
static TS_EVEACC e_read_file 		   	 = {STATE_PERFORM_CORRELATION, "Read file", fsm_change_event, fsm_action_read_file};
static TS_EVEACC e_perform_correlation =   {STATE_VISUALIZE, "Perform correlation", fsm_change_event, fsm_action_perform_correlation};
static TS_EVEACC e_visualize 		     = {STATE_INIT, "Visualize", fsm_change_event, fsm_action_visualize};

static TS_STATE state_init 				   = {STATE_INIT, "Initialization State", fsm_void, &e_init};
static TS_STATE state_request_file 		   = {STATE_REQUEST_FILE, "Request file State", fsm_void, &e_request_file};
static TS_STATE state_read_file 		   = {STATE_READ_FILE, "Read file State", fsm_void, &e_read_file};
static TS_STATE state_perform_correlationa = {STATE_PERFORM_CORRELATION, "Perform correlation State", fsm_void, &e_perform_correlation};
static TS_STATE state_visualize 		   = {STATE_VISUALIZE, "Visualize State", fsm_void, &e_visualize};

static TS_STATE* statesBackBone[] = {
		&state_init,
		&state_request_file,
		&state_read_file,
		&state_perform_correlationa,
		&state_visualize,
		0
};

static TS_MACHINE fsm_backbone = { 0, STATE_INIT, "FSM Backbone", statesBackBone};

static char filename[NAMELENGTH];
static image_t img, template;
static position_t pos;

static output_stream_t console_out;
static char msg[100];

/*--------------------------------------------------------------------------------------*/
/*                        FSM PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

static int fsm_change_event(void){
	if(fsm_event_flag == TRUE){
		fsm_event_flag = FALSE;
		return TRUE;
	}
	return FALSE;
}

static void fsm_action_init(void){
	console_stream_output(&console_out);
	fsm_event_flag = TRUE;
}

static void fsm_action_request_file(void){

	int error;

	stream_write(console_out,"[FSM] - Current state is Request File\n",100);
	error = select_file(filename);
	if(error)
		fsm_stop = TRUE;
	fsm_event_flag = TRUE;
}

static void fsm_action_read_file(void){

	int error;

	stream_write(console_out,"[FSM] - Current state is Read File\n",100);
	error = read_file(&template,"TEMPLATE.BMP");
	if(error)
		fsm_stop = TRUE;
	error = read_file(&img,filename);
	if(error)
		fsm_stop = TRUE;
	fsm_event_flag = TRUE;
}

static void fsm_action_perform_correlation(void){
	stream_write(console_out,"[FSM] - Current state is Perform correlation\n",100);
	pos = perform_correlation(img,template);
	fsm_event_flag = TRUE;
}

static void fsm_action_visualize(void){

	int error;

	stream_write(console_out,"[FSM] - Current state is Visualize\n",100);
	error = visualize(img,template,pos);
	if(error)
		fsm_stop = TRUE;
	fsm_event_flag = TRUE;
}

static void fsm_void(){

}

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

static int read_file(image_t *img, char filename[]){

	int error;
	input_stream_t fileIn;

	error = file_input_stream(&fileIn,filename);
	if(error){
		sprintf(msg,"Error while reading file %s. The application is going to stop...",filename);
		stream_write(console_out,msg,100);
		return error;
	}
	error = bmp_load(fileIn,img);
	stream_close_input(fileIn);

	return error;
}

static int visualize(image_t img, image_t template, position_t pos){

	// Define parameters
	int error, i;
	graphics_t gfx;
	vga_graphics_config_t config = VGA_GRAPHICS_HDMI_CONFIG(VMODE_800x600);

	// Draw rect on image
	mark_image_position(&img, template, pos);

	// Plot image
	error = vga_graphics_init(config, &gfx);
	if(!error){
		graphics_draw_image(gfx,img,0,0);
		for(i = 0; i < 10; i++)
			graphics_render(gfx);
		graphics_destroy(gfx);
	}else{
		sprintf(msg,"Error while trying to access to VGA manager. The application is going to stop...");
		stream_write(console_out,msg,100);
	}

	return error;
}

static void mark_image_position(image_t *img, image_t template, position_t pos){

	// Define parameters
	int x_pos, y_pos;

	// Draw rect on image
	for(x_pos = pos.pos_x; x_pos < pos.pos_x+template.x; x_pos++){
		for(y_pos = pos.pos_y; y_pos < pos.pos_y+template.y; y_pos++){
			if(x_pos-pos.pos_x >= VISUALIZATION_LINE_WIDTH && y_pos-pos.pos_y >= VISUALIZATION_LINE_WIDTH &&
			   x_pos-pos.pos_x < template.x-VISUALIZATION_LINE_WIDTH && y_pos-pos.pos_y < template.y-VISUALIZATION_LINE_WIDTH){
			}else
				img->pixels[y_pos*img->stride+x_pos] = VISUALIZATION_LINE_COLOR;
		}
	}
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

int run_fsm(void){

	STATE_MACHINE_ejecutar(&fsm_backbone);

	return fsm_stop;
}

/****************************************************************************************/
/*                                      fsm.c                                        */
/****************************************************************************************/
