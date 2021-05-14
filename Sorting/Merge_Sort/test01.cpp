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

void merge(std::vector<int> &v, int low, int mid, int high){
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for(int i=0; i < n1; ++i)
		L[i] = v[low + i];
	for(int j=0; j < n2; ++j)
		R[j] = v[mid + 1 + j];

	i = 0;
	j = 0;
	k = low;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			v[k++] = L[i++];
		}else{
			v[k++] = R[j++];
		}
	}
	while(i < n1){
		v[k++] = L[i++];
	}
	while(j < n2){
		v[k++] = R[j++];
	}
}

void merge_sort(std::vector<int> &v, int low, int high){
	if(low >= high)
		return;
	int mid = (low + high)/2;
	merge_sort(v, low, mid);
	merge_sort(v, mid+1, high);

	merge(v, low, mid, high);
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	merge_sort(v, 0, v.size()-1);
	std::cout << v;
	return 0;
}

