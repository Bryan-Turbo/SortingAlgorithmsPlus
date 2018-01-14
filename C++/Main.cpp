#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include "MergeSort.h"

using namespace std;
using namespace std::chrono;

vector<int> randomNums(int size)
{
    vector<int> nums(size);
    int num;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        num = rand() % size;
        nums[i] = num;
    }
    return nums;
}

long RunSorter(vector<int> numbers){
    milliseconds start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    vector<int> sorted = MergeSort::Sort(numbers);
    milliseconds stop = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    return (stop - start).count();
}

int main()
{
    const int size = 10000000;

    int sortRounds = 0;
    int maxSortRounds = 10;
    long totalSortTime = 0;
    while (sortRounds < maxSortRounds)
    {
        vector<int> numbers = randomNums(size);
        long sortingTime = RunSorter(numbers);
        cout << "the algorithm took " << sortingTime << "ms" << endl;
        totalSortTime += sortingTime;
        sortRounds++;
    }
    cout << "total sorting time was " << totalSortTime << "ms, and the average sorting time was " << totalSortTime / maxSortRounds << "ms" << endl;
    return 0;
}