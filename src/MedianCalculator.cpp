#include "MedianCalculator.h"

void HeapMedianCalculator::AddNumber(float number)
{
    if(m_SmallElements.empty())
    {
        m_SmallElements.push(number);
        return;
    }

    const float maxSmall = m_SmallElements.top();
    if(number < maxSmall)
    {
        m_SmallElements.push(number);
    }
    else
    {
        m_BigElements.push(number);
    }
    RebalanceElements();
}

float HeapMedianCalculator::GetMedian() const
{
    if(m_SmallElements.size() == m_BigElements.size())
    {
        return (m_SmallElements.top() + m_BigElements.top()) / 2.0f;
    }
    return m_SmallElements.top();
}

void HeapMedianCalculator::RebalanceElements()
{
    const int smallCount = m_SmallElements.size();
    const int bigCount = m_BigElements.size();
    if(bigCount + 1 < smallCount)
    {
        const float maxSmall = m_SmallElements.top();
        m_SmallElements.pop();
        m_BigElements.push(maxSmall);
    }
    else if(smallCount < bigCount)
    {
        const float minBig = m_BigElements.top();
        m_BigElements.pop();
        m_SmallElements.push(minBig);
    }
}
