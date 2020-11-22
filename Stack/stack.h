#ifndef STACK
#define STACK

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
   Node<T> *top_;

   List<T>(){
	   top_=nullptr;
   }
   ~List<T>(){
	   Node<T> *clear=top_;
	   while(clear){
		   clear=top_->next;
		   delete top_;
		   top_=clear;
	   }
   }

   void insertFront(T);
   bool isEmpty(); 
   T lastValue();
   void removeFront();
   void print();
};

template<typename T>
class Stack : public List <T>
{  
    public:
    void push(T dato);
    T top();
    void pop(); 
    void sprint();   
};

#endif //STACK
