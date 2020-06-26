#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
   ifstream file("input.txt");
   int n;
   int m;

    if (file) {
        file >> n;
        file.ignore(1);
        file >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int number;
                file >> number;
                cout << setw(10) << number;
                if (j + 1 < m) {
                    cout << ' ';
                }
                file.ignore(1);
            }
            if (i + 1 < n) {
                cout << endl;
            }
        }
    }
    return 0;
}
