/**
 * @file MergeSort.h
 * @brief Implementacja algorytmu sortowania przez scalanie (Merge Sort).
 */
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

 /**
  * @class MergeSort
  * @brief Klasa szablonowa realizująca algorytm sortowania przez scalanie.
  * @tparam T Typ danych (np. int, double, float).
  */
template<typename T>
class MergeSort {
public:
    static void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) return;
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

private:
    static void mergeSort(std::vector<T>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    static void merge(std::vector<T>& arr, int left, int mid, int right) {
        std::vector<T> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right)
            temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int x = 0; x < k; x++)
            arr[left + x] = temp[x];
    }
};
#endif