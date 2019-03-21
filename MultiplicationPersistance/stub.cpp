#include <iostream>
#include <string>
#define to_digit(x)(x - '0')
using std::string;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

const unsigned int INIT_STEPS = 0;
const unsigned int BASE_TEN = 0;
const unsigned int OFFSET = 1;
const unsigned int MIN_INT = 1;

unsigned int Length(const char * str)
{
	unsigned int count = 0;
	while (*(str + count) != '\0')
	{
		count += 1;
	}
	return count;
}

unsigned int Per(const char * num, unsigned int steps)
{
	//Base case string length 1
	if (Length(num) == MIN_INT)
	{
		return steps;
	}

	//Do multiplication
	unsigned long long new_num = to_digit(*(num));
	for (unsigned int i = OFFSET; i < Length(num); ++i)
	{
		new_num *= to_digit(*(num + i));
	}

	//Convert number to string for easy use
	string new_str;
	new_str = to_string(new_num);
	steps += 1;

	//Call next Iteration
	cout << "Iteration " << steps << ": " << new_str << endl;
	return Per(new_str.c_str(), steps);
}

int main()
{
	char num[255];

	cout << "Multiplicitive Persistance of: ";
	cin >> num;

	cout << "Steps: " << Per(num, INIT_STEPS);

	return 0;
}