#include "pch.h"
#include "trigonometry.h"


float ToRadians(float degrees) {
	return (degrees / 180) * PI;
}


//Bhaskara’s approximation for Sine 
//Accuracy within 2.1% 
//Further improve performance by using Bit shifts where multiplying by powers of 2
float Sine(float radians) {

	float mod = (int)(radians / PI);
	int is_odd = int(mod) % 2;

	radians = radians - mod*PI;

	if (0 == is_odd) {
		return (16 * radians * (PI - radians)) / (5 * PI * PI - 4 * radians * (PI - radians));
	}
	else {
		return -(16 * radians * (PI - radians)) / (5 * PI * PI - 4 * radians * (PI - radians)) ;
	}
}

//I'll probably not fix this because this is just too easy to reuse Sine
float Cosine(float radians) {
	return Sine(radians + PI/2);	//alternative function: ((PI*PI - 4*radians*radians) / (PI*PI + radians*radians));
}

float Tangent(float radians) {
	return Sine(radians) / Cosine(radians);
}

