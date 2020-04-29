/**
 * @file main.cpp
 * @author Сааль Степан
 * @brief Инициализация рандомного массива, запуск сортировки, замер времени
 */

#include <iostream>
#include <iomanip>
#include "heapsort.h"
#include "bubblesort.h"
#include "array.h"
#include <ctime>
#include <fstream>

using namespace std;

/**
 * @brief Сортировка пузырьком и вывод информации
 * @param A Массив для сортировки
 * @param size Размер массива
 * @param visualize Требуется ли визуализайия
 */
void bubbleSortTest(int* A, int size, bool visualize)
{
    time_t start, end;
    ofstream sortedFile;

    BubbleSort bubbleSort(visualize);
    time(&start);
    cout << endl << "BubbleSort:" << endl << endl;
    int *sortedArrayA = bubbleSort.makeSort(A, size);
    time(&end);
    cout << endl << "Execution time BubbleSort: " << difftime(end, start) << " seconds";
    sortedFile.open("../BUBBLE_SORTED.txt");
    arrayToFile(sortedArrayA, size, sortedFile);
}
/**
 * @brief Сортировка кучей и вывод информации
 * @param A Массив для сортировки
 * @param size Размер массива
 * @param visualize Требуется ли визуализайия
 */
void heapSortTest(int* B, int size, bool visualize)
{
    time_t start, end;
    ofstream sortedFile;

    HeapSort heapSort(visualize);
    time(&start);
    cout << endl << "HeapSort:" << endl << endl;
    int *sortedArrayB = heapSort.makeSort(B, size);
    time(&end);
    cout << endl << "Execution time HeapSort: " << difftime(end, start) << " seconds";
    sortedFile.open("../HEAP_SORTED.txt");
    arrayToFile(sortedArrayB, size, sortedFile);
}

/**
 * @brief Инициализация массива, запуск сортировки, замер времени
 * @return 0
 */
int main()
{
    int size, *A = nullptr, *B = nullptr;
    bool visualize, fromFile;
    ifstream input;
    ofstream unsorted;

    cout << "Input size of array:" << endl;
    cin >> size;
    cout << "Do you need visualization? 1-yes 0-no" << endl;
    cin >> visualize;
    cout << "How to create array? 0-random 1-from 'INPUT.txt'" << endl;
    cin >> fromFile;

    if (! fromFile) {
        A = fillRandomArray(A, size);
        B = copyArray(A, size);
    } else {
        input.open("../INPUT.txt");
        A = arrayFromFile(A, size, input);
        B = copyArray(A, size);
    }
    unsorted.open("../UNSORTED.txt");
    arrayToFile(A, size, unsorted);

    bubbleSortTest(A, size, visualize);
    heapSortTest(B, size, visualize);

    return 0;
}
