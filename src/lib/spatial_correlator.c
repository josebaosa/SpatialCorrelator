/*****************************************************************************************
*                                      spatial_correlator.c                              *
******************************************************************************************
* AUTHOR: Joseba Osa
*
* DESCRIPTION: This library contains all the necessary functions to perform
* the spatial correlation between an image and a pattern
*
*****************************************************************************************/

/*--------------------------------------------------------------------------------------*/
/*                                       INCLUDES                                       */
/*--------------------------------------------------------------------------------------*/
#include "../lib/spatial_correlator.h"

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DECLARATIONS                             */     
/*--------------------------------------------------------------------------------------*/

/** @brief This function takes an RGB image and parses it to grayscale.
 *  @param container Array of integers which will be used to store the grayscale image.
 *  @param source Data structure containing the source image.
 *  @return Void.
 */
void grayscale_parser(int *container, image_t source);

/** @brief This function puts the mean of a list of values to zero.
 *  @param values Array of integers containing the values.
 *  @param length The amount of values stored in the array.
 *  @return Void.
 */
void mean_to_zero(int *values, int length);

/*--------------------------------------------------------------------------------------*/
/*                                      VARIABLES                                       */
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
/*                            PRIVATE FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/
void grayscale_parser(int *container, image_t source){

	int num_elements = source.x * source.y;
	int pos = 0;

	for(pos = 0; pos < num_elements; pos++){
		container[pos] = ((source.pixels[pos]RED)+(source.pixels[pos]GREEN)+(source.pixels[pos]BLUE))/3;
	}
}

void mean_to_zero(int *values, int length){

	int pos = 0;
	int mean = 0;

	// Compute the mean
	for(pos = 0; pos < length; pos++)
		mean += values[pos];
	mean /= length;

	// Subtract the mean to all the values
	for(pos = 0; pos < length; pos++)
		values[pos] -= mean;
}

/*--------------------------------------------------------------------------------------*/
/*                             PUBLIC FUNCTION DEFINITIONS                              */
/*--------------------------------------------------------------------------------------*/

position_t perform_correlation(image_t img, image_t template){
	
	int temp_x = 0;
	int temp_y = 0;
	int temp_i = 0;
	int temp_j = 0;

	int x_positions = img.x - template.x;
	int y_positions = img.y - template.y;

	int image_adapted[MAXWIDTH*MAXHEIGH];
	int templ_adapted[MAXWIDTH*MAXHEIGH];

	int sum_values = 0;
	int max_corr = 0;

	position_t ret_value;

	// Gray scale - Mean zero to image
	grayscale_parser(image_adapted,img);
	grayscale_parser(templ_adapted,template);

	mean_to_zero(image_adapted,img.x*img.y);
	mean_to_zero(templ_adapted,template.x*template.y);

	// Compare values
	for(temp_x = 0; temp_x < x_positions; temp_x ++){
		for(temp_y = 0; temp_y < y_positions; temp_y ++){
			sum_values = 0;
			for(temp_i = 0; temp_i < template.x; temp_i ++){
				for(temp_j = 0; temp_j < template.y; temp_j ++){
					sum_values += image_adapted[(temp_x+temp_i)+(img.x*(temp_y+temp_j))] *
								  templ_adapted[(temp_i)+(template.x*temp_j)];
				}
			}
			if(sum_values > max_corr){
				max_corr = sum_values;
				ret_value.pos_x = temp_x;
				ret_value.pos_y = temp_y;
			}
		}
	}

	return ret_value;
}

/****************************************************************************************/
/*                                      spatial_correlator.c                            */
/****************************************************************************************/
