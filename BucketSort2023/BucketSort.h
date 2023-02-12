#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class CBucketSort
{

private:
	void GatheringPass(std::vector<int>  buckets_2d[10], std::vector<int>& output);
	void DistributionPass(std::vector<int>& input_list, int index_number, std::vector<int>  buckets_2d[10]);
	int DigitFromInt(int number, int index);
public:
	CBucketSort()
	{

	}
	vector<int> BucketSort(std::vector<int> input_list);
	int GetAmountDigits(std::vector<int>& input_list);
};
