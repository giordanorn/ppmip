#include "filters.h"

PPM
applyGreyscale(PPM image)
{
    for (short i = 0; i < image.width; i++)
    {
        for (short j = 0; j < image.height; j++)
        {
            Pixel *current = &image.pixelmap[i][j];

            Color grey = (
                current->red +
                current->green +
                current->blue
            ) / 3;
            
            Pixel greyscaled = {
                grey,
                grey,
                grey
            };

            *current = greyscaled;
        }
    }

    return image;
}

PPM
applyThreshold(PPM image)
{
	uint intensity_delimiter = image.color_bits / 2;
    for (short i = 0; i < image.width; i++)
    {
        for (short j = 0; j < image.height; j++)
        {
            Pixel *current = &image.pixelmap[i][j];

			Color average = (
				current->red +
				current->green +
				current->blue
			) / 3;

			Color threshold = ( average > intensity_delimiter ) ? image.color_bits : 0;

			Pixel thresholded = {
				threshold,
				threshold,
				threshold
			};

            *current = thresholded;
		}
	}
    return image;
}

PPM
applyBlur(PPM image)
{
    return image;
}

PPM
applySharpness(PPM image)
{
    return image;
}

PPM
applyRotation(PPM image)
{
    return image;
}

PPM
applyZoomIn(PPM image)
{
    return image;
}

PPM
applyZoomOut(PPM image)
{
    return image;
}