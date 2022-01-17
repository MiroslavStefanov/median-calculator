#pragma once

#include <queue>
#include <vector>

struct MedianCalculator
{
    virtual ~MedianCalculator() = default;
    virtual void AddNumber(float number) = 0;
    virtual float GetMedian() const = 0;
};

class HeapMedianCalculator : public MedianCalculator
{
public:

    /**
     * @brief O(logN)
     * 
     * @param number 
     */
    void AddNumber(float number) override;

    /**
     * @brief O(1)
     * 
     * @return median value 
     */
    float GetMedian() const override;

private:
    void RebalanceElements();

private:
    using MaxHeap = std::priority_queue<float>;
    using MinHeap = std::priority_queue<float, std::vector<float>, std::greater<float>>;

    MaxHeap m_SmallElements;
    MinHeap m_BigElements;
};
