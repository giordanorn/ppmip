#ifndef FILTERS_H
#define FILTERS_H

#include "utils.h"

// All methods are immutable, i.e., does not change the original variable and returns a new instance.
PPM applyGreyscale(PPM);
PPM applyThresholding(PPM);
PPM applyBlur(PPM);
PPM applySharpness(PPM);
PPM applyRotation(PPM);
PPM applyZoomIn(PPM);
PPM applyZoomOut(PPM);

#endif