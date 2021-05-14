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

// find the minimum value each time and put it in place
void selection_sort(std::vector<int> &v){
	int n = v.size();
	for(int i = 0; i < n; ++i){
		int min = i;
		for(int j = i+1; j < n; ++j){
			if(v[j] < v[min]){
				min = j;
			}
		}
		std::swap(v[min], v[i]);
	}
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	selection_sort(v);
	
	std::cout << v;
	return 0;
}
