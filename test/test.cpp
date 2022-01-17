#include "MedianCalculator.h"
#include "TestMedianCalculator.h"
#include <random>
#include <cstdio>

bool assertEqual(float expected, float actual)
{
    if(expected != actual)
    {
        printf("Expected value %.3f, actual value %.3f", expected, actual);
        return false;
    }
    else
    {
        return true;
    }
}

bool testWithRandomElements(int elementCount)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<float> uniformDistribution;

    HeapMedianCalculator median;
    TestMedianCalculator testMedian;
    for(int i = 0; i<elementCount; i++)
    {
        const float element = uniformDistribution(generator);
        median.AddNumber(element);
        testMedian.AddNumber(element);

        const float expected = testMedian.GetMedian();
        const float actual = median.GetMedian();
        if(!assertEqual(expected, actual))
        {
            return false;
        }
    }

    return true;
}

bool testWithOneElementExpectElementValue()
{
    HeapMedianCalculator median;

    const float element = 0.5f;
    median.AddNumber(element);

    const float actual = median.GetMedian();
    return assertEqual(element, actual);
}

bool testWithTwoElementsExpectTheirMean()
{
    HeapMedianCalculator median;

    const float firstElement = 1.0f;
    median.AddNumber(firstElement);

    const float secondElement = 3.2f;
    median.AddNumber(secondElement);

    const float expected = 0.5f * (firstElement + secondElement);
    const float actual = median.GetMedian();
    return assertEqual(expected, actual);
}

bool testWithThreeElementsExpectMiddleElement()
{
    HeapMedianCalculator median;

    const float smallElement = -1.0f;
    median.AddNumber(smallElement);

    const float middleElement = 3.2f;
    median.AddNumber(middleElement);

    const float bigElement = 1000000.0f;
    median.AddNumber(bigElement);

    const float actual = median.GetMedian();
    return assertEqual(middleElement, actual);
}

int main()
{
    if(!testWithOneElementExpectElementValue()) return 1;
    if(!testWithTwoElementsExpectTheirMean()) return 1;
    if(!testWithThreeElementsExpectMiddleElement()) return 1;

    const int RANDOM_TEST_COUNT = 100;
    const bool randomTestPassed = testWithRandomElements(RANDOM_TEST_COUNT);
    if(!randomTestPassed) return 1;
    
    return 0;
}