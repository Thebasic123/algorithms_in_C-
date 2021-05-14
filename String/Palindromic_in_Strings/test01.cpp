#include <iostream>
#include <string>

/*
A palindromic is a string that can be read the same way in either direction.
It can be checked by: 

bool isPalindromic(std::string word){
    int i1 = 0;
    int i2 = word.length() - 1;
    while (i2 > i1) {
        if (word[i1] != word[i2]) {
            return false;
        }
        ++i1;
        --i2;
    }
    return true;
}

*/

int count_palindromic(std::string s){
    int n = s.length();
    int count = 0;

    // double the size of center, which stands for half step
    // each time of left and right
    for(int center = 0; center <= n*2-1; center++){
        int left = center / 2;
        int right = left + center % 2; // different when center is even or odd
        while(left >=0 && right <n && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;

    std::cout << count_palindromic(s) << "\n";
}
