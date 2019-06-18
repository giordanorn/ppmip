#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define DEBUG 0
#define VERBOSE 1

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned char Color;

enum {
	HELP,
	GREYSCALE,
	THRESHOLD,
	BLUR,
	SHARP,
	ROTATE,
	SCALEUP,
	SCALEDOWN
} Option;

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
void printShortHelp(char *);
void printImageInfo(PPM);
void printPixel(int, int, Pixel);
bool userConfirmation(char *);

#endif
