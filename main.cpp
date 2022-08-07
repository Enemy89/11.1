#include <iostream>
#include <string>

using namespace std;

string encrypt_caesar(string line, int shift) {
    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] += shift;
            if (line[i] > 122) {
                line[i] -= 26;
            }
        }
        else {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                line[i] += shift;
                if (line[i] > 90) {
                    line[i] -= 26;
                }
            }
        }
    }
    return line;
}

string decrypt_caesar(string line, int shift) {
    encrypt_caesar(line, -shift);
    return line;
}

int main() {
    string line;
    int shift, mark;
    cout << "Enter the string and the number of offset characters:" << endl;
    getline(cin, line);
    cin>>shift;
    cout << encrypt_caesar(line, shift)<< endl;
    cout << "Decrypt the string? (0-no, 1-yes)" << endl;
    cin>>mark;
    cout<<(mark==1 ? decrypt_caesar(line,shift) :  encrypt_caesar(line, shift));
}
