#include <stdio.h>
#include <stdlib.h>
#include "file.h"

PPM*
readPPM(char *pathto)
{
	FILE *file;
	file = fopen(pathto, "r");

	if (!file)
	{
		printf("File \"%s\" not found or some error has occurred.\n", pathto);
		exit(1);
	}

	char buffer[64];
	
	// Read identifier
	fscanf(file, "%s", buffer);

	// Identifier has to be P3
	if ( buffer[0] == 'P' && buffer[1] == '3' && buffer[2] == '\0' )
	{
		if (DEBUG)
		{
			printf("Your file has an identifier of a PPM image! -- This is a debug message.\n");
		}
	}
	else
	{
		printf("Your file may not be an PPM image, please choose another one.\n");
		fclose(file);
		exit(1);
	}

	PPM *image = (PPM*) calloc(sizeof(PPM), 1);

	// The usage of unisgned char is just because the value of the color bits will always be 255, change it if you want more color quality.
	unsigned char color_bits;
	unsigned int width, height;

	fscanf(file, "%d %d", &width, &height);
	fscanf(file, "%hhd", &color_bits);

	image->pixelmap = (Pixel **) calloc(sizeof(Pixel*), width);
	for (int i = 0; i < width; i++)
	{
		image->pixelmap[i] = (Pixel *) calloc(sizeof(Pixel), height);
		for (int j = 0; j < height; j++)
		{
			fscanf(file, "%hhd %hhd %hhd", &image->pixelmap[i][j].red, &image->pixelmap[i][j].green, &image->pixelmap[i][j].blue);
		}
	}

	fclose(file);

	// Assign local variables to image pointer
	image->width = width;
	image->height = height;
	image->color_bits = color_bits;

	return image;
}

void
writePPM(char *pathto, PPM image)
{
	FILE *file;
	file = fopen(pathto, "r");

	if ( file == NULL || userConfirmation("The output file already exists, do you want to overwrite?") == true )
	{
		if (VERBOSE)
		{
			printf("Writing file \"%s\"...\n", pathto);
		}

		file = fopen(pathto, "w");

		if (!file)
		{
			printf("You have no permission to write this file.\n");
			exit(1);
		}

		// Write identifier
		fprintf(file, "P3\n");

		// Write dimensions
		fprintf(file, "%u %u\n", image.width, image.height);

		// Write color bits
		fprintf(file, "%u\n", image.color_bits);

		// Write pixel map
		for (ushort i = 0; i < image.width; i++)
		{
			for (ushort j = 0; j < image.height; j++)
			{
				fprintf(file, "%d %d %d\n", image.pixelmap[i][j].red, image.pixelmap[i][j].green, image.pixelmap[i][j].blue);
			}
		}

		fclose(file);

		if (VERBOSE)
		{
			printf("Done.\n");
		}

	}
	else
	{
		printf("Nothing to be done. Exiting.\n");
		
		if (file)
		{
			fclose(file);
		}
	}

	return;
}