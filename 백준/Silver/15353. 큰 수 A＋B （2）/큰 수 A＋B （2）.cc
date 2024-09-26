#include <iostream>
#include <string>
#include <algorithm>

std::string addBigNumbers(const std::string &a, const std::string &b) {
    std::string result = "";
    int carry = 0;
    int lenA = a.size();
    int lenB = b.size();
    int maxLength = std::max(lenA, lenB);
    
    for (int i = 0; i < maxLength; i++) {
        int digitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
        int digitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    if (carry) {
        result += carry + '0';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string A, B;
    std::cin >> A >> B;
    
    std::string result = addBigNumbers(A, B);
    
    std::cout << result << std::endl;
    
    return 0;
}
