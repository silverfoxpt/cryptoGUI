#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

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

#include <QString>
using namespace std;

vector<string> tokenize(string s, const char delim);
vector<string> inputTextFile(char a[]);
void printTextFileContent(char a[]);
string qStrToStr(QString s);
QString strToQStr(string s);
string textFileToStr(char a[]);

#endif
