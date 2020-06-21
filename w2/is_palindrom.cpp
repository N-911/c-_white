#include <string>

using namespace std;

bool IsPalindrom(string a) {
    if (a.empty())
        return true;
    for (size_t i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1])
            return false;
    }
    return true;
}
