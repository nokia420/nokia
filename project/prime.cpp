#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimesInRange(int start, int end) {
    cout << "Prime numbers between " << start << " and " << end << " are:" << endl;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout <<endl;
}

int main() {
    int start, end;

    cout << "Enter starting number: ";
    cin >> start;
    cout << "Enter ending number: ";
    cin >> end;

    if (start >= end) {
        cout << "Ending number should be greater than starting number." << endl;
        return 1;
    }

    printPrimesInRange(start, end);

    return 0;
}
