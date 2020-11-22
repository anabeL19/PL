#include<iostream>
#include "queue.h"
using namespace std;

template<class T>
void List<T>::insert(T dato)
{  
	Node<T>*tmp;
	tmp = new Node<T>(dato);
	if (rear_ == nullptr) {
		front_ = rear_ = tmp;
		return;
	}
	rear_->next = tmp;
	rear_ = tmp;
}

template<class T>
void List<T>::removeFront()
{  
	Node<T> *tmp = front_;
	front_ = front_->next;
	if (front_ == nullptr)
		rear_ = nullptr;
	delete tmp;
}

template<typename T>
void List<T>::print()
{
	Node<T> *tmp=front_;
	while(tmp){
        // &: address
		cout<<"&:"<<tmp<<", valor: "<<tmp->value<<"\n";
		tmp=tmp->next;
	}
}

// ----------------------  QUEUE  ------------------------
template<typename T>
void Queue<T>::enQueue(T dato) {
    this->insert(dato);
}

template<typename T>
T Queue<T>::front() {
    return this->front_->value;
}

template<typename T>
void Queue<T>::deQueue() {
    this->removeFront();
}

template<typename T>
void Queue<T>::qprint() {
    this->print();
}

int main() 
{
    Queue<float> queue;
    queue.enQueue(5.0);
	queue.enQueue(1.1);
	queue.enQueue(7.4);

    cout<<endl<<"Valores insertados en la cola: "<<endl;
	queue.qprint();

	cout<<endl<<"Valor top: "<< queue.front() <<"\n";

	queue.enQueue(4.3);

	cout<<endl<<"Valores insertados en la cola: "<<endl;
	queue.qprint();

	// DELETE FIRST
	queue.deQueue();
	cout<<endl<<"Delete: \n";
	queue.qprint();

	cout<<endl<<"Valor top: "<< queue.front() <<"\n";
}
