#include <string>
#include <stack>
#include <assert.h>

using namespace std;

int isDigit(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

string multiStr(string str, int n) {
    string ret = "";
    for(int i = 0; i< n; i++){
        ret += str;
    }
    return ret;
}

string decompressStr(const string &str) {
    stack<string> s;
    string cur = "";
    int time = 0;
    s.push("");
    for(int i=0; i<str.size();i++) {
        if(str[i] == '(') {
            s.top() = s.top() + cur;
            s.push("");
            cur = "";
        } else if (str[i]==')') {
            s.top() = s.top() + cur;
            cur = s.top();
            s.pop();
        } else if (isDigit(str[i])) {
            time = str[i] - '0';
            while(++i < str.size() && isDigit(str[i])) {
                time = time * 10 + (str[i] - '0');
            }
            --i;
            s.top() = s.top() + multiStr(cur, time);
            cur = "";
        } else {
            s.top() = s.top() + cur;
            cur = str[i];
        }
    }
    return s.top() + cur;
}

int main() {
    string str1 = "A2BC03D";
    string str2 = "(A2B)2C";
    string str3 = "A((B2C)2)2D";
    string str4 = "(AB)2(CD)2E";

    string ret1 = "AABCCCD";
    string ret2 = "AABAABC";
    string ret3 = "ABBCBBCBBCBBCD";
    string ret4 = "ABABCDCDE";

    assert(decompressStr(str1)==ret1);
    assert(decompressStr(str2)==ret2);
    assert(decompressStr(str3)==ret3);
    assert(decompressStr(str4)==ret4);
}