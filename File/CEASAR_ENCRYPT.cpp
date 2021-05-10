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
#include "ENGLISH_CHECKER.h"
#include "CEASAR_ENCRYPT.h"
using namespace std;

/*void display(string s)
{
    vector<int> res = wordCalc(s);
    cout << "Number of words : " << res[1] << endl;
    cout << "Number of English word : " << res[0] << endl;
    cout << fixed << setprecision(3);
    cout << "Percentage : " << (double) res[0]/res[1]*100 << "%";
}*/
string alpha = "qwertyuiopasdfghjklzxcvbnm";
struct packet
{
    double percent; string dec; int key;
};
vector<packet> packets;

string encryptCeasar(string enc, int key)
{
    string x = enc;
    for (int i = 0; i < (int) x.size(); i++)
    {
        x[i] = tolower(x[i]);
        if (alpha.find(x[i]) == string::npos) { continue;}
        x[i] += key;
        if (x[i] > 'z') {x[i] -= 26;}
        x[i] = toupper(x[i]);
    }
    return x;
}

string decryptCeasar(string dec, int key)
{
    string x = dec;
    for (int i = 0; i < (int) x.size(); i++)
    {
        x[i] = tolower(x[i]);
        if (alpha.find(x[i]) == string::npos) { continue;}
        x[i] -= key;
        if (x[i] < 'a') {x[i] += 26; }
    }
    return x;
}

bool LF(packet a, packet b)
{
    return a.percent > b.percent;
}

void displayCeasarCrack(string dec)
{
    cout << fixed << setprecision(3);
    for (int i = 0; i < 26; i++)
    {
        string plain = decryptCeasar(dec, i);
        vector<int> res = wordCalc(plain);
        //cout << "Word : " << plain << " ; Key = " << i << " ; ";
        //cout << "Percentage = " << (double) res[0]/res[1]*100 << "%" << endl;
        packet newPack = {(double) res[0]/res[1], plain, i}; packets.push_back(newPack);
    }
    sort(packets.begin(), packets.end(), LF);
    for (int i = 0; i < 26; i++)
    {
        packet cur = packets[i];
        cout << "Plaintext : " << cur.dec << " ; Key = " << setw(2) << cur.key << " ; ";
        cout << "English word percentage = " << cur.percent*100 << "%" << endl;
    }
}

string crackCeasar(string dec)
{
    cout << fixed << setprecision(3);
    for (int i = 0; i < 26; i++)
    {
        string plain = decryptCeasar(dec, i);
        vector<int> res = wordCalc(plain);
        //cout << "Word : " << plain << " ; Key = " << i << " ; ";
        //cout << "Percentage = " << (double) res[0]/res[1]*100 << "%" << endl;
        packet newPack = {(double) res[0]/res[1], plain, i}; packets.push_back(newPack);
    }
    sort(packets.begin(), packets.end(), LF);
    return packets[0].dec;
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

