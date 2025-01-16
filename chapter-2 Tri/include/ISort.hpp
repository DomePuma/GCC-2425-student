#ifndef ISORT_HPP
#define ISORT_HPP

#include <vector>

struct ISort
{
    virtual ~ISort() = default;
    virtual void sort(std::vector<int>& vector) = 0;
};

#endif //ISORT_HPP