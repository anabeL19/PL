#include<iostream>
#include "list.h"
using namespace std;

template<class T>
void List<T>::insert(T dato)
{  
	Node<T>*tmp;	Node<T>*new_;
	if(!head){head=new Node<T>(dato);}
	if(find(dato,tmp,1)==false){
	    if(!tmp){//or tmp==nullptr
			tmp=head;
			new_=new Node<T>(dato);
			new_->next=tmp;      head=new_;
		}
		else{new_=new Node<T>(dato);
			 new_->next=tmp->next;
			 tmp->next=new_;}
	}
}


template<class T>
bool List<T>::find(T dato, Node<T> *&tmp, int op)
{
	tmp=head;
	switch(op)
	{
		case 1: 
		    if(tmp->value >= dato and tmp->value!=dato){
			    tmp=nullptr; 	 return false;}
				
			while(tmp->value != dato){
				if( tmp->value < dato and (tmp->next==nullptr or tmp->next->value > dato)){ return false;}	
					tmp=tmp->next;
			}
			return true;
		//break;
		case 2: 
		    if(tmp->value==dato){ //????envio su misma posicion no el anterior[head]
		        tmp=nullptr;    return true;}
				
			while(tmp){
				if(tmp->value < dato and (tmp->next->next==nullptr or tmp->next->next->value > dato)){//buscamos the last && other
				   return tmp;}
				tmp=tmp->next;
			}
		//break;
	}
}

template<typename T>
void List<T>::remove(T dato)
{
	Node<T> *tmp;	Node<T> *tmp2;
	if(find(dato,tmp,2)==true){
		if(tmp==nullptr){//head
			tmp2=tmp=head;
			tmp=tmp2->next;
			head=tmp;
			delete tmp2;
		}
		else{	
		tmp2=tmp->next;
		tmp->next=tmp2->next;
		delete tmp2;}
	}
}

template<typename T>
void List<T>::print()
{
	Node<T> *tmp=head;
	while(tmp){
		cout<<"&:"<<tmp<<", valor: "<<tmp->value<<"\n";
		tmp=tmp->next;
	}
}

int main()
{
    /*
	Node<int> *aux;
	List<int> lista;
    */
    Node<float> *aux;
    List<float> lista;
    
    // INSERT
    /*
	lista.insert(5);
	lista.insert(1);
	lista.insert(7);
	lista.insert(4);
	lista.insert(6);
	lista.insert(8);
	lista.insert(10);
	lista.insert(0);
	*/
    
    lista.insert(5.0);
	lista.insert(1.1);
	lista.insert(7.4);
	lista.insert(4.3);
    
	cout<<endl<<"Ex. Inserta lista ordenada: \n";
	lista.print();
    
    //FIND: if there is: "exists" if not: insert
	//int num = 8;
	float num = 4.3;
    cout<<endl<<"NUM: "<<num<<endl;	
	if(lista.find(num, aux, 1)) cout<<"existe \n";
	else lista.insert(num);
	lista.print();
	
    //REMOVE
    /*
	lista.remove(0);
	lista.remove(10);
	lista.remove(7);
	*/
    lista.remove(5.0);
	lista.remove(1.1);
	cout<<endl<<"Lista con valores eliminados: \n";
	lista.print();
}


