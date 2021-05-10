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
#include <sstream>
#include <climits>
#include "UTILITY_FUNCTIONS.h"
using namespace std;

/*set<string> word_list;

void input()
{
    ifstream input("WORDLIST_SHORT.txt");
    string word;
    while(input >> word) {word_list.insert(word);}
}

vector<int> wordCalc(string s)
{
    input();
    vector<string> tmp = tokenize(s, ' ');
    int wordCount = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        string curWord = tmp[i];
        if (word_list.find(curWord) == word_list.end()) {} else {wordCount++;}
    }
    vector<int> res; res.push_back(wordCount); res.push_back(tmp.size()); return res;
}

void display(string s)
{

    vector<int> res = wordCalc(s);
    cout << "Number of words : " << res[1] << endl;
    cout << "Number of English word : " << res[0] << endl;
    cout << fixed << setprecision(3);
    cout << "Percentage : " << (double) res[0]/res[1]*100 << "%";
}*/

/*int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string plainText; getline(cin, plainText);

    display(plainText);
}*/

