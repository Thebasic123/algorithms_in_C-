#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
	for(auto it : v){
		os << it << " ";
	}
	os << "\n";
	return os;
}

std::vector<int> prefix(const std::string &pat){
	int m = pat.length();
	std::vector<int> lps(m);
	int len = 0;
	int i = 1;
	while(i < m){
		if(pat[i]==pat[len]){
			lps[i++] = ++len;
		}else{
			if(len!=0){
				len = lps[len-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
	return lps;
}

std::vector<int> kmp(const std::string &str, const std::string &pat){
	std::vector<int> lps = prefix(pat);

	std::vector<int> match;
	int n = str.length();
	int m = pat.length();
	int i=0;
	int j=0;
	while(i < n){
		if(str[i]==pat[j]){
			++i;
			++j;
		}
		if(j==m){
			match.push_back(i-j);
			j = lps[j-1];
		}else if(i < n && pat[j] != str[i]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	return match;
}

int main(int argc, char *argv[]){
	std::string str;
	std::string pat;

	std::cin >> str;
	std::cin >> pat;
	
	std::cout << kmp(str, pat);
	
	return 0;
}

