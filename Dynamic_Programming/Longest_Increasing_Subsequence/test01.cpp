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

int lis(std::vector<int> v){
	int n = v.size();
	std::vector<int> dp(n, 1);
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(v[i] > v[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j] + 1; 
			}
		}
	}
	
	return *std::max_element(dp.begin(), dp.end());
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << lis(v) << "\n";
	return 0;
}
