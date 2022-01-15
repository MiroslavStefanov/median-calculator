#include "MedianCalculator.h"
#include <iostream>

int main()
{
    HeapMedianCalculator median;
    median.AddNumber(2);
    std::cout<<median.GetMedian()<<std::endl;
    median.AddNumber(3);
    std::cout<<median.GetMedian()<<std::endl;
    median.AddNumber(1);
    std::cout<<median.GetMedian()<<std::endl;
    median.AddNumber(1);
    std::cout<<median.GetMedian()<<std::endl;
    
    return 0;
}