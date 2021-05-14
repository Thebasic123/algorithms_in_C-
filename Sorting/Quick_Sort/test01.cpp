#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it: v)
		os << it << " ";
	os << "\n";
	return os;
}

int partition(std::vector<int> &v, int low, int high){
	int pivot = v[high];
	int i = low;
	for(int j = low; j < high; ++j){
		if(v[j] <= pivot){
			std::swap(v[i++], v[j]);
		}
	}
	std::swap(v[i], v[high]);
	return i;
}

void quick_sort(std::vector<int> &v, int low, int high){
	if(low >= high)
		return;

    // partition the array into two sections
	int p = partition(v, low, high);

    // no need to include pivot
	quick_sort(v, low, p-1);
	quick_sort(v, p+1, high);
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i=0; i < n; ++i){
		std::cin >> v[i];
	}

	quick_sort(v, 0, v.size()-1);
	std::cout << v;
	return 0;
}

