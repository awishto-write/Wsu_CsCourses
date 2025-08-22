
#include "function.h"

//1. Series Resistance

int series_resistance(int R1, int R2, int R3)
{
	printf("Function for series_resistance = R1 + R2 + R3\n");

	printf("Choose the values for the three resistors: ");
	scanf("%d %d %d", &R1, &R2, &R3);

	int series_resistance = R1 + R2 + R3;
	printf("Total series_resistance: series_resistance = R1 + R2 + R3 = %d %d %d", R1, R2, R3);
	printf("= %d\n\n", series_resistance);


	return series_resistance;
}

//2. Total sales tax

double total_sales_tax(double item_cost, double sales_tax_rate)
{
	printf("Function for total_sales_rate = item_cost * sales_tax_rate\n");

	printf("Choose the value for item_cost and the value for sales_tax_rate: ");
	scanf("%lf %lf", &item_cost, &sales_tax_rate);

	double total_sales_tax = item_cost * sales_tax_rate;
	printf("total_sales_tax = item_cost * sales_tax_rate = %lf %lf", item_cost, sales_tax_rate);
	printf("= %lf\n\n", total_sales_tax);

	return total_sales_tax;
}


//3. Volume of a pyramid

double volume_pyramid(double l,double w, double h)
{
	printf("Function for volume_pyramid = (l * w * l)/3\n");

	printf("Choose the value for l, w, h: ");
	scanf("%lf %lf %lf", &l, &w, &h);

	double volume_pyramid = (l * w * h) / 3;
	printf("volume_pyramid = (l * w * h) / 3 = %lf %lf %lf", l, w, h);
	printf("= %lf\n\n", volume_pyramid);

	return volume_pyramid;
}

//4. Total parallel resistance

double total_parallel_resistance(double R1, double R2, double R3)
{
	printf("Function for total_parallel_resistance = 1/ (1 / R1 + 1 / R2 + 1 / R3)\n");

	printf("Enter new values for R1, R2 and R3: ");
	scanf("%lf %lf %lf", &R1, &R2, &R3);

	double total_parallel_resistance = 1 / ((double)1 / R1 + (double)1 / R2 + (double)1 / R3);
	printf("parallel_resistance = 1/ (1 / %lf + 1 / %lf + 1 / %lf)", R1, R2, R3);
	printf("= %lf\n\n", total_parallel_resistance);

	return total_parallel_resistance;
}

//5. Character encoded

char encoded_character(char plaintext_character, int shift)
{
	printf("Function for encoded_character = (plaintext_character - 'a') + 'A' - shift\n");

	printf("Enter a character: ");
	while (getchar() != '\n');
	scanf(" %c", &plaintext_character);

	printf("Enter the 'shift' number: ");
	scanf("%d", &shift);

	char encoded_character = (plaintext_character - 'a') + 'A' - shift;
	printf("encoded_character = %c\n\n", encoded_character);

	return encoded_character;
}

// 6. Distance between two Points

double distance(double x1, double x2, double y1, double y2)
{
	printf("Function for distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))\n");

	printf("Choose the values for x1, x2, y1 and y2: ");
	scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

	double distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	printf("distance = sqrt (( %lf- %lf ) ^ 2 + ( %lf - %lf ) ^ 2 ", x1, x2, y1, y2);
	printf("= %lf\n\n", distance);

	return distance;
}

// 7. Equation

double equation (double y, double z, double x, int a)
{
	printf("Function for equation = y = y/ (3/17) -z + x / (a%2) + PI\n");

	printf("choose the values for y, z, x: ");
	scanf("%lf %lf %lf", &y, &z, &x);
	printf("choose the value of a: ");
	scanf("%d", &a);

	printf("y= %lf / (3/17) - %lf + %lf / (%d %% 2) + PI", y, z, x, a);
    double equation= y= y / ((double)3 / (double)17) - z + x / (a % 2) + PI;
	printf("= %lf\n\n", y);
	
	return equation;
}