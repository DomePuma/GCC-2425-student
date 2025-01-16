#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

#include "ISort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "InsertionSort.hpp"

void genericSorting(std::vector<int>& v)
{
    std::unique_ptr<ISort> sortingAlgorithm = std::make_unique<QuickSort>();

    if(std::size_t collectionSize = v.size(); collectionSize < 16)
    {
        sortingAlgorithm = std::make_unique<BubbleSort>();
    }
    else if(collectionSize < 64)
    {
        sortingAlgorithm = std::make_unique<InsertionSort>();
    }

    sortingAlgorithm->sort(v);
}

void displayVector(const std::vector<int>& v)
{
    std::cout << "[";
    for(const int& i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void fillRandomlyVector(int numberOfRandomNumbers, std::vector<int>& v)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(0, 255);

    v.reserve(numberOfRandomNumbers);
    for(int i = 0; i < numberOfRandomNumbers; i++)
    {
        v.emplace_back(dis(gen));
    }
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    
    fillRandomlyVector(6,v1);
    fillRandomlyVector(17,v2);
    fillRandomlyVector(65,v3);

    displayVector(v1);
    genericSorting(v1);
    displayVector(v1);

    displayVector(v2);
    genericSorting(v2);
    displayVector(v2);

    displayVector(v3);
    genericSorting(v3);
    displayVector(v3);

    return 0;
}   