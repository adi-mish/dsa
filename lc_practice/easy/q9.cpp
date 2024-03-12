#include <iostream>

using namespace std;

/*Given an integer x, return true if x is a palindrome, and false otherwise.*/

class Solution {
public:
    bool isPalindrome(int x) {
        if ((x < 0) || ((x % 10 == 0) && (x != 0))) {
            return false;
        } 
        else {
             int reversed = 0;
            while (x > reversed) {
                int digit = x % 10;
                reversed = (reversed * 10) + digit;
                x /= 10;
            }
            return ((x == reversed) || (x == reversed / 10));
        }
    }
};

int main() {
    Solution s;
    int x = 10;
    if (s.isPalindrome(x)) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }
    return 0;
}
