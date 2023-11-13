#include <bits/stdc++.h>
using namespace std;



bool isRotation(string& str1,string& str2) {
    // Check if both strings have the same length
    if (str1.length() != str2.length()) {
        return false;
    }

    string concatenatedStr = str1 + str1;


    return concatenatedStr.find(str2) != string::npos;
}

int main() {
    std::string str1 = "abcd";
    std::string str2 = "cdab";

    if (isRotation(str1, str2)) {
        cout << str2 << " is a rotation of " << str1 << endl;
    } else {
        cout << str2 << " is not a rotation of " << str1 << endl;
    }

    return 0;
}

