#include <iostream>
#include "StackElement.h"
#pragma once
using namespace std;


class StackMinimum {
	StackData* first;
	StackData* currentMin;
public:
	StackMinimum();
	StackMinimum(const StackMinimum& other);
	StackMinimum(StackMinimum&& other) noexcept;
	StackData* GetFirst();
	bool empty() const;
	int top();
	void pop();
	int getMin();
	void push(int n);
	void displayStack();
	StackMinimum& operator=(const StackMinimum& right);
	StackMinimum& operator=(StackMinimum&& right) noexcept;
	~StackMinimum();
};