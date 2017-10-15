#include <array>
#include <vector>

using namespace std;

class MergeSort
{
public:
    static vector<int> Sort(vector<int> input)
    {
        int size = input.size();
        int middle = size / 2;

        if (size <= 1) {
            return input;
        }

        vector<int> firstHalf = TakeFrom(input, 0, middle);
        vector<int> secondHalf = TakeFrom(input, middle, size);
        
        return Merge(Sort(firstHalf), Sort(secondHalf));
    }

private:
    static vector<int> Merge(vector<int> firstHalf, vector<int> secondHalf)
    {
        int firstHalfLength = firstHalf.size();
        int secondHalfLength = secondHalf.size();

        vector<int> sortedList(firstHalfLength + secondHalfLength);

        int firstHalfIndex = 0;
        int secondHalfIndex = 0;

        for (int i = 0; i < firstHalfLength + secondHalfLength; i++) {
            if (firstHalfIndex < firstHalfLength && secondHalfIndex < secondHalfLength) {
                if (firstHalf[firstHalfIndex] < secondHalf[secondHalfIndex]) {
                    sortedList[i] = firstHalf[firstHalfIndex];
                    firstHalfIndex++;
                } else {
                    sortedList[i] = secondHalf[secondHalfIndex];
                    secondHalfIndex++;
                }
            } else {
                if (firstHalfIndex >= firstHalfLength) {
                    sortedList[i] = secondHalf[secondHalfIndex];
                    secondHalfIndex++;
                } else if (secondHalfIndex >= secondHalfLength) {
                    sortedList[i] = firstHalf[firstHalfIndex];
                    firstHalfIndex++;
                }
            }
        }
        return sortedList;
    }

    static vector<int> TakeFrom(vector<int> input, int lower, int upper)
    {
        vector<int> outputList(upper - lower);
        for (int i = lower; i < upper; i++) {
            outputList[i - lower] = input[i];
        }
        return outputList;
    }
};
