#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet (const map<int, string>& m) {
    set<string> res;
    for (const auto& val : m) {
        res.insert(val.second);
    }
    return res;

}

int main() {
    map<int, string> m = {{1, "odd"}, {2, "even"}, {3, "odd"}};
    set<string> s = BuildMapValuesSet(m);
    for (const string& v : s) {
        cout << v << endl;
    }
    return 0;
}
