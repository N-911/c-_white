#include <iostream>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    while (n > 0 && m > 0) {
        if (n > m) {
            n %= m;
        } else {
            m %= n;
        }
    }
    cout << n + m;
    return 0;
}
