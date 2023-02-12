#include "BucketSort.h"
#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std::chrono;

void CreateRandomArray(std::vector<int>& vector,int amount_numbers,int range , int range_into_negatives)
{
    for (int i = 0; i < amount_numbers; i++)
    {
        vector.push_back(std::rand() % range + (-range_into_negatives));
    }
}

void RunTest(int amount_numbers, int range, int range_into_negatives)
{
    CBucketSort bucket;

    cout << "Start Test" << endl;
    vector<int> test_array1;
    vector<int> output1;
    CreateRandomArray(test_array1, amount_numbers,range , range_into_negatives);

    auto start = high_resolution_clock::now();
    output1 = bucket.BucketSort(test_array1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Results: " << duration.count() << " Microseconds"<< endl;
}


int main()
{
    cout << "1000 random positive numbers" << endl;
    RunTest(1000, 10000, 0);

    cout << "10000 random positive numbers" << endl;
    RunTest(10000, 010000, 0);

    cout << "30000 random positive numbers" << endl;
    RunTest(30000, 300000, 0);

    cout << endl;

    cout << "1000 random numbers with negatives" << endl;
    RunTest(1000, 10000, 500);

    cout << "1000 random numbers with negatives" << endl;
    RunTest(10000, 100000, 5000);

    cout << "30000 random numbers with negatives" << endl;
    RunTest(30000, 300000, 15000);

    return 0;
}
