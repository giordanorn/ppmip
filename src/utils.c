#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const int TOTAL_OPTIONS = 8;

char*
OPTIONS(int option)
{
	char *options[] = {
		"help",
		"greyscale",
		"threshold",
		"blur",
		"sharp",
		"rotate",
		"amplify",
		"reduce"
	};
	return options[option];
}

int
checkOption(char *argument)
{
	if (!argument) {
		printf("You must pass at least one argument. Exiting...\n");
		return -1;
	}
	else {
		char *option = argument;
		return parseOption(option);
	}
}

int
parseOption(char *option)
{
	for (int i = 0; i < TOTAL_OPTIONS; i++) {
		if (strcmp(option, OPTIONS(i)) == 0) {
			return i;
		}
	}
	return -1;
}

void
printHelp()
{
	printf("The available options are:\n");
	for (short i = 0; i < TOTAL_OPTIONS; i++) {
		printf("%s\t\t--\n", OPTIONS(i));
	}
}

void
printImageInfo(PPM image)
{
	printf("Width: %d\n", image.width);
	printf("Height: %d\n", image.height);
	printf("Pixel color bits: %d\n", image.color_bits);
	printf("Pixel Map:\t\tR\tG\tB\n");
	for (int i = 0; i < image.width; i++) {
		for (int j = 0; j < image.height; j++) {
			printf("Pixel[%d][%d]:\t\t%d\t%d\t%d\n", i, j, image.pixelmap[i][j].r, image.pixelmap[i][j].g, image.pixelmap[i][j].b);
		}
	}
}