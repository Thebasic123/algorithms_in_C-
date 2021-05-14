#include <iostream>
#include <vector>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}

template <template <typename, typename...> class ContainerType, 
          typename ValueType, typename... Args>
std::ostream& operator<<(std::ostream& os, const ContainerType<ValueType, Args...>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

int longest_subarray(std::vector<int> v, int k){
    int n = v.size();
    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > k) {
            count++;
        } 
        else {
            max = std::max(count, max);
            count = 0;
        }
    }
    max = std::max(count, max);
    return max;
}

int main(int argc, char *argv[]){
    int k;
    int n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << longest_subarray(v, k) << "\n";
    return 0;
}
