#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define uchar unsigned char

typedef struct Pixel_t {
	uchar r;
	uchar g;
	uchar b;
} Pixel;

typedef struct PPM_t {
	Pixel **pixelmap;
} PPM;


Pixel newPixel();


enum Options_t {
	THR,
	BLU,
	SHA,
	ROT,
	AMP,
	RED
} Options;


void checkArgs(char **args);
int parseOption(char *option);

#endif
