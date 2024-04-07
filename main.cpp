#include <iostream>
#include "StackMinimum.h"

using namespace std;

int main()
{
	StackMinimum* stack = new StackMinimum();
	stack->push(10);
	stack->push(-12);
	stack->push(22);
	cout << stack->getMin() << endl;
	stack->pop();
	cout << stack->top() << endl;
	cout << stack->getMin() << endl;
	StackMinimum* stack2 = stack;
	stack->displayStack();
	return 0;
}