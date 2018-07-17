#include <iostream>
#include "a4.h"
using namespace std;

int main(){
	Heap L1;
	Queue L2;
	int x ;
	bool List2 = false; 
	cout << "Student Number: 301217039 Login ID: qilongz Name: QilongZhang" << endl;

	cin >> x ;
	while( !cin.eof() ){
        	if( x == 0 ){
			List2 = true ;
        	}
		if(List2 == false){
			L1.insert(x);
		}
		else{
			L2.enqueue(x);
		}
        	cin >> x ;
	}

	while(!L1.empty()){
		x = L1.extractMin();
		if(L2.empty()){
			cout << x << endl;
			return 0;
		}
		if(L2.Search(x) == false){
			cout << x << endl;
			return 0;
		}
	}
	cout << "NONE" << endl;
	return 0;
}
