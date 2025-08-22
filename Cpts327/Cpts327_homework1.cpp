#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

string Decrypt(const string& ciphertext, const string& key) {
    string plaintext;
    int keyLength = key.length();
    for (int i = 0, j = 0; i < ciphertext.length(); ++i) {
        char currentChar = ciphertext[i];
        if (islower(currentChar)) {
            char keyChar = tolower(key[j % keyLength]);
            char shift = currentChar - 'a';
            char decryptedChar = 'a' + (shift - (keyChar - 'a') + 26) % 26; // Added +26 to handle negative modulo
            plaintext += decryptedChar;
            ++j;
        }
        else {
            plaintext += currentChar;
        }
    }
    return plaintext;
}

unordered_map<char, int> Occurrences(const string& ciphertext) {
    unordered_map<char, int> occurence; // The character and the number of times it occurs
    for (char curChar : ciphertext) {  // Going through the whole string of ciphertext
        if (isalpha(curChar)) {
            char lowChar = std::tolower(curChar);
            if (occurence.find(lowChar) != occurence.end()) {
                occurence[lowChar]++;
            } else {
                occurence[lowChar] = 1;
            }
        }
    }
    return occurence;
}

int main() {

        // Code about occurrence
    string ciphertextUsed = "whokhusjew cqfmrmekse mjgwwrq laewkbs gevnnse,qarecz tiwpej ggtlscv gbeyid, cbp qkvp. ygg tqpwooz mo twcbzmjk lp wz-tavdqb pvqq nkfopa, my-rsdwkr lpr xmridvfqeiio tsovaeekczeh gwcgeio, eyf qdiwxtxwfc wro cffw sscmgtslw, tpqxyzmyi o yeyvlos opwwd. ygg iricghf aepw czes dsdv o yeyvlos opwwd";
    unordered_map<char, int> occurrence = Occurrences(ciphertextUsed);
    cout << "Letter Occurrences: { ";
    for (const auto& pair : occurrence) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << "}" << endl;

    string ciphertext, key;
    // Input ciphertext and key
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);
    cout << "Enter the key: ";
    getline(cin, key);

    // Decrypt the ciphertext using the Vigenere cipher
    string decryptedText = Decrypt(ciphertext, key);

    // Display the decrypted text
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}