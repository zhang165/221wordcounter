/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		text_item toReturn = data[0];
		data[0] = data[--numItems];
		swap_down(0);
		return toReturn;
	}
}

void max_heap::swap_down(int i) {
	int l = i*2 + 1;
	int r = l + 1;
	int s = i;
	if(l < numItems && data[l].freq > data[s].freq){
		s = l; // left child bigger
	}
	if(l < numItems && data[r].freq > data[s].freq){
		s = r; // right child bigger
	}

	if( s!= i){
		text_item temp = data[i];
		data[i] = data[s];
		data[s] = temp;
		swap_down(s);
	}
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		data[numItems++] = item;
		swap_up(numItems-1); 
	}
}

void max_heap::swap_up(int i) {
	if(i==0) return; // do nothing at top
	int p = (i-1)/2;
	if(data[i].freq > data[p].freq){ // we're actually bigger
		text_item temp = data[i];
		data[i] = data[p];
		data[p] = temp;
		swap_up(p);
	}
}
