#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class CBucketSort
{

private:
	void gathering_pass(std::vector<int>  buckets_2d[10], std::vector<int>& output);
	void distribution_pass(std::vector<int>& input_list, int index_number, std::vector<int>  buckets_2d[10]);
	int int_digit(int number, int index);
public:
	CBucketSort()
	{

	}
	vector<int> BucketSort(std::vector<int> input_list);
	int get_amount_digits(std::vector<int>& input_list);
};
