#ifndef MORSE_TRANSLATOR_H
#define MORSE_TRANSLATOR_H

#include <string>
using namespace std;
string encryptMorse(string s, char delim);
string decryptMorse(string s, char delim, char dash, char dot);

#endif // MORSE_TRANSLATOR_H

