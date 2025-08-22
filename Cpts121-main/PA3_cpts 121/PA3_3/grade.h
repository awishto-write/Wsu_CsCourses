#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double read_double(FILE* infile);
int read_integer(FILE* infile);
void print_double(FILE* outfile, double number);

double sum_gpa(double gpa1, double gpa2, double gpa3, double gpa4, double gpa5);

int sum_class(int class1, int class2, int class3, int class4, int class5);

double sum_age(double age1, double age2, double age3, double age4, double age5);

double mean_gpa(double calculate_sum_gpa, int total_number);

double mean_class(double calculate_sum_class, int total_number);

double mean_age(double calculate_sum_age, int total_number);

double deviation_gpa(double number, double calculate_mean_gpa);

double variance(double calculate_deviation_gpa1, double calculate_deviation_gpa2, double calculate_deviation_gpa3,
	double calculate_deviation_gpa4, double calculate_deviation_gpa5, int number);

double standard_deviation(double variance);

double find_min(double number1, double number2, double number3, double number4, double number5);

double find_max(double number1, double number2, double number3, double number4, double number5);
