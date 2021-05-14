#include <iostream>
#include <vector>
#include <set>
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

int max_sum_less_than_k(std::vector<int> v, int k){
    int n = v.size();
    int curr_sum = v[0];
    int max_sum = 0;
    int start = 0;

    for (int i = 1; i < n; i++) {
        if (curr_sum <= k) {
            max_sum = std::max(max_sum, curr_sum);
        }

        while (curr_sum + v[i] > k && start < i) {
            curr_sum -= v[start];
            start++;
        }
        curr_sum += v[i];
    }

    if (curr_sum <= k)
        max_sum = std::max(max_sum, curr_sum);

    return max_sum;
}

int main(int argc, char *argv[]){
    int k,n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << f(v, k) << "\n";
    return 0;
}
