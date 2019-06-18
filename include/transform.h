#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "utils.h"

typedef enum 
{
	DEG_90,
	DEG_180,
	DED_270
} Rotation;

PPM applyRotation(PPM, Rotation);
PPM applyScaleUp(PPM);
PPM applyScaleDown(PPM);

#endif
