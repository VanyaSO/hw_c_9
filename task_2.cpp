#include <iostream>
using namespace std;

// Написати функцію, яка отримує покажчик на динамічний масив і його розмір.
// Функція повинна видалити з масиву всі прості числа і повернути покажчик на новий динамічний масив.


void initArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
}

bool isPrime(int number)
{
    if (number <= 1)
        return false;

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int* deletePrimeNumbers(int* arr, int &size)
{
    int newSize = 0;
    //
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    for (int i = 0, j = 0; i < size; ++i) {
        if(!isPrime(arr[i])) {
            newArr[j++] = arr[i];
        }
    }

    size = newSize;
    delete[] arr;

    return newArr;

}


int main()
{
    int SIZE = 10;
    int* arr = new int[SIZE];

    initArray(arr, SIZE);
    arr = deletePrimeNumbers(arr, SIZE);

    delete[] arr;
    return 0;
}