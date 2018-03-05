/***********************************************************************
*                   spatial_correlator.h   		          		  	   *
************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This library contains all the necessary functions to perform
* the spatial correlation between an image and a pattern
*
***********************************************************************/

#ifndef SPATIAL_CORRELATOR_H
#define SPATIAL_CORRELATOR_H

/*--------------------------------------------------------------------*/
/*                             MACROS                                 */
/*--------------------------------------------------------------------*/
#include "../lib/image.h"

#define RED >>16&255
#define GREEN >>8&255
#define BLUE >>0&255

#define MAXWIDTH 1366
#define MAXHEIGH 768

/*--------------------------------------------------------------------*/
/*                               TYPES                                */
/*--------------------------------------------------------------------*/
typedef struct position{
	int pos_x;
	int pos_y;
}position_t;

/*---------------------------------------------------------------------*/
/*                  PUBLIC FUNCTION DECLARATIONS                       */     
/*---------------------------------------------------------------------*/

/** @brief This functions performs the spatial correlation between an
 * 		   image and a template.
 *  @todo This is the test 2 for doxygen generation
 *  @image html logo.jpg
 *  @param img Data structure containing the image.
 *  @param template Data structure containing the template.
 *  @return A data structure containing the coordinates of the greatest
 *  		likelihood between the image and the template.
 */
position_t perform_correlation(image_t img, image_t template);

#endif /* SPATIAL_CORRELATOR_H */
/**********************************************************************/
/*                    spatial_correlator.h                            */
/**********************************************************************/
