#include "pch.h"
#include "trigonometry.h"

//Bhaskara’s approximation for Sine 
//Accuracy within 2% of the angle 
float Sine(float radians) {

	float mod = (int)(radians / PI);
	int is_odd = int(mod) % 2;

	radians = radians - mod*PI;

	assert(radians > 0);
	assert(radians < PI);

	if (0 == is_odd) {
		return (16 * radians * (PI - radians)) / (5 * PI * PI - 4 * radians * (PI - radians));
	}
	else {
		return -(16 * radians * (PI - radians)) / (5 * PI * PI - 4 * radians * (PI - radians)) ;
	}
}

float Cosine(float radians) {
	//I'll probably not fix this because this is just too easy
	return Sine(radians + PI/2);	//alternative function: ((PI*PI - 4*radians*radians) / (PI*PI + radians*radians));
}

float Tangent(float radians) {
	return Sine(radians) / Cosine(radians);
}

