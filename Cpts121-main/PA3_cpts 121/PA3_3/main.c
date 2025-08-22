// Naomi Dion-Gokan
// 09/ 29/ 21
// CPT_S 121
// Programming Assignment 3
// This program will open, read and write some files.

#include "grade.h"

int main(void)
{

	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0,
		age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;
	int id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0,
		class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0;

	FILE* infile = NULL, * outfile = NULL;

	infile = fopen("input.dat", "r"); // read file
	outfile = fopen("output.dat", "w"); // write file

	id1 = read_integer(infile);      gpa1 = read_double(infile);
	class1 = read_integer(infile);   age1 = read_double(infile);

	id2 = read_integer(infile);      gpa2 = read_double(infile);
	class2 = read_integer(infile);   age2 = read_double(infile);

	id3 = read_integer(infile);      gpa3 = read_double(infile);
	class3 = read_integer(infile);   age3 = read_double(infile);

	id4 = read_integer(infile);      gpa4 = read_double(infile);
	class4 = read_integer(infile);   age4 = read_double(infile);

	id5 = read_integer(infile);      gpa5 = read_double(infile);
	class5 = read_integer(infile);   age5 = read_double(infile);

	int total_number = 5;

	// 1. Sum of gpa
	double calculate_sum_gpa = 0.0;
	calculate_sum_gpa = sum_gpa(gpa1, gpa2, gpa3, gpa4, gpa5);
	printf("sum_gpa: %.2lf\n", calculate_sum_gpa);

	// 2. Sum of class
	int calculate_sum_class = 0;
	calculate_sum_class = sum_class(class1, class2, class3, class4, class5);
	printf("sum_class: %d\n", calculate_sum_class);

	// 3. Sum of age
	double calculate_sum_age = 0.0;
	calculate_sum_age = sum_age(age1, age2, age3, age4, age5);
	printf("sum_age: %.2lf\n", calculate_sum_age);

	// 4. Mean of gpa
	double calculate_mean_gpa = 0.0;
	calculate_mean_gpa = mean_gpa(calculate_sum_gpa, total_number);
	printf("mean_gpa: %.2lf\n", calculate_mean_gpa);

	print_double(outfile, calculate_mean_gpa);

	// 5. Mean of class
	double calculate_mean_class = 0.0;
	calculate_mean_class = mean_class(calculate_sum_class, total_number);
	printf("mean_class: %.2lf\n", calculate_mean_class);

	print_double(outfile, calculate_mean_class);

	// 6. Mean of age
	double calculate_mean_age = 0.0;
	calculate_mean_age = mean_gpa(calculate_sum_age, total_number);
	printf("mean_age: %.2lf\n", calculate_mean_age);

	print_double(outfile, calculate_mean_age);

	// 7. Deviation of each gap
	double calculate_deviation_gpa1 = 0.0, calculate_deviation_gpa2 = 0.0, calculate_deviation_gpa3 = 0.0,
		calculate_deviation_gpa4 = 0.0, calculate_deviation_gpa5 = 0.0;

	calculate_deviation_gpa1 = deviation_gpa(gpa1, calculate_mean_gpa);
	printf("deviation_gp1: %.2lf\n", calculate_deviation_gpa1);

	calculate_deviation_gpa2 = deviation_gpa(gpa2, calculate_mean_gpa);
	printf("deviation_gp2: %.2lf\n", calculate_deviation_gpa2);

	calculate_deviation_gpa3 = deviation_gpa(gpa3, calculate_mean_gpa);
	printf("deviation_gp3: %.2lf\n", calculate_deviation_gpa3);

	calculate_deviation_gpa4 = deviation_gpa(gpa4, calculate_mean_gpa);
	printf("deviation_gp4: %.2lf\n", calculate_deviation_gpa4);

	calculate_deviation_gpa5 = deviation_gpa(gpa5, calculate_mean_gpa);
	printf("deviation_gp5: %.2lf\n", calculate_deviation_gpa5);

	// 8. Variance of gpas
	double calculate_variance = 0.0;
	calculate_variance = variance(calculate_deviation_gpa1, calculate_deviation_gpa2, calculate_deviation_gpa3,
		calculate_deviation_gpa4, calculate_deviation_gpa5, total_number);
	printf("variance_gpas: %.2lf\n", calculate_variance);

	//9. Standard Deviation of gpas
	double calculate_standard_deviation = 0.0;
	calculate_standard_deviation = standard_deviation(calculate_variance);
	printf("standard_deviation: %.2lf\n", calculate_standard_deviation);

	print_double(outfile, calculate_standard_deviation);

	// 11. Minimun gpa
	double get_find_min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	printf("find_min: %.2lf\n", get_find_min);

	print_double(outfile, get_find_min);

	// 10. Maximum gpa
	double get_find_max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	printf("find_max: %.2lf\n", get_find_max);

	print_double(outfile, get_find_max);


	// Print 

	fclose(infile);
	fclose(outfile);

	return 0;
}