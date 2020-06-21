#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n;

    cin >> n;
    vector<int> q_index(n);
    vector<string> q_type(n);
    vector<bool> q(0, false);
    for (int i = 0; i < n; ++i) {
        cin >> q_type[i];
        if (q_type[i] != "WORRY_COUNT")
            cin >> q_index[i];
        else
            q_index[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (q_type[j] == "COME") {
            q.resize(q.size() + q_index[j]);
        }
        else if (q_type[j] == "QUIET") {
            q[q_index[j]] = false;
        }
        else if (q_type[j] == "WORRY") {
            q[q_index[j]] = true;
        }
        else if (q_type[j] == "WORRY_COUNT") {
            cout << count(begin(q), end(q), true) << endl;
        }
    }
    return 0;
}
