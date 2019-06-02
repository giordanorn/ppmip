#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "file.h"
#include "filters.h"

int
main(int argc, char *argv[])
{
	char *firstArgument = argv[1];
	char *secondArgument = argv[2];
	char *thirdArgument = argv[3];

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
				image = applyGreyscale(image);
				if (!thirdArgument)
				{
					printf("You might pass a third argument with a path to the output file.\n");
					exit(1);
				}
				else
				{
					writePPM(thirdArgument, image);
					break;
				}
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
			exit(1);
	}

	return 0;
}
