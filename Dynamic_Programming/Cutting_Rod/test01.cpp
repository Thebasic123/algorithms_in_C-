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
Given a rod of length n inches and an array of prices that contains 
prices of all pieces of size smaller than n. Determine the maximum 
value obtainable by cutting up the rod and selling the pieces.
*/

int cut(std::vector<int> v){
	int n = v.size();
	std::vector<int> dp(n+1);

	for(int i = 1; i < n+1; ++i){
		int maxval = INT_MIN;
		for(int j = 0; j < i; ++j){
			maxval = std::max(maxval, v[j] + dp[i-j-1]);
		}
		dp[i] = maxval;
	}
	return dp[n];
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << cut(v) << "\n";
	return 0;
}
