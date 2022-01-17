#pragma once

#include "MedianCalculator.h"

class TestMedianCalculator : public MedianCalculator
{
public:
    void AddNumber(float number) override;
    float GetMedian() const override;

private:
    mutable std::vector<float> m_Elements;  
};