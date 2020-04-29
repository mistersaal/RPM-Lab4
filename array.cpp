/**
 * @file array.cpp
 * @author Сааль Степан
 * @brief Реализация функций для работы с массивами
 */

#include <random>
#include <iostream>
#include <fstream>

using namespace std;

int* fillRandomArray(int* A, int size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size * 2);

    A = new int[size];
    for(int i = 0; i < size; i++){
        A[i] = dis(gen);
    }
    return A;
}

int* copyArray(const int* A, int size)
{
    int *B = new int [size];
    for (int i = 0; i < size; ++i) {
        B[i] = A[i];
    }
    return B;
}

void arrayToFile(int *A, int size, ofstream &file) {
    for(int i = 0; i < size; i++){
        file << A[i] << " ";
    }
    file << endl << endl;
}

int* arrayFromFile(int *A, int size, ifstream &file) {
    A = new int[size];
    for(int i = 0; i < size; i++){
        file >> A[i];
    }
    return A;
}
