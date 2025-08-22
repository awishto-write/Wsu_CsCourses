// Naomi Dion-Gokan
// Programming Assignment 1/ CPTS 121
// September 08, 2021

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#include <stdio.h>
#include <math.h>

int main(void)

{
	//1. Total Series Resistance

	int R1 = 0, R2 = 0, R3 = 0, series_resistance = 0;

	printf("Choose the values for the three resistors: ");
	scanf("%d %d %d", &R1, &R2, &R3);

	series_resistance = R1 + R2 + R3;
	printf("Total series_resistance: series_resistance = R1 + R2 + R3 = %d %d %d", R1, R2, R3);
	printf("= %d\n", series_resistance);

	// 2. Total Sales Tax

	double sales_tax_rate = 0.0, item_cost = 0.0, total_sales_tax = 0.0;

	printf("Choose the value for sales_tax_rate and the value for item_cost: ");
	scanf("%lf %lf", &sales_tax_rate, &item_cost);

	total_sales_tax = sales_tax_rate * item_cost;
	printf("total_sales_tax = sales_tax_rate * item_cost = %lf %lf", sales_tax_rate, item_cost);
	printf("= %lf\n", total_sales_tax);

	// 3. Volume of a Right Rectangular Pyramid

	double l = 0.0, w = 0.0, h = 0.0, volume_pyramid = 0.0;

	printf("Choose the value for l, w, h: ");
	scanf("%lf %lf %lf", &l, &w, &h);

	volume_pyramid = (l * w * h) / 3;
	printf("volume_pyramid = (l * w * h) / 3 = %lf %lf %lf", l, w, h);
	printf("= %lf\n", volume_pyramid);

	// 4. Total Parallel Resistance

	double parallel_resistance = 0.0;

	printf("Enter new values for R1, R2 and R3: ");
	scanf("%d %d %d", &R1, &R2, &R3);

	parallel_resistance = 1 / ((double)1 / R1 + (double)1 / R2 + (double)1 / R3);
	printf("parallel_resistance = 1/ (1 / %d + 1 / %d + 1 / %d)", R1, R2, R3);
	printf("= %lf\n", parallel_resistance);

	// 5. Character Encoding

	char plaintext_character = '/0';
	printf("Enter a character: ");
	while (getchar() != '\n');
	scanf(" %c", &plaintext_character);

	int shift = 0;
	printf("Enter the 'shift' number: ");
	scanf("%d", &shift);

	char encoded_character = (plaintext_character - 'a') + 'A' - shift;
	printf("encoded_character = %c\n\n", encoded_character);

	// 6. Distance Between Two Points

	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;
	printf("Choose the values for x1, x2, y1 and y2: ");
	scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	printf("distance = sqrt (( %lf- %lf ) ^ 2 + ( %lf - %lf ) ^ 2 ", x1, x2, y1, y2);
	printf("= %lf\n", distance);

	// 7. General Equation

	double y = 0.0, z = 0.0, x = 0.0;
	int a = 0;

	printf("choose the values for y, z, x: ");
	scanf("%lf %lf %lf", &y, &z, &x);
	printf("choose the value of a: ");
	scanf("%d", &a);

	printf("equation: y= %lf / (3/17) - %lf + %lf / (%d %% 2) + PI", y, z, x, a);
	y = y / ((double)3 / (double)17) - z + x / (a % 2) + PI;
	printf("= %lf\n", y);

	return 0;

}