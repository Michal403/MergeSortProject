/**
 * @file MergeSortApp.cpp
 * @brief Główny plik programu uruchamiający algorytm.
 * @author Marecik Michał
 */
#include <iostream>
#include <vector>
#include "MergeSort.h"

int main() {
    std::cout << "=== Projekt MergeSort - Michal ===" << std::endl;
    // Zadanie: Dwie instancje tablic (int oraz double)
    std::vector<int> tablicaInt = { 12, 7, 14, 9, 10, 11 };
    std::vector<double> tablicaDouble = { 1.1, 9.9, 5.5, 2.2, 3.3 };

    std::cout << "--- Sortowanie MergeSort ---\n";

    // Sortowanie Int
    MergeSort<int>::sort(tablicaInt);
    std::cout << "Posortowane int: ";
    for (int x : tablicaInt) std::cout << x << " ";
    std::cout << "\n";

    // Sortowanie Double
    MergeSort<double>::sort(tablicaDouble);
    std::cout << "Posortowane double: ";
    for (double x : tablicaDouble) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}