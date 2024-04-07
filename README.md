Zaimplementowana struktura danych "StackMinimum" - stos z dodatkową metodą getMinimum, która zwraca minimalną wartość na stosie.
Przykład użycia:
MinStack* StackMin = new MinStack();
StackMin->push(10);
StackMin->push(-12);
StackMin->push(22);  
std::cout<< StackMin->getMin() << std::endl; // pokaże -12
StackMin->pop();
std::cout<< StackMin->top() << std::endl;    // pokaże -12
std::cout<< StackMin->getMin() << std::endl; // pokaże -12
