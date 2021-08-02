#include <iostream>
#include <string>

using namespace std;

void encryption_func(char* s, int k, int pos) {

    if ((int)s[pos] != 32) { //Check if it's a space. In that case ignore it
        s[pos] = (((((int)s[pos]) - 97) + k) % 26) + 97; //Encrypting function as PosNewLetter = (PosOldLetter + k) mod 26
        //Subtract 97 because the position of 'a' in the ascii code is 97 and the module has to be done on numbers from 0 to 25
    }
    else {
    }

}

void decryption_func(char* s, int k, int pos) {

    if ((int)s[pos] != 32) { //Check if it's a space. In that case ignore it

            //Check if the module is done on a negative number. If that's the case we need to take care manually of
            //such operation as the sign of the remainder is implementation-defined.
        if (((int)s[pos] - 97) - k < 0) { //Check if the module is done on a negative number
            int moduleCheck;
            int moduleSi = (((int)s[pos] - 97) - k) % 26; // To make it work: (s = (-a mod b = -a)) => (s = (b - a))
            moduleCheck = 26 + moduleSi;
            s[pos] = moduleCheck + 97;

        }
        else { //If the module is done on a positive number
            s[pos] = (((((int)s[pos]) - 97) - k) % 26) + 97; //Decrypting function as PosOldLetter = (PosNewLetter - k) mod 26
            //Subtract 97 because the position of 'a' in the ascii code is 97 and the module has to be done on numbers from 0 to 25
        }

    }

}

//This function will call the encryption function on the copied string
void encrypt(string s, int k) {
    for (unsigned int i = 0; i < size(s); ++i) {

        encryption_func(&s[0], k, i);
        
    }

    cout << "Result of copying function: ";
    for (unsigned int i = 0; i < size(s); ++i) {
        cout << s[i];
    }
    cout << endl;

    return;
}

//This function will call the encryption function on the original string
void encrypt_del(char* s, int k, int size) {
    for (signed int i = 0; i < size; ++i) {

        encryption_func(&s[0], k, i);
        
    }
}

//This function will call the decryption function on the original string
void decrypt_del(char* s, int k, int size) {
    for (signed int i = 0; i < size; ++i) {
        
        decryption_func(&s[0], k, i);
        
    }
}

int main()
{
    string s; //Message or Cripto
    int k; //Rotating Factor
    char choose;

    cout << "Decide if you want to Encrypt (e) or Decrypt (d)" << endl;
    cin >> choose;
    while ((choose != 'e') && (choose != 'd')) {
        cout << "Choose either e or d" << endl;
        cin >> choose;
    }

    switch (choose) {

    case 'e': //Encrypt

        cout << "Input the string" << endl;
        cin.ignore(); //Ignore the blank space that remains from the input of char choose
        getline(cin, s);
        cout << "Input the rotating factor" << endl;
        cin >> k;

        encrypt(s, k);

        cout << "Original string after copying function: ";
        for (unsigned int i = 0; i < size(s); ++i) {
            cout << s[i];
        }
        cout << endl;

        encrypt_del(&s[0], k, size(s));

        cout << "Original string after Encryption function: ";
        for (unsigned int i = 0; i < size(s); ++i) {
            cout << s[i];
        }
        cout << endl;

        break;

    case 'd': //Decrypt

        cout << "Input the string" << endl;
        cin.ignore(); //Ignore the blank space that remains from the input of char choose
        getline(cin, s);
        cout << "Input the rotating factor" << endl;
        cin >> k;

        decrypt_del(&s[0], k, size(s));

        cout << "String after Decrypting function: ";
        for (unsigned int i = 0; i < size(s); ++i) {
            cout << s[i];
        }
        cout << endl;

        break;

    default:
        //
        break;

    }
    

    return 0;
}
