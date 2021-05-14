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

void bubble_sort(std::vector<int> &v){
	int n = v.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n-i-1; ++j){
			if(v[j] > v[j+1])
				std::swap(v[j], v[j+1]);
		}
	}
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	bubble_sort(v);

	std::cout << v;
	return 0;
}
