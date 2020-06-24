#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#ifndef W3_STRING_SORT_H
#define W3_STRING_SORT_H


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


#endif //W3_STRING_SORT_H
