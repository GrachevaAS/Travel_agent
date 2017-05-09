#include <iostream>

#include <vector>
#include <stdlib.h>

double convert(double input) {
	return round(input * 5);
}
void normalDistribution(int count, std::vector<std::pair<double, double> >& points) {
	int i = 0;
	while (i < count) {
		double first_value = static_cast<double>(rand() * 2) / RAND_MAX - 1;
		double second_value = static_cast<double>(rand() * 2) / RAND_MAX - 1;
		double s = pow(first_value, 2) + pow(second_value, 2);
		if (s > 1 || s == 0)
			continue;
		// std::cout << s << " ";
		i++;
		first_value = first_value * sqrt(-2 * log(s) / s);
		second_value = second_value * sqrt(-2 * log(s) / s);
		first_value = convert(first_value);
		second_value = convert(second_value);
		points.push_back(std::make_pair(first_value, second_value));
	}
}