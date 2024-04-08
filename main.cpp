#include <iostream>
#include "StackMinimum.h"

using namespace std;

int main()
{
	StackMinimum* stack = new StackMinimum();
	stack->push(10);
	stack->push(22);
	stack->push(220);
	stack->push(-11);
	stack->push(33);
	stack->push(-12);
	stack->push(1000);
	stack->push(-100);
	cout << stack->getMin() << endl;
	stack->pop();
	cout << stack->top() << endl;
	cout << stack->getMin() << endl;
	return 0;
}