#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "read.h"
#include "filters.h"

int
main(int argc, char *argv[])
{
	char *firstArgument = argv[1];
	char *secondArgument = argv[2];

	int option = checkOption(firstArgument);

	switch (option) {
		case HELP:
			printHelp();
			break;
		case GREYSCALE:
			if (!secondArgument)
			{
				printf("%s option requires a path to a file as second argument.\n", OPTIONS(GREYSCALE));
				exit(1);
			}
			else
			{
				PPM image = *readPPM(secondArgument);
				printf("Before applying greyscale filter:\t -- This is a debug message\n");
				printImageInfo(image);
				image = applyGreyscale(image);
				printf("After applying greyscale filter:\t -- This is a debug message\n");
				printImageInfo(image);
			}
			break;
		case THRESHOLD:
		case BLUR:
		case SHARP:
		case ROTATE:
		case AMPLIFY:
		case REDUCE:
			printf("Option %s is currently working in progress. It will be available soon.\n", argv[1]);
			break;
		default:
			printf("Unrecognized option %s. Exiting...\n", argv[1]);
			return 1;
	}

	return 0;
}
