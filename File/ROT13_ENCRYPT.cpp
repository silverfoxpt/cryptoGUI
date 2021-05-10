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
using namespace std;

/*void display(string s)
{
    vector<int> res = wordCalc(s);
    cout << "Number of words : " << res[1] << endl;
    cout << "Number of English word : " << res[0] << endl;
    cout << fixed << setprecision(3);
    cout << "Percentage : " << (double) res[0]/res[1]*100 << "%";
}*/
string alpha2 = "qwertyuiopasdfghjklzxcvbnm";
struct packet2
{
    double percent; string dec; int key;
};
vector<packet2> packet2s;

string encryptRot(string enc)
{
    int key = 13;
    string x = enc;
    for (int i = 0; i < (int) x.size(); i++)
    {
        x[i] = tolower(x[i]);
        if (alpha2.find(x[i]) == string::npos) { continue;}
        x[i] += key;
        if (x[i] > 'z') {x[i] -= 26;}
        x[i] = toupper(x[i]);
    }
    return x;
}

string decryptRot(string dec)
{
    int key = 13;
    string x = dec;
    for (int i = 0; i < (int) x.size(); i++)
    {
        x[i] = tolower(x[i]);
        if (alpha2.find(x[i]) == string::npos) { continue;}
        x[i] -= key;
        if (x[i] < 'a') {x[i] += 26; }
    }
    return x;
}

/*int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string encText; getline(cin, encText);
    int mode; cin >> mode;
    if (mode == 1) {int key; cin >> key; cout << encryptCeasar(encText, key);}
    else if (mode == 2) {int key; cin >> key; cout << decryptCeasar(encText, key);}
    else if (mode == 3) {
        cout << "Display board? (y/n) : ";
        char c; cin >> c;
        if (c == 'y')
        {
            displayCeasarCrack(encText);
        }
        else {cout << crackCeasar(encText);}
    }
}*/


