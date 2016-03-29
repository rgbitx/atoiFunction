#include <iostream>

using namespace std;

int atoiTest(string str) {
    int num = 0;
    int sign = 1;
    const int n = str.size();

    int i = 0;

    // delete the empty char
    while (str[i] == ' ' && i < n) i++;

    // identify the sign of the number
    if (str[i] == '+') i++;
    else if (str[i] == '-') {
        i++;
        sign = -1;
    }

    for (; i < n; i++) {

        // make sure the char is the number
        if (str[i] < '0' || str[i] > '9') break;

        // to check whether the number is out of the range [INT_MIN, INT_MAX]
        if (num > INT32_MAX / 10 && (num == INT32_MAX / 10 && (str[i] - '0') > INT32_MAX % 10)) {
            return sign == -1 ? INT32_MIN : INT32_MIN;
        }

        // add the number
        num = num * 10 + str[i] - '0';
    }

    return num * sign;

}


int main() {
    cout << "Hello, World!" << endl << endl;

    string str = "   -234213";

    int ret = atoiTest(str);

    cout << "Results:" << endl << ret << endl;

    return 0;
}