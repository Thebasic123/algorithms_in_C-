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

int max_score(int cost, std::vector<std::vector<int>> v){
	int n = v.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	
	for(int i = 0; i < n; ++i){
        dp[0][i] = std::max(dp[0][i-1] + v[0][i-1], dp[1][i-1] + v[0][i-1] - cost);
        dp[1][i] = std::max(dp[1][i-1] + v[1][i-1], dp[0][i-1] + v[1][i-1] - cost);
	}
	return std::max(dp[0][n], dp[1][n]);
}

int main(int argc, char *argv[]){
	int n;
	int cost; // cost of switching between two sequence
	int a, b;
	std::cin >> n;
	std::cin >> cost;
	// start at v.first
	std::vector<std::vector<int>> v(n, std::vector<int>(2));
	for(int i = 0; i < n; ++i){
		std::cin >> v[0][i] >> v[1][i];
	}
	
	std::cout << max_score(cost, v) << "\n";
	return 0;
}
