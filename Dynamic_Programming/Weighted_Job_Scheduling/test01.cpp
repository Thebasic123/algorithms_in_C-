#include <iostream>
#include <utility>
#include <vector>

struct Job{
	int start;
	int end;
	int profit;
};


int schedule(std::vector<Job> jobs){
	int n = jobs.size();
	std::sort(jobs.begin(), jobs.end(), [&](Job a, Job b){
		return a.end < b.end;			
	});

	int m = jobs.back().end;
	std::vector<int> dp(m+1);
	
	int j = 0;
	for(int i=1; i <= m; ++i){
		if(jobs[j].end <= i){
			dp[i] = std::max(dp[i-1], jobs[j].profit + dp[jobs[j].start]);
			j++;
		}else{
			dp[i] = dp[i-1];
		}
	}

	return dp.back();
}

int main(int argc, char *argv[]){
	int n, s, f, v;
	std::cin >> n;
	std::vector<Job> jobs(n);
	for(int i=0; i < n; ++i){
		std::cin >> s >> f >> v;
		jobs[i].start = s;
		jobs[i].end = f;
		jobs[i].profit = v;
	}

	std::cout << schedule(jobs) << "\n";
	
	return 0;
}
