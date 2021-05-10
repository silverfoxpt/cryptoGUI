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
#include <sstream>
#include "UTILITY_FUNCTIONS.h"
using namespace std;

void alterString(string& x, char dash, char dot)
{
    for (int i = 0; i < (int) x.size(); i++)
    {
        if (x[i] == dash) {x[i] = '-';}
        if (x[i] == dot) {x[i] = '.';}
    }
}

map<char, string> encryptMap; map<string, char> decryptMap;

void init()
{
    encryptMap['a'] = ".-";
    encryptMap['b'] = "-...";
    encryptMap['c'] = "-.-.";
    encryptMap['d'] = "-..";
    encryptMap['e'] = ".";
    encryptMap['f'] = "..-.";
    encryptMap['g'] = "--.";
    encryptMap['h'] = "....";
    encryptMap['i'] = "..";
    encryptMap['j'] = ".---";
    encryptMap['k'] = "-.-";
    encryptMap['l'] = ".-..";
    encryptMap['m'] = "--";

    encryptMap['n'] = "-.";
    encryptMap['o'] = "---";
    encryptMap['p'] = ".--.";
    encryptMap['q'] = "--.-";
    encryptMap['r'] = ".-.";
    encryptMap['s'] = "...";
    encryptMap['t'] = "-";
    encryptMap['u'] = "..-";
    encryptMap['v'] = "...-";
    encryptMap['w'] = ".--";
    encryptMap['x'] = "-..-";
    encryptMap['y'] = "-.--";
    encryptMap['z'] = "--..";

    encryptMap['1'] = ".----";
    encryptMap['2'] = "..---";
    encryptMap['3'] = "...--";
    encryptMap['4'] = "....-";
    encryptMap['5'] = ".....";
    encryptMap['6'] = "-....";
    encryptMap['7'] = "--...";
    encryptMap['8'] = "---..";
    encryptMap['9'] = "----.";
    encryptMap['0'] = "-----";
    encryptMap['.'] = ".-.-.-";
    encryptMap[','] = "--..--";
    encryptMap['?'] = "..--..";

    for(map<char, string>::iterator it = encryptMap.begin(); it!=encryptMap.end(); it++)
    {
        decryptMap[it->second] = it->first;
    }
}

string encryptMorse(string s, char delim)
{
    string res = ""; init();
    for (int i = 0; i < (int) s.size(); i++)
    {
        char c = s[i]; tolower(c);
        if (encryptMap.find(c) == encryptMap.end()) {res += c;}
        else {res += encryptMap[c];}
        res += delim;
    }
    res.erase(res.size()-1, 1);
    return res;
}

string decryptMorse(string s, char delim, char dash, char dot)
{
    string res = ""; init();
    string stmp = s;
    alterString(stmp, dash, dot);
    vector<string> splitter = tokenize(stmp, delim);
    for (int i = 0; i < (int) splitter.size(); i++)
    {
        string cur = splitter[i];
        if (decryptMap.find(cur) != decryptMap.end()) {res += decryptMap[cur];}
        else {res += cur;}
    }
    return res;
}

/*int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    string inputString; char delim, dash, dot;
    cout << "Input : "; getline(cin, inputString);
    cout << "Delimiter : "; cin >> delim;
    cout << "Dash : "; cin >> dash;
    cout << "Dot : "; cin >> dot;
    int mode; cin >> mode;
    if (mode == 1) {cout << encryptMorse(inputString, delim);}
    else {cout << decryptMorse(inputString, delim, dash, dot);}
    //vector<string> tmp = tokenize(inputString, delim);
}*/

