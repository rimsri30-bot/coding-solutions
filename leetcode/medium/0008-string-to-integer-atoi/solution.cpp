#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        long result = 0;

        // digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // overflow check
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};