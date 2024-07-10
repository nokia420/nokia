#include <iostream>
#include <string>

using namespace std;

void printPattern(const string &word) {
    int length = word.length();

    for (int i = 0; i < length; ++i) {
        cout << word.substr(0, i + 1) << endl;
    }
        for (int i = length - 1; i > 0; --i) {
        cout << word.substr(0, i) << endl;
    }
}

int main() {
    string word = "display";
    printPattern(word);

    return 0;
}
