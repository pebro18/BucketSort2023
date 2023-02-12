#include "BucketSort.h"

vector<int> CBucketSort::BucketSort(std::vector<int> input_list)
{
	int amount_negative_numbers = 0;

	// determines the amount needed for the loop
	int amount_digits = get_amount_digits(input_list);

	for (int i = 0; i < amount_digits; i++)
	{
		vector<int> neg_numbers;
		vector<int> pos_numbers;

		vector<int> neg_buckets_2d[10];
		vector<int> buckets_2d[10];

		vector<int> output;

		// filter out positive andnegative numbers out of the array into their own vector
		// negative numvbers become positive for ease of use in the distribution pass
		for (size_t i = 0; i < input_list.size(); i++)
		{
			if (input_list[i] >= 0) pos_numbers.push_back(input_list[i]); // 1 bool 1 write
			else neg_numbers.push_back(input_list[i] * -1); // 
		}
		// determine the amount of negative numbers to be used at the end
		amount_negative_numbers = neg_numbers.size();

		// Distribution of both number vectors into their own related 2d bucket
		distribution_pass(neg_numbers, i, neg_buckets_2d);
		distribution_pass(pos_numbers, i, buckets_2d);

		//gathering pass of negative numbers first
		gathering_pass(neg_buckets_2d, output);
		// Change the negative numbers back into negatives
		for_each(output.begin(), output.end(), [&](int& i) {i *= -1; });
		//gathering pass for the positive numbers
		gathering_pass(buckets_2d, output);
		input_list = output;
	}

	// at the end of the sorting turn the the negative numbers from asc to dsc
	std::reverse(input_list.begin(), input_list.begin() + amount_negative_numbers);
	return input_list;
}

// Distributes all numbers into their respective buckets based on given index number into a 2d array
void CBucketSort::distribution_pass(std::vector<int>& input_list, int index_number, vector<int> buckets_2d[10])
{
	for (int i = 0; i < input_list.size(); i++)
	{
		int single_number = int_digit(input_list[i], index_number);
		buckets_2d[single_number].push_back(input_list[i]);
	}
}

// Collects all values from the 2d array of vectors back into a 1d vector
void CBucketSort::gathering_pass(std::vector<int>  buckets_2d[10], vector<int>& output)
{
	for (int i = 0; i < 10; i++)
	{
		vector<int> row_data = buckets_2d[i];
		output.insert(output.end(), row_data.begin(), row_data.end());
	}
}

// function gets the digit of a number based on the given parameter
int CBucketSort::int_digit(int number, int digit)
{
	// Changes the number into a string
	// A string is an array of chars
	auto numbers_in_string = to_string(number);
	int offset = numbers_in_string.size() - 1;
	
	// underflow check
	// works similar to padding when parameter digit > amount digits of parameter number
	// digit = 2
	// number = 001 <-- return 0
	// number = 312 <-- skips this
	if ((offset - digit) < 0)
	{
		return 0;
	}

	// Gets the right number based on the given digit parameter
	// IDE warning for possible unchecked underflow
	char chosen_number = numbers_in_string[offset - digit];

	// casts the char back into a int using a bit of ascii trickery
	return (int)(chosen_number - '0');

}

int CBucketSort::get_amount_digits(std::vector<int>& input_list)
{
	// determine max and min of the given input vector
	auto max = max_element(input_list.begin(), input_list.end());
	auto min = min_element(input_list.begin(), input_list.end());

	// casts max and min into spring
	auto max_in_string = to_string(*max);
	auto min_in_string = to_string((*min * -1));

	// checks size of array
	if (max_in_string.size() >= min_in_string.size())
	{
		return max_in_string.size();
	}
	else
	{
		return min_in_string.size();
	}
}