#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}
/*
Giving array: 
4 3 7 1 8 5

It can be represented as the following heap: 
        4
      /   \
    3       7
  /   \       \
1       8       5

After converting into max heap: 
        8
      /   \
    4       7
  /   \       \
1       3       5

Reconstruct as array:
8 4 7 1 3 5

The first element is 8, which is the maximum, 
exchange the first it with the last, 
then reconsruct max heap except for the last,

*/


/* build the heap, with root node as index i
           ***
           /
         i th
        /   \ 
      l th    r th

 v: the input array
 n: length of the array
 i: the node to build the heap
*/

void heapify(std::vector<int> &v,int n, int i){
	int largest = i;

    // find corresponding l and r place in heap
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && v[l] > v[largest]) // check boundary of l, then compare to largest
		largest = l;
	if(r < n && v[r] > v[largest]) // check boundary of r, then compare to largest
		largest = r;               
    // Note: by setting largest index, it will find largest value
    // of the three index i, l, r

	if(largest!=i){                    // if largest has been set to l or r
		std::swap(v[i], v[largest]);   // set root with as the largest one
		heapify(v, n, largest);        // heapify the sub-node of l or r

        // Note: if the sub-node has value larger than current root, it is 
        // not guranteed to be max-heap after this step, however, it will 
        // help the process in the final re-heapify stage
	}
}

void heap_sort(std::vector<int> &v){
	int n = v.size();

    // build max-heap, by heapify from the middle to the start
    // so that it will cover all the values
	for(int i= n/2-1; i>=0; --i)
		heapify(v, n, i);

    // extract the root of max-heap (largest one, v[0]) and place 
    // it to the last one by one
	for(int i=n-1; i >=0; --i){
		std::swap(v[0], v[i]);

        // re-heapify to get the largest
		heapify(v, i, 0);
        // Note: this process require the recursively heapify, as it takes the largest 
        // one by one, the sub-tree will need always put the largest on top
	}
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	heap_sort(v);
	
	std::cout << v;
	return 0;
}

