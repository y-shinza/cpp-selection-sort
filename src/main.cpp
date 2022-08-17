#include <iostream>
#include <time.h>

void initArray(int* array);
void selectionSort(int* array);

const int ARRAY_SIZE = 10;
const int MAX_NUMBER = 99;

int main()
{
    int array[ARRAY_SIZE];

    initArray(array);
    selectionSort(array);

    return 0;
}

void printArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        std::cout << array[i] << ", ";

    std::cout << std::endl;
}

void initArray(int* array)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++)
        array[i] = rand() % MAX_NUMBER + 1;

    std::cout << "初期値" << std::endl;
    printArray(array);
}

void selectionSort(int* array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int min_index = i;

        for (int j = i; j < ARRAY_SIZE; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        int tmp = array[i];
        array[i] = array[min_index];
        array[min_index] = tmp;

        std::cout << i + 1 << "回目のソート" << std::endl;
        printArray(array);
    }
}