#ifndef QUEUE
#define QUEUE

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
   Node<T> *front_;
   Node<T> *rear_;

   List<T>(){
	   front_ = rear_ =nullptr;
   }
   ~List<T>(){
	   Node<T> *clear=front_;
	   while(clear){
		   clear=front_->next;
		   delete front_;
		   front_=clear;
	   }
   }

   void insert(T);
   bool isEmpty(); 
   T lastValue();
   void removeFront();
   void print();
};

template<typename T>
class Queue : private List <T>
{  
    public:
    void enQueue(T dato);
    T front();
    void deQueue(); 
    void qprint();   
};

#endif //QUEUE
