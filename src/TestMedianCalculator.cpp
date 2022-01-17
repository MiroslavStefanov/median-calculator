#include "TestMedianCalculator.h"
#include <algorithm>

void TestMedianCalculator::AddNumber(float number)
{
    m_Elements.push_back(number);
}

float TestMedianCalculator::GetMedian() const
{
    std::sort(m_Elements.begin(), m_Elements.end());
    const auto count = m_Elements.size();
    if(count % 2 == 1)
    {
        return m_Elements[count/2];
    }
    else
    {
        return 0.5f*(m_Elements[count/2] + m_Elements[count/2 - 1]);
    }
}
