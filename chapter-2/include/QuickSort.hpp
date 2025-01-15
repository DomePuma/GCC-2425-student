#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include "ISort.hpp"

struct QuickSort final : ISort
{
    void sort(std::vector<int>& v) override
    {
        std::size_t collectionSize = v.size();
        QuickShort(v, collectionSize, 0, 0);
    }

    void QuickShort(std::vector<int>& v, int size, int low = 0, int high = 0)
    {
        if (high == 0)
        {
            high = size - 1;
        }

        if (low < high)
        {
            int p = Partition(v, low, high);
            QuickShort(v, p, low, p - 1);
            QuickShort(v, high + 1, p + 1, high);
        }
    }
    
    void Swap(std::vector<int>& v, int left, int right)
    {
        int tabLeft = v[left];
        v[left] = v[right];
        v[right] = tabLeft;
    }
    
    int Partition(std::vector<int>& v, int low, int high)
    {
        int pivot_index = high;
        int l = low;
        
        for (int i = low; i < high; ++i) 
        {
            if (v[i] <= v[pivot_index])
            {
                Swap(v, i, l);
                l++;
            }
        }

        Swap(v, l, pivot_index);
        return l;
    }
};

#endif //QUICKSORT_HPP