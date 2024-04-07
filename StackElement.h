#include <iostream>
#pragma once
using namespace std;

class StackData {
public:
	int data;
	StackData* under;
	StackData(int n);
	StackData(const StackData& other);
	StackData(StackData&& other) noexcept;
	~StackData();
};
