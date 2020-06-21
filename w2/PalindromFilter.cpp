#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool IsPalindrom(string a);
vector<string> PalindromFilter (vector<string> words, int minLength);

static bool IsPalindrom(string a) {
    if (a.empty())
        return true;
    for (size_t i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1])
            return false;
    }
    return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
    vector<string> filter;

    for (auto x : words) {
        if (x.size() >= minLength && IsPalindrom(x))
            filter.push_back(x);
    }
    return filter;
}

