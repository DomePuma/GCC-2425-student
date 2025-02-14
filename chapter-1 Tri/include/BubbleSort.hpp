#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iostream>
#include "ISort.hpp"

struct BubbleSort final : ISort
{
    void sort(std::vector<int>& v) override
    {
        std::size_t collectionSize_t = v.size();
        int collectionSize = collectionSize_t;
        for (int i = 0; i < collectionSize; i++) 
        {
            for (int j = collectionSize; j > i; j--)
            {
                if (v[j] > v[j-1])
                {
                    int aux = v[j];
                    v[j] = v[j-1];
                    v[j-1] = aux;
                }
            }
        }
    }
};

#endif //BUBBLESORT_HPP