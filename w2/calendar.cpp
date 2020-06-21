#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void print_list_month (const vector<vector<string>>& month, int day);

void print_list_month (const vector<vector<string>>& month, int day) {
    cout << month[day].size() << " ";
    for (auto x : month[day]) {
        cout << x << " ";
    }
    cout << endl;
}

vector<vector<string>> new_month(const vector<vector<string>>& month, int current_m, int next_m) {
    vector<int> days_in_m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cur_m_days = days_in_m[current_m];

    int nex_m_days = days_in_m[next_m];
    vector<vector<string>> new_month(nex_m_days);

    int j = 0;
    for (int i = 0; i < cur_m_days; ++i) {
        if ( j < nex_m_days) {
            new_month[j].insert(new_month[j].end(), month[i].begin(), month[i].end());
            ++j;
        } else {
            new_month[j - 1].insert(new_month[j - 1].end(), month[i].begin(), month[i].end());
        }
    }
    return new_month;
}

int main() {
    int count;  // count commands
    int current_month = 0;  // january
    int day;
    cin >> count;

    vector<vector<string>> month(31);

    for (int i = 0; i < count; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "DUMP") {
            cin >> day;
            print_list_month(month, day - 1);
        } else {
            if (operation_code == "ADD") {
                string task;
                cin >> day >> task;
                month[day - 1].push_back(task);
            } else if (operation_code == "NEXT") {
                int next_m = (current_month + 1) % 12;
                month = new_month(month, current_month, next_m);
                current_month = next_m;
            }
        }
    }
    return 0;
}