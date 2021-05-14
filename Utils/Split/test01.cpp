#include <iostream>
#include <vector>
#include <string>


template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v){
    int i;
    os << "{";
    for(i = 0; i < v.size()-1; ++i){
        os << v[i] << ", ";
    }
    os << v[i]<<"}\n";
    return os;
}

std::vector<std::string> split(const std::string& str, const std::string& delim){
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int main(int argc, char *argv[]){
    std::string orig;
    getline(std::cin, orig);

    std::cout << split(orig, " ");
	return 0;
}

