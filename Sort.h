/*All the code comes from the previous Assignment except the Search() function*/
using namespace std;

class Heap{
public:
	Heap();
	~Heap(); 
	bool empty() const {return hSize == 0;};
	void insert(int priority);
	int extractMin();
private:		
	class Pair{
		public:
			int priority;
	};
	Pair* A;
	int hCapacity;
	int hSize;
	void trickleUp(int i);
	void trickleDown(int i);
	void heapify();
	void swap(int i,int j);
};

class Queue
{
	public:
		Queue();
		~Queue();
		void enqueue( int item );
		bool Search(int item);
		bool empty();
	private:
		class node{
			public:
				node(int new_data, node * next_node ){
					data = new_data;
					next = next_node;
				}
			int data;
			node * next;
   		};
    		node * front_p;
    		node * back_p;
    		int current_size;
};

Heap::Heap(){
   hCapacity = 1073741824;
   A = new Pair[hCapacity];
   hSize = 0;
}

Heap::~Heap(){
   delete[] A;
}

void Heap::insert(int priority){
   A[hSize].priority = priority;
   trickleUp(hSize);
   hSize ++;
}

void Heap::trickleUp(int i){
   int p = (i-1)/2;
   while (i > 0 and A[p].priority < A[i].priority) {
      swap(i, p);
      trickleUp(p);
   }
}

void Heap::swap(int i, int j){
   Pair temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}

int Heap::extractMin(){
    Pair temp = A[0];
    hSize = hSize-1;
    A[0] = A[hSize];
    heapify();
    trickleDown(0); 
    return temp.priority;
}

void Heap::trickleDown(int i){
    int n = 2*i+1;
    if (2*i+1 < hSize){
       if( 2*i+2 < hSize and A[2*i+2].priority > A[2*i+1].priority){
          n = 2*i+2; 
       }
       if(A[i].priority < A[n].priority){
          swap(i, n);
          trickleDown(n);
       }
    }
}

void Heap::heapify(){
   for( int i = (hSize/2)-1; i>=0 ; i-- ) trickleDown(i);  
}

Queue::Queue(){  // Constructs a new empty queue.
	front_p = NULL;
	back_p = NULL; 
	current_size = 0;
}

Queue::~Queue(){ // Destructor.
	while (front_p != NULL) {
		node *pr = front_p;
		pr = front_p->next;
		delete front_p;
		front_p = pr;
	}
	front_p = NULL;
	back_p = NULL;
	current_size = 0;
}
    
void Queue::enqueue( int item ){  // Enqueues <item>.
	node * p = new node(item, NULL);
	if (front_p == NULL) {
		front_p = p;
		back_p = p;
	}
	else {
		back_p->next = p;
		back_p = p;
		back_p->next = NULL;
	}
	current_size++;
}

bool Queue::Search(int item){
	node * p = front_p;
	while(p != NULL){
		if(p -> data == item){
			return true;
		}
		p = p -> next;
	}
	return false;
}    
    
bool Queue::empty(){  // Returns true iff the queue contains no items.
	return current_size == 0;
}
