// Naomi Dion-Gokan
// CptS 121, Fall 2021; Lab Section 1
// Programming Assignment 2
// September 15, 2021

// This program prints out a modular approach to the equation evaluator.
// We will insert inputs and get the outputs of a function.
// We will use the equations we have to transform them in functions in order to use and view them better. 
// This project will be separated and at the same time linked three files.
// We will be able to have a description, function and calculation of some equations.
// We will develop a better and effective method for our codes.
// We will find a serie resistance, a total sales tax, a volume of a pyramid, an encoding character.
// We will also find a distance between two points and use a general equation to find a solution.

#include "function.h"

int main(void)
{ 
	// 1. Calculation of Series Resistance based on a modular approach
	
	int R1 = 0, R2 = 0, R3 = 0;
	int calculate_series_resistance = 0;
	calculate_series_resistance = series_resistance(R1, R2, R3);
	

	// 2. Calculation for total sales tax

	double item_cost = 0.0, sales_tax_rate = 0.0, calculate_total_sales_tax = 0.0;
	calculate_total_sales_tax = total_sales_tax(item_cost, sales_tax_rate);

	// 3. Calculation for the volume of a right rectangular pyramid

	double l = 0.0, w = 0.0, h = 0.0, calculate_volume_pyramid = 0.0;
	calculate_volume_pyramid = volume_pyramid(l, w , h);

	// 4. Calculation for the total parallel resistance

	double calculate_total_parallel_resistance = 0.0;  
	calculate_total_parallel_resistance = total_parallel_resistance(R1, R2, R3);

	// 5. Calculation for the character encoding 

	char plaintext_character = '/0'; int shift = 0;
	char calculate_encoded_character;
	calculate_encoded_character = encoded_character(plaintext_character, 'a', 'A', shift);

	// 6. Calculation for distance between two points

	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, calculate_distance = 0.0;
	calculate_distance = distance(x1, x2, y1, y2);

	// 7. Calculation of the general equation

	double y = 0.0, z = 0.0, x = 0.0, calculate_equation = 0.0;
	int a = 0; 
	calculate_equation = equation (y, z, x, a);
	
	return 0;

} // end of main ()

 