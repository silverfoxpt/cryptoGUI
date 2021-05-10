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
#include <bitset>
#include "HEXA_TRANSLATOR.h"
#include "UTILITY_FUNCTIONS.h"

using namespace std;

string encryptHexa(string plainText)
{
    string res = "";
    for (int i = 0; i < (int) plainText.size(); i++)
    {
        int k = (int) plainText[i];
        string tmps = "";
        while(k > 0)
        {
            int tmp = k%16; k/=16;
            if (tmp < 10)
            {
                 tmps += (tmp + '0');
            }
            else {tmps += (tmp%10 + 'a');}
        }
        reverse(tmps.begin(), tmps.end());
        res += tmps; res += " ";
    }
    return res;
}

string decryptHexa(string codeText)
{
    string res = "";
    vector<string> chars= tokenize(codeText, ' ');

    for (int i = 0; i < (int) chars.size(); i++)
    {
        //int value = bitset<64>(chars[i]).to_ullong();
        string x = chars[i]; int num = x.size(); int curc = 0; reverse(x.begin(), x.end());
        while(num > 0)
        {
            if (x[num-1] == '0') {num--; continue;}
            char c = x[num-1]; int muller = 1;
            if (c >= 'a') {muller = 10 + (c-'a');} else {muller = c - '0';}
            curc += pow(16, num-1)*muller; num--;
        }
        res += (char) (curc);
    }
    return res;
}

/*int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string text; getline(cin, text);
    int code; cin >> code;
    if (code == 1) //encrypt
    {
        cout << encryptHexa(text);
    }
    else if (code == 2)
    {
        cout << decryptHexa(text);
    }
}*/


