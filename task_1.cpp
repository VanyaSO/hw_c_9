#include <iostream>
using namespace std;
// Написати такі функції для роботи з динамічним масивом:

// Функція розподілу динамічної пам'яті
int* getPointer(int size)
{
    return new int[size];
}

// Функція ініціалізації динамічного масиву.
void initArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 10;
    }
}

// Функція друку динамічного масиву
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція видалення динамічного масиву
void deleteArray(int* arr)
{
    delete[] arr;
}

// Функція додавання елемента в кінець масиву.
int* addElement(int* arr, int &size, int el)
{
    int* newArr = getPointer(size+1);
    // copy array
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    // add new elements
    newArr[size] = el;
    // update size array
    size++;
    deleteArray(arr);

    return newArr;
}

// Функція вставки елемента за вказаним індексом.
int* insertElByIndex(int* arr, int size, int index, int el)
{
    if (index < 0 || index >= size) return arr;

    int* newArr = getPointer(size);
    for (int i = 0; i < size; ++i) {
        if(i == index)
            newArr[index] = el;
        else
            newArr[i] = arr[i];
    }
    deleteArray(arr);

    return newArr;
}

// Функція видалення елемента за вказаним індексом
int* deleteElByIndex(int* arr, int &size, int index)
{
    if (index < 0 || index >= size) return arr;

    int* newArr = getPointer(size-1);
    for (int i = 0, j = 0; i < size; ++i) {
        if (i == index)
            j++;
        newArr[i] = arr[i + j];

    }
    size--;
    deleteArray(arr);

    return newArr;
}

int getValue(char symb)
{
    int value;
    switch (symb) {
        case 's':
            cout << "Enter size for array: ";
            break;
        case 'e':
            cout << "Enter new element: ";
            break;
        case 'i':
            cout << "Enter index: ";
            break;
    }
    cin >> value;

    return value;
}

int main()
{
    srand(time(0));
    int SIZE = getValue('s');
    int* arr = getPointer(SIZE);

    initArray(arr, SIZE);
    printArray(arr, SIZE);

    arr = addElement(arr, SIZE, getValue('e'));
    printArray(arr, SIZE);

    arr = insertElByIndex(arr, SIZE, getValue('i'), getValue('e'));
    printArray(arr, SIZE);

    arr = deleteElByIndex(arr, SIZE, getValue('i'));
    printArray(arr, SIZE);

    delete[] arr;

    return 0;
}
