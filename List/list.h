#ifndef List_H
#define List_H
template<typename T>
class Node
{
	public:
	T value;
	Node<T> *next;
  Node<T>(T dato, Node *sgte=nullptr){
		value=dato;
		next=sgte;
	}
};

template<typename T>
class List
{
   public:
   Node<T> *head; 
   
   List<T>(){
       //head=nullptr;
	   head=nullptr;
   }
   ~List<T>(){
	   Node<T> *clear=head;
	   while(clear){
		   clear=head->next;
		   delete head;
		   head=clear;
	   }
   }
   void insert(T);
   bool find(T, Node<T> *&,int);
   void remove(T);
   void print();
   
   // STACK
   void pushFront(T);
   bool sfind(T, Node<T> *&);
   void popFront();
   void sprint();
};
#endif //List_H
