#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string& word) {
    map<char, int> count_c;
    for (auto x : word)
        ++count_c[x];
    return count_c;
}

int main () {
    int count;

    cin >> count;
    for (int i = 0; i < count; ++i) {
        string w1, w2;
        cin >> w1 >> w2;
        if (BuildCharCounters(w1) == BuildCharCounters(w2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
