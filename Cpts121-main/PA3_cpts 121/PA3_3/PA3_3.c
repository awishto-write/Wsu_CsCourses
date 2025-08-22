#include "grade.h"

int read_integer(FILE* infile)
{
	int num = 0;
	fscanf(infile, "%d\n", &num);

	return num;
}

double read_double(FILE* infile)
{
	double num = 0.0;
	fscanf(infile, "%lf\n", &num);

	return num;
}

void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}

double sum_gpa(double gpa1, double gpa2, double gpa3, double gpa4, double gpa5)
{
	double sum_gpa = gpa1 + gpa2 + gpa3 + gpa4 + gpa5;

	return sum_gpa;
}

int sum_class(int class1, int class2, int class3, int class4, int class5)
{
	int sum_class = class1 + class2 + class3 + class4 + class5;

	return sum_class;
}

double sum_age(double age1, double age2, double age3, double age4, double age5)
{
	double sum_age = age1 + age2 + age3 + age4 + age5;

	return sum_age;
}

double mean_gpa(double calculate_sum_gpa, int total_number)
{
	double mean_gpa = calculate_sum_gpa / total_number;

	return mean_gpa;
}

double mean_class(double calculate_sum_class, int total_number)
{
	double mean_class = calculate_sum_class / total_number;

	return mean_class;
}

double mean_age(double calculate_sum_age, int total_number)
{
	double mean_age = calculate_sum_age / total_number;

	return mean_age;
}

double deviation_gpa(double number, double calculate_mean_gpa)
{
	double deviation_gpa = number - calculate_mean_gpa;

	return deviation_gpa;
}

double variance(double calculate_deviation_gpa1, double calculate_deviation_gpa2, double calculate_deviation_gpa3,
	double calculate_deviation_gpa4, double calculate_deviation_gpa5, int number)
{
	double variance = (pow(calculate_deviation_gpa1, 2) + pow(calculate_deviation_gpa2, 2) + pow(calculate_deviation_gpa3, 2) +
		pow(calculate_deviation_gpa4, 2) + pow(calculate_deviation_gpa5, 2)) / number;

	return variance;
}

double standard_deviation(double calculate_variance)
{
	double standard_deviation = sqrt(calculate_variance);

	return standard_deviation;
}

double find_min(double number1, double number2, double number3, double number4, double number5)
{
	if ((number1 < number4) && (number1 < number2) && (number1 < number3) && (number1 < number5))
	{
		return number1;
	}

	else if ((number2 < number1) && (number2 < number4) && (number2 < number3) && (number2 < number5))
	{
		return number2;
	}

	else if ((number3 < number1) && (number3 < number2) && (number4 < number3) && (number3 < number5))
	{
		return number3;
	}

	else if ((number4 < number1) && (number4 < number2) && (number4 < number3) && (number4 < number5))
	{
		return number4;
	}
	else if ((number5 < number1) && (number5 < number2) && (number5 < number3) && (number5 < number4))
	{
		return number5;
	}
	else
		return 0.0;
}

double find_max(double number1, double number2, double number3, double number4, double number5)
{
	if ((number1 > number4) && (number1 > number2) && (number1 > number3) && (number1 > number5))
	{
		return number1;
	}

	else if ((number2 > number1) && (number2 > number3) && (number2 > number4) && (number2 > number5))
	{
		return number2;
	}

	else if ((number3 > number1) && (number3 > number2) && (number3 > number4) && (number3 > number5))
	{
		return number3;
	}

	else if ((number4 > number1) && (number4 > number2) && (number4 > number3) && (number4 > number5))
	{
		return number4;
	}
	else if ((number5 > number1) && (number5 > number2) && (number5 > number3) && (number5 > number4))
	{
		return number5;
	}
	else
		return 0.0; //max found
}