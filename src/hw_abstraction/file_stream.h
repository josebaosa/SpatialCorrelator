/*
 * file_stream.h
 *
 *  Created on: 17 Nov 2017
 *      Author: Jon Ayerdi
 */

#ifndef SRC_HAL_FILE_STREAM_H_
#define SRC_HAL_FILE_STREAM_H_

#include "../io/stream.h"

#define NAMELENGTH 64
#define MAXFILES 32
#define FOLDERPATH ""

int file_input_stream(input_stream_t *stream, const char *filename);
int file_output_stream(output_stream_t *stream, const char *filename);

/**
 * Doxygen stuff
 *
 */
int get_filenames(char *folder, char filenames[MAXFILES][NAMELENGTH], int *amount);

#endif /* SRC_HAL_FILE_STREAM_H_ */
