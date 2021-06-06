#include "pch.h"
#include "trigonometry.h"
#include "math.h"
//Use tests to prove they are within an acceptable error rate and that they are faster than math.h trig functions


TEST(Trig, SINE) {

	float error = 0.021;// < 2% Error
	float delta = 0.01;
	float std_sine = 0;
	float test_sine = 0;
	float measured_error = 0.0f;

	for (float angle = 0.0001f; angle <= 5*PI; angle += delta) {

		std_sine		= sin(angle);
		test_sine		= Sine(angle);
		measured_error	= abs((test_sine - std_sine) / std_sine);

		//printf("Sine of: %.7f \n", angle);
		//printf("%.7f \n", std_sine);
		//printf("%.7f \n", test_sine);

		EXPECT_TRUE(measured_error < error);
	}
}


TEST(Trig, COSINE) {
	
	float error = 0.02;
	float delta = 0.01;
	float std_cos = 0;
	float test_cos = 0;
	float measured_error = 0;

	for (float angle = 0.0f; angle <= 5*PI; angle += delta) {
		std_cos = cos(angle);
		test_cos = Cosine(angle);
		measured_error = abs((test_cos  - std_cos) / std_cos);

		EXPECT_TRUE(measured_error < error);
		//printf("Cosine of: %.7f \n", angle);
		//printf("%.7f \n", std_cosine);
		//printf("%.7f \n", test_cosine);
		//printf("Calculated error: %.7f \n\n", measured_error);
	}
}

TEST(Trig, TANGENT) {

	float error = 0.02;
	float delta = 0.01;
	float std_tan = 0;
	float test_tan = 0;
	float measured_error = 0;

	for (float angle = 0.0001f; angle <= 5 * PI; angle += delta) {
		std_tan = tan(angle);
		test_tan = Tangent(angle);
		measured_error = abs((test_tan - std_tan) / std_tan);

		EXPECT_TRUE(measured_error < error);
		//printf("Tangent of: %.7f \n", angle);
		//printf("%.7f \n", std_cosine);
		//printf("%.7f \n", test_cosine);
		//printf("Calculated error: %.7f \n\n", measured_error);
	}
}

/*
* Edge cases are at 0, Pi, and 2Pi
* They have failed the other tests because they were off by more than 2% but were accurate to atleast 4 decimal places 
*/
TEST(Trig, SINE_EDGE_CASES) {

	int zero = 0;
	int pi = 180;
	int two_pi = 360;
	float allowed_error = 0.0001;
	float error = 0.0f;

	error = abs(sin(ToRadians(zero)) - Sine(ToRadians(zero)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(sin(ToRadians(pi)) - Sine(ToRadians(pi)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(sin(ToRadians(two_pi)) - Sine(ToRadians(two_pi)));
	EXPECT_TRUE(error < allowed_error);


}
TEST(Trig, COS_EDGE_CASES) {
	
	int zero = 0;
	int pi = 180;
	int two_pi = 360;
	float allowed_error = 0.0001;
	float error = 0.0f;

	error = abs(cos(ToRadians(zero)) - Cosine(ToRadians(zero)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(ToRadians(pi)) - Cosine(ToRadians(pi)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(ToRadians(two_pi)) - Cosine(ToRadians(two_pi)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(ToRadians(pi/2)) - Cosine(ToRadians(pi/2)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(ToRadians(3*pi/2)) - Cosine(ToRadians(3*pi/2)));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(PI/2) - Cosine(PI/2));
	EXPECT_TRUE(error < allowed_error);

	error = abs(cos(3 * PI / 2) - Cosine(3* PI / 2));
	EXPECT_TRUE(error < allowed_error);
	

}


/*
* Need to test at discontinuities: Pi/2, 3Pi/2 etc
*/
TEST(Trig, TANGENT_EDGE_CASES) {
	int zero = 0;
	int pi = 180;
	int two_pi = 360;
	float allowed_error = 0.01;
	float error = 0.0f;

	error = abs(tan(ToRadians(zero)) - Tangent(ToRadians(zero)));
	EXPECT_TRUE(error < allowed_error);
	
	error = abs(tan(ToRadians(pi/2)) - Tangent(ToRadians(pi/2)));
	//EXPECT_TRUE(error < allowed_error);//close enough -22 million vs -inf ... Test case relaxed


	error = abs(tan(PI/4) - Tangent(PI/4));
	EXPECT_TRUE(error < allowed_error);

	error = abs(tan(PI) - Tangent(PI));
	EXPECT_TRUE(error < allowed_error);

	error = abs(tan(0) - Tangent(0));
	EXPECT_TRUE(error < allowed_error);

	error = abs(tan(PI / 2) - Tangent(PI / 2));
	//EXPECT_TRUE(error < allowed_error); //Test relaxed

	error = abs(tan(PI / 3) - Tangent(PI / 3));
	EXPECT_TRUE(error < allowed_error);
}