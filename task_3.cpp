#include <iostream>
using namespace std;

template<typename T>
void printArray(T* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void countingCount(T* arr, int size, int &posCount, int &negCount, int &zeroCount)
{
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            posCount++;
        } else if (arr[i] < 0) {
            negCount++;
        } else {
            zeroCount++;
        }
    }
}

template<typename T>
void initArrays(T* staticArr, int staticSize, T* &posArr, T* &negArr, T* &zeroArr)
{
    // index for each array separately
    int indexP = 0, indexN = 0, indexZ = 0;
    for (int i = 0; i < staticSize; ++i) {
        if (staticArr[i] > 0) {
            posArr[indexP++] = staticArr[i];
        } else if (staticArr[i] < 0) {
            negArr[indexN++] = staticArr[i];
        } else {
            zeroArr[indexZ++] = staticArr[i];
        }
    }
}

template<typename T>
void distributionArray(T* staticArr, int staticSize, T* &posArr, int &posSize, T* &negArr, int &negSize, T* &zeroArr, int &zeroSize)
{
    // create counters for size for new arrays
    int posCount = 0, negCount = 0, zeroCount = 0;
    countingCount(staticArr, staticSize, posCount, negCount, zeroCount);

    // create new arrays
    posSize = posCount;
    posArr = new T[posSize];

    negSize = negCount;
    negArr = new T[negSize];

    zeroSize = zeroCount;
    zeroArr = new T[zeroSize];

    // initialized arrays
    initArrays(staticArr, staticSize, posArr, negArr, zeroArr);
}

int main()
{
    int staticSize = 12;
    double staticArr[] = {15.3,1,2,3,4.5,-1,-2,-3,-4,0,0,0,0};

    int positiveSize = 0;
    double* positiveArr = nullptr;

    int negativeSize = 0;
    double* negativeArr = nullptr;

    int zeroSize = 0;
    double* zeroArr = nullptr;

    distributionArray(staticArr, staticSize,
              positiveArr,positiveSize,
              negativeArr,negativeSize,
                     zeroArr, zeroSize);

    return 0;
}