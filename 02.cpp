/*
Write a program that read the following string:
“Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains 
 the words started with vowel, and another contains the words started with consonant.
*/
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string str = "Munmun is the student of Computer Science & Engineering";

    int vowelCount = 0, consonantCount = 0;
    set<char> vowelsFound, consonantsFound;

    // Count vowels and consonants
    for (char ch : str) {
        if (isalpha(ch)) {
            if (isVowel(ch)) {
                vowelCount++;
                vowelsFound.insert(tolower(ch));
            } else {
                consonantCount++;
                consonantsFound.insert(tolower(ch));
            }
        }
    }

    // Divide words based on starting letter
    string vowelWords = "", consonantWords = "";
    stringstream ss(str);
    string word;
    while (ss >> word) {
        char first = tolower(word[0]);
        if (isalpha(first)) {
            if (isVowel(first))
                vowelWords += word + " ";
            else
                consonantWords += word + " ";
        }
    }

    // Output results
    cout << "Original String: " << str << "\n\n";
    cout << "Total Vowels: " << vowelCount << endl;
    cout << "Total Consonants: " << consonantCount << endl;

    cout << "\nVowels Present: ";
    for (char v : vowelsFound) cout << v << " ";
    cout << endl;

    cout << "Consonants Present: ";
    for (char c : consonantsFound) cout << c << " ";
    cout << endl;

    cout << "\nWords starting with Vowel: " << vowelWords << endl;
    cout << "Words starting with Consonant: " << consonantWords << endl;

    return 0;
}
