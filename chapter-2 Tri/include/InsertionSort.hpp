#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <iostream>
#include "ISort.hpp"

struct InsertionSort final : ISort
{
    void sort(std::vector<int>& v) override
    {
        std::size_t collectionSize_t = v.size();
        int collectionSize = collectionSize_t;
        for (int i = 1; i < collectionSize; ++i) 
        {
            int aux = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > aux)
            {
                v[j + 1] = v[j];
                j -= 1;
            }
            v[j + 1] = aux;
        }
    }
};

#endif //INSERTIONSORT_HPP