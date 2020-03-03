#pragma once

#define _USE_MATH_DEFINES
#include "maths.h"
#include <math.h>

namespace engine {
	namespace maths {

		inline float toRadiance(float degrees) {
			return degrees * (M_PI / 180.0f);
		}
	}
}