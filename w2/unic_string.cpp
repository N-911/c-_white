#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> u_set;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        u_set.insert(s);
    }
    cout << u_set.size() << endl;

    return 0;
}
