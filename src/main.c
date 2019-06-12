#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "file.h"
#include "filters.h"

int
main(int argc, char *argv[])
{
	char *programName = argv[0];
	char *firstArgument = argv[1];
	char *secondArgument = argv[2];
	char *thirdArgument = argv[3];

	if (!firstArgument)
	{
		printShortHelp(programName);
		exit(1);
	}

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
					puts("You might pass a third argument with a path to the output file.");
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
			printf("%s: Option %s is currently working in progress. It will be available soon.\n", programName, firstArgument);
			break;
		default:
			printf("%s: Unrecognized option %s. Exiting.\n", programName, firstArgument);
			printShortHelp(programName);
			exit(1);
	}

	return 0;
}
