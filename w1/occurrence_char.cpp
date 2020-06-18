#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    int res = 0;
    int index;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'f') {
            res++;
            index = i;
        }
        if (res == 2)
            break;
    }
    if (res == 0)
        cout << -2 << endl;
    else if (res == 1)
        cout << -1 << endl;
    else
        cout << index << endl;
    return 0;
}