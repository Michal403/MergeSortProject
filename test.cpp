#include "gtest/gtest.h"
#include "MergeSort.h" 
#include <vector>

// --- TESTY JEDNOSTKOWE ---

// 1. Zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco
TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

// 2. Potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności
TEST(MergeSortTest, ReversedOrder) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

// 3. Poprawnie sortuje losową tablicę liczb
TEST(MergeSortTest, RandomOrder) {
    std::vector<int> arr = { 10, 2, 8, 1, 5 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 5, 8, 10}));
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, OnlyNegative) {
    std::vector<int> arr = { -5, -1, -10, -3 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-10, -5, -3, -1}));
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortTest, NegativeAndPositive) {
    std::vector<int> arr = { -5, 10, 0, -3, 2 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-5, -3, 0, 2, 10}));
}

// 6. Obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_NO_THROW(MergeSort<int>::sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 42 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{42}));
}

// 8. Poprawnie sortuje tablicę z duplikatami liczb
TEST(MergeSortTest, WithDuplicates) {
    std::vector<int> arr = { 2, 2, 1, 1, 3 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 1, 2, 2, 3}));
}

// 9. Poprawnie sortuje tablice ujemną z duplikatami
TEST(MergeSortTest, NegativeDuplicates) {
    std::vector<int> arr = { -2, -5, -2, -10 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-10, -5, -2, -2}));
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedDuplicates) {
    std::vector<int> arr = { -1, 2, -1, 0, 2 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-1, -1, 0, 2, 2}));
}

// 11. Poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(MergeSortTest, TwoElementsSorted) {
    std::vector<int> arr = { 1, 2 };
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2}));
}

// 12. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(MergeSortTest, LargeArray) {
    std::vector<int> arr;
    for (int i = 150; i > 0; --i) arr.push_back(i); // 150, 149, ... 1

    MergeSort<int>::sort(arr);

    // Sprawdzenie czy posortowane
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        EXPECT_LE(arr[i], arr[i + 1]);
    }
}

// 13. Poprawnie sortuje dużą tablicę... z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, LargeArrayMixed) {
    std::vector<int> arr;
    // Generowanie mieszanki
    for (int i = 0; i < 50; ++i) arr.push_back(-i); // ujemne
    for (int i = 0; i < 50; ++i) arr.push_back(i);  // dodatnie (duplikaty wartości bezwzględnych)
    arr.push_back(0);

    MergeSort<int>::sort(arr);

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        EXPECT_LE(arr[i], arr[i + 1]);
    }
}