#include <iostream>
#include <string>
#include <vector>

int lcs(const std::string s1, const std::string s2){
	int n = s1.length();
	int m = s2.length();

	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
	for(int i=1; i < n+1; ++i){
		for(int j= 1; j < m+1; ++j){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	return dp[n][m];
}

int main(int argc, char *argv[]){
	std::string s1;
	std::string s2;

	std::cin >> s1;
	std::cin >> s2;

	std::cout << lcs(s1, s2) << "\n";

	return 0;
}
