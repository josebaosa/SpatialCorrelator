/***********************************************************************
*                            menu_manager.h   		          		  	   *
************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: The menu manager prints all the available files via serie
* manages the file selection process
*
***********************************************************************/

#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/
#define STATUS_OK  0
#define STATUS_ERR 1

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */     
/*---------------------------------------------------------------------*/

/** @brief BMP file selector.
 *  @param selection char array which will contain the selected file name.
 *  @return A flag which will determine the validity of the selection (STATUS_ERR|STATUS_OK).
 */
int select_file(char *selection);

#endif /* MODULE_H */
/**********************************************************************/
/*                                menu_manager.h                            */
/**********************************************************************/
