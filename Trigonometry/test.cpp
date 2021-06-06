#include "pch.h"
#include "trigonometry.h"
#include "math.h"
//Use tests to prove they are within an acceptable error rate and that they are faster than math.h trig functions


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Trig, SINE) {

	float error = 0.02;// < 2% Error
	float delta = 0.01;
	float std_sine = 0;
	float test_sine = 0;
	float measured_error = 0.0f;

	for (float angle = 0.001f; angle <= 5*PI; angle += delta) {

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

	for (float angle = 0.001; angle <= 5*PI; angle += delta) {
		std_cos = cos(angle);
		test_cos= Cosine(angle);
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

	for (float angle = 0.001; angle <= 5 * PI; angle += delta) {
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
