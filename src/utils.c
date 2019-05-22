#include "utils.h"

Pixel
newPixel()
{
	Pixel pixel;

	pixel.r = 0;
	pixel.g = 0;
	pixel.b = 0;

	return pixel;
}

void
checkArgs(char *arg)
{
	switch(parseOption(arg))
	{
		case THR:
		case BLU:
		case SHA:
		case ROT:
		case AMP:
		case RED:
			printf("Option %s is currently working in progress. It will be available soon.\n");
			exit(1);
		default:
			printf("Unrecognized option %s. Exiting...\n", arg);
			exit(1);
	}
	return;
}

int
parseOption(char *option)
{
	if (strcmp(option, "thr") == 0)
		return THR;
	else if (strcmp(option, "blu") == 0)
		return BLU;
	else if (strcmp(option, "sha") == 0)
		return SHA;
	else if (strcmp(option, "rot") == 0)
		return ROT;
	else if (strcmp(option, "amp") == 0)
		return AMP;
	else if (strcmp(option, "red") == 0)
		return RED;
	else
		return -1;
}
