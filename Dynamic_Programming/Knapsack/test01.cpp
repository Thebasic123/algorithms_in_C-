#include <iostream>
#include <vector>
#include <utility>


int knapsack(int W, std::vector<std::pair<int, int>> vwp){
	int n = vwp.size();
	std::vector<std::vector<int>> dp( n+1, std::vector<int>(W+1));
	for(int i=1; i < n+1; ++i){
		for(int j = 1; j < W+1; ++j){
			if(j>=vwp[i-1].second){
				dp[i][j] = std::max(dp[i-1][j], vwp[i-1].first + dp[i-1][j-vwp[i-1].second]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main(int argc, char *argv[]){
	int n;
	int W;
	std::cin >> W;
	std::cin >> n;
	std::vector<std::pair<int, int>> vwp(n); // value weight pair
	for(int i=0; i < n; ++i){
		int v, w;
		std::cin >> v >> w;
		vwp[i] = std::make_pair(v, w);
	}

	std::cout << knapsack(W, vwp) << "\n";

	return 0;
}
