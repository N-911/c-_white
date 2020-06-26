#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    ifstream from_file("input.txt");
    double number;

    cout << fixed << setprecision(3);
    while( from_file >> number) {
        cout << number << endl;
    }
    return 0;
}