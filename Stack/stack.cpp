#include<iostream>
#include "stack.h"
using namespace std;

template<class T>
void List<T>::insertFront(T dato)
{  
	Node<T>*tmp;
	tmp = new Node<T>(dato);
	tmp->next = top_;
	top_ = tmp;
}

template<typename T>
bool List<T>::isEmpty() 
{
	return top_ == nullptr;
}

template<typename T>
T List<T>::lastValue() 
{
	if (!isEmpty()) return top_->value;
}

template<class T>
void List<T>::removeFront()
{  
	Node<T> *tmp = top_;
	top_ = top_->next;
	tmp->next = nullptr;
	delete tmp;
}

template<typename T>
void List<T>::print()
{
	Node<T> *tmp=top_;
	while(tmp){
        // &: address
		cout<<"&:"<<tmp<<", valor: "<<tmp->value<<"\n";
		tmp=tmp->next;
	}
}

// ----------------------  STACK  ------------------------
template<typename T>
void Stack<T>::push(T dato) {
    this->insertFront(dato);
}

template<typename T>
T Stack<T>::top() {
    this->lastValue();
}

template<typename T>
void Stack<T>::pop() {
    this->removeFront();
}

template<typename T>
void Stack<T>::sprint() {
    this->print();
}

int main() 
{
    Stack<float> stack;
    stack.push(5.0);
	stack.push(1.1);
	stack.push(7.4);
	stack.push(4.3);
    
    cout<<endl<<"Valores insertados en el stack: "<<endl;
	stack.sprint();

    // TOP 
	float value;
	value = stack.top();
	cout<<endl<<"Valor top: "<<value<<"\n";

	// POP
	stack.pop();
	cout<<endl<<"Pop: \n";
	stack.sprint();

    // TOP 
	value = stack.top();
	cout<<endl<<"Valor top: "<<value<<"\n";
}
