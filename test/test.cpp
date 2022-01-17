#include "MedianCalculator.h"

int main()
{
    HeapMedianCalculator median;
    median.AddNumber(2);
    if(median.GetMedian() != 2.0f)
        return 1;
    median.AddNumber(3);
    if(median.GetMedian() != 2.5f)
        return 1;
    median.AddNumber(1);
    if(median.GetMedian() != 2.0f)
        return 1;
    median.AddNumber(1);
    if(median.GetMedian() != 1.5f)
        return 1;
    
    return 0;
}