#ifndef UTILS_H
#define UTILS_H

#define DEBUG 0
#define VERBOSE 1

#define uint unsigned int
#define uchar unsigned char
#define ushort unsigned short

#define Color uchar

#include <stdbool.h>

enum {
	HELP,
	GREYSCALE,
	THRESHOLD,
	BLUR,
	SHARP,
	ROTATE,
	AMPLIFY,
	REDUCE,
} OPTIONSMAP;

const int TOTAL_OPTIONS;
char* OPTIONS(int);

typedef struct {
	Color red;
	Color green;
	Color blue;
} Pixel;

typedef struct {
	uint width;
	uint height;
	uint color_bits;
	Pixel **pixelmap;
} PPM;

	
int checkOption(char *);
int parseOption(char *);
void printHelp(void);
void printImageInfo(PPM);
void printPixel(int, int, Pixel);
bool userConfirmation(char *);
#endif
