#include "StackMinimum.h"
using namespace std;

StackMinimum::StackMinimum()
{ 
	first = nullptr;
	currentMin = nullptr;
}
StackMinimum::StackMinimum(const StackMinimum& other)
{
	first = nullptr;
	currentMin = nullptr;
	StackData* temp1 = other.currentMin;
	temp1 = currentMin;
	StackData* temp = other.first;
	while (temp != nullptr) {
		push(temp->data);
		temp = temp->under;
	}
}
StackMinimum::StackMinimum(StackMinimum&& other) noexcept
{
	first = other.first;
	currentMin = other.currentMin;
	other.first = nullptr;
	other.currentMin = nullptr;
}
StackData* StackMinimum::GetFirst()
{
	return first;
}

bool StackMinimum::empty() const
{
	return first == nullptr;
}
int StackMinimum::top()
{
	if (!empty())
		return first->data;
	else {
		printf("Cannot give top value while empty");
		exit(1);
	}	
}
void StackMinimum::pop()
{
	if (first == nullptr) {
		printf("\nStack empty!");
		exit(1);
	}
	else {
		StackData* temp;
		if (first->data == currentMin->data)
		{
			StackData* temp2;
			temp2 = currentMin;
			currentMin = currentMin->under;
			delete temp2;
		}
		temp = first;
		first = first->under;
		delete temp;
	}
}
int StackMinimum::getMin()
{
	if (!empty())
		return currentMin->data;
	else {
		printf("Cannot give min value while empty");
		exit(1);
	}
}
void StackMinimum::push(int n)
{
	StackData* temp = new StackData(n);
	StackData* temp1 = new StackData(n);
	if (!temp) {
		printf("\nTemporary StackData Error!");
		exit(1);
	}
	if (empty()) currentMin = temp1;
	else
	{
		StackData* prev = nullptr;
		StackData* curr = currentMin;
		while (curr && curr->data < n) {
			prev = curr;
			curr = curr->under;
		}
		if (!prev) 
		{ 
			temp1->under = currentMin;
			currentMin = temp1;
		}
		else 
		{
			prev->under = temp1;
			temp1->under = curr;
		}
	}
	temp->under = first;
	first = temp;
}

void StackMinimum::displayStack()
{
	StackData* temp;
	if (empty()) {
		printf("\nStack empty!");
		exit(1);
	}
	else {
		temp = GetFirst();
		while (temp != NULL) {
			printf("%d", temp->data);
			temp = temp->under;
			if (temp != NULL)
				printf(" ");
		}
	}
	delete temp;
	printf("\n");
}
StackMinimum& StackMinimum::operator=(const StackMinimum& right)
{
	if (this != &right) {
		while (!empty()) {
			pop();
		}
		StackMinimum tmp = right;
		swap(first, tmp.first);
	}
	StackMinimum tmp = right;
	swap(currentMin, tmp.currentMin);
	return *this;
}
StackMinimum& StackMinimum::operator=(StackMinimum&& right) noexcept
{
	if (this != &right) {
		while (!empty()) {
			pop();
		}
		swap(first, right.first);
	}
	swap(currentMin, right.currentMin);
	return *this;
}
StackMinimum::~StackMinimum() 
{
	while (!empty()) {
		pop();
	}
	delete first;
	delete currentMin;
}