#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <iomanip>
#include <cctype>
#include <utility>
#include <cmath>
#include <climits>
#include <windows.h>
#include <bitset>
using namespace std;

string toBin8(char c)
{
    int x = (int) c;
    string res = "";
    while(x > 0)
    {
        int a = x%2; x/=2;
        res += a + '0';
    }
    reverse(res.begin(), res.end());
    while(res.size() < 8) { res = '0' + res;}
    return res;
}

string toBin6(char c)
{
    int x = (int) c;
    string res = "";
    while(x > 0)
    {
        int a = x%2; x/=2;
        res += a + '0';
    }
    reverse(res.begin(), res.end());
    while(res.size() < 6) { res = '0' + res;}
    return res;
}

string base64Encode(string inp)
{
    int n = inp.size();
    string bin = "";
    for (int i = 0; i < (int) inp.size(); i++)
    {
        bin += toBin8(inp[i]);
    }
    if (n%3==1) {bin += "0000";}
    else if (n%3==2) {bin += "00";}
    string res = "";
    for (int i = 0; i < (int) bin.size(); i+=6)
    {
        string curChar = "";
        for (int j = i; j <= i+5; j++) {curChar += bin[j];}
        int x = stoi(curChar, 0, 2);
        string rev = "";
        if (x <= 25) {rev += ('A' + x);}
        else if (26 <= x && x <= 51) {rev += ('a' + (x-26));}
        else if (52 <= x && x <= 61) {rev += ('0' + (x-52));}
        else if (x == 62) {rev += '+';}
        else {rev += '/';}
        res += rev;
    }
    if (n%3==1) {res += "==";}
    else if (n%3==2) {res += "=";}
    return res;
}

string base64Decode(string inp)
{
    //int n = inp.size();
    string bin = "";
    for (int i = 0; i < (int) inp.size(); i++)
    {
        if (inp[i] == '=') {bin.erase(bin.size()-1, 1); bin.erase(bin.size()-1, 1); continue;}
        char c = inp[i]; int x;
        if ('A' <= c && c <= 'Z') {x = c - 'A';}
        else if ('a' <= c && c <= 'z') {x = 26 + (c - 'a');}
        else if ('0' <= c && c <= '9') {x = 52 + (c - '0');}
        else if (c == '+') {x = 62;}
        else if (c == '/') {x = 63;}
        string binary = bitset<8>(x).to_string();
        while(binary.size() > 6) {binary.erase(0,1);}
        bin += binary;
    }
    //cerr << bin << endl;
    string res = "";
    for (int i = 0; i < (int) bin.size(); i+=8)
    {
        string curChar = "";
        for (int j = i; j <= i+7; j++) {curChar += bin[j];}
        res += stoi(curChar, 0, 2);
    }
    return res;
}

/*int main()
{
    string x; getline(cin, x);
    cout <<base64Decode(x);
}*/
