#include <set>
#include <map>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<string>> syn;
    string word_1;
    string word_2;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "ADD") {
            cin >> word_1 >> word_2;
            syn[word_1].insert(word_2);
            syn[word_2].insert(word_1);
        } else if (command == "COUNT") {
            cin >> word_1;
            cout << syn[word_1].size() << endl;
        } else if (command == "CHECK") {
            cin >> word_1 >> word_2;
            if (syn.count(word_1) && syn[word_1].count(word_2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
