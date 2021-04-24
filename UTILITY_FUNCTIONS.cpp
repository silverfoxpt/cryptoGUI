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

inline bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

vector<string> tokenize(string s, const char delim)
{
    stringstream ss(s);

    string s2; vector<string> res;
    while (getline(ss, s2, delim)) {
        res.push_back(s2);
    }
    return res;
}

vector<string> inputTextFile(char a[])
{
    ifstream input(a);
    //if (!exists_test0(a)) {cout << "boo" << endl;}
    vector<string> res;
    string tmp;
    while(getline(input, tmp))
    {
        //cerr << "stop" << endl;
        res.push_back(tmp);
    }
    return res;
}

void printTextFileContent(char a[])
{
    //cerr << a;
    vector<string> contentFile = inputTextFile(a);
    //cerr << contentFile.size();
    for (int i = 0; i < (int) contentFile.size(); i++)
    {
        cout << contentFile[i] << "\n";
    }
}

//int main(){printTextFileContent("WELCOME_TEXT.txt");}
