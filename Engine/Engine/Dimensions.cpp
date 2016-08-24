#include "Dimensions.h"

void Dimensions::grow(float multiplier)
{
    height_ *= multiplier;
    width_ *= multiplier;
}
