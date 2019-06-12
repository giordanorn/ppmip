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
		return -1;
	}
	else {
		return parseOption(argument);
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
printShortHelp(char *programName)
{
	printf("Usage: %s [FILTER] [INPUT_FILE] [OUTPUT_FILE]\n", programName);
	printf("Try \'%s help\' for more information.\n", programName);
}

void
printHelp()
{
	puts("The available options are:");
	for (short i = 0; i < TOTAL_OPTIONS; i++) {
		printf("%s\n", OPTIONS(i));
	}
}

void
printImageInfo(PPM image)
{
	printf("Width: %d\n", image.width);
	printf("Height: %d\n", image.height);
	printf("Pixel color bits: %d\n", image.color_bits);
	puts("Pixel Map:\t\tR\tG\tB");
	for (int i = 0; i < image.width; i++) {
		for (int j = 0; j < image.height; j++) {
			printPixel(i, j, image.pixelmap[i][j]);
		}
	}
}

void
printPixel(int line, int column, Pixel pixel)
{
	printf("Pixel[%d][%d]:\t\t%d\t%d\t%d\n", line, column, pixel.red, pixel.green, pixel.blue);
}

bool
userConfirmation(char *message)
{
	char confirmation;
	printf("%s [y/N] ", message);
	scanf("%c", &confirmation);
	if (confirmation == 'y' || confirmation == 'Y')
	{
		return true;
	}
	else 
	{
		return false;
	}
}