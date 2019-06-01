#ifndef UTILS_H
#define UTILS_H

#define uchar unsigned char
#define uint unsigned int

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
	uchar r;
	uchar g;
	uchar b;
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

#endif
