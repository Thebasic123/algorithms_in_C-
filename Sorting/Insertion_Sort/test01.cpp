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

void insertion_sort(std::vector<int> &v){
	int n = v.size();
	int temp, j;
	for(int i = 1; i < n; ++i){
        // store the value
		temp = v[i];
		j = i-1;

        // shifting numbers larger than temp to right
		while(j>=0 && v[j] > temp){
			v[j+1] = v[j];
			j = j-1;
		}
        // insert temp to the correct place
		v[j+1] = temp;
	}
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	insertion_sort(v);

	std::cout << v;
	return 0;
}

