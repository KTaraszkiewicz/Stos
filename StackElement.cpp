#include "StackElement.h"

StackData::StackData(int n)
{
    this->data = n;
    this->under = nullptr;
}
StackData::StackData(const StackData& other)
    : data(other.data), under(nullptr) {}
StackData::StackData(StackData&& other) noexcept 
    : data(std::move(other.data)), under(other.under) {
    other.under = nullptr;
}
StackData::~StackData() {}
