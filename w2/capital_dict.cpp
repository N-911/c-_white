#include <map>
#include <string>
#include <iostream>

using namespace std;

void print_dict(const map<string, string>& dict_country) {
    for (const auto& x : dict_country) {
        cout << x.first << "/" << x.second << " ";
    }
    cout << endl;
}
int main() {
    int count;
    cin >> count;
    map<string, string> dict_country;

    for (int i = 0; i < count; ++i) {
        string operation;
        string country;
        string new_capital;
        cin >> operation;
        if (operation == "DUMP") {
            if (dict_country.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                print_dict(dict_country);
            }
        }
        else if (operation == "ABOUT") {
            cin >> country;
            if (dict_country.count(country) == 1) {
                cout << "Country " << country << " has capital " << dict_country[country] << endl;
            } else {
                cout << "Country " << country << " doesn't exist" << endl;
            }
        } else if (operation == "CHANGE_CAPITAL") {
            cin >> country >> new_capital;
            if (dict_country.count(country) == 0) {
                dict_country[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else if (dict_country[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;

            } else {
                cout << "Country " << country << " has changed its capital from " << dict_country[country] <<
                 " to " << new_capital << endl;
                dict_country[country] = new_capital;
            }
        } else if (operation == "RENAME") {
            string old_country_name;
            string new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || dict_country.count(old_country_name) == 0 ||
                dict_country.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                dict_country[new_country_name] = dict_country[old_country_name];
                dict_country.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital " <<  dict_country[new_country_name] <<
                " has been renamed to " << new_country_name << endl;
            }

        }
    }
    return 0;
}
