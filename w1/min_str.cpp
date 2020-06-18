#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> in_str = {" ", " ", " "};
    std::cin >> in_str[0] >> in_str[1] >> in_str[2];
    if (in_str[0] <= in_str[1] && in_str[0] <= in_str[2])
        std::cout << in_str[0];
    else if (in_str[1] <= in_str[0] && in_str[1] <= in_str[2])
        std::cout << in_str[1];
    else
        std::cout << in_str[2];
    return 0;
}
