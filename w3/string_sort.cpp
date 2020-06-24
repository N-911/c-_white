#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SortedStrings {

public:
    void AddString(const string& s) {
        v_str.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(v_str), end(v_str));
        return v_str;
    }
private:
    vector<string> v_str;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}

