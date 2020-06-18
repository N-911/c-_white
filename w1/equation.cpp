#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, D;

    cin >> a >> b >> c;
    D = b * b - 4 * a * c;
    if (D == 0 && a)
        cout << (-b / (2 * a)) << endl;
    else if (D > 0 && !a && b)
       cout <<  -1 * c / b;
    else if (D > 0 && a) {
        cout << ((-b + sqrt(D)) / (2 * a)) << " ";
        cout << ((-b - sqrt(D)) / (2 * a)) << endl;
    }
    return 0;
}
