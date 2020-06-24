#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;



class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        fam[year].first_name = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        fam[year].last_name = last_name;
    }
    vector<string> find_change(int year) {
        vector<string> res(2);
        for (auto& i : fam) {
            if (i.first <= year) {
                if (!i.second.first_name.empty())
                    res[0] = i.second.first_name;
                if (!i.second.last_name.empty())
                    res[1] = i.second.last_name;
            }
            else {
                break;
            }
        }
        return res;
    }
    string GetFullNameWithHistory(int year) {
        vector<string> f_n;
        vector<string> l_n;

        string temp;
        string temp2;
        for (auto& i : fam) {
            if (i.first <= year) {
                if (!i.second.first_name.empty() && i.second.first_name != temp) {
                    f_n.push_back(i.second.first_name);
                    temp = i.second.first_name;
                }
                if (!i.second.last_name.empty() && i.second.last_name != temp2) {
                    l_n.push_back(i.second.last_name);
                    temp2 = i.second.last_name;
                }
            }
        }
        string res;
        if (f_n.empty() && l_n.empty()) {
            res = "Incognito";
        }
        else if (f_n.empty()) {
//            res += f_n[f_n.size() - 1]
            for (int i = f_n.size(); i > 0 ; i--) {
                res += f_n[i];
            }
            res += " with unknown first name";
        }
        else if (l_n.empty()) {
            for (int i = l_n.size(); i > 0; i--) {
                res += l_n[i];
            }
            res += " with unknown last name";
        } else {
            if (f_n.size() > 1) {
                res += f_n[f_n.size() - 1];
                res += " (";
                for (int i = f_n.size() - 2; i >= 0; i--) {
                    res += f_n[i];
                    if (i == 0)
                        res += ")";
                    else
                        res += " , ";
                }
            }
            else {
                res += f_n[0];
            }
            res += " ";
            if (l_n.size() > 1) {
                res += l_n[f_n.size() - 1];
                res += " (";
                for (int i = l_n.size() - 2; i >= 0; i--) {
                    res += l_n[i];
                    if (i == 0)
                        res += ")";
                    else
                        res += " , ";
                }
            }
            else {
                res += l_n[0];
            }
        }
        return res;

    }
    string GetFullName(int year) {
        vector<string> last_changes = find_change(year);
        string res;
        if (last_changes[0].empty() && last_changes[1].empty()) {
            res = "Incognito";
        }
        else if (last_changes[0].empty()) {
            res += last_changes[1];
            res += " with unknown first name";
        }
        else if (last_changes[1].empty()) {
            res += last_changes[0];
            res += " with unknown last name";
        } else {
            res += last_changes[0];
            res += " ";
            res += last_changes[1];
        }
        return res;
    }
private:
    struct name {
        string first_name;
        string last_name;
    };
    map<int, name> fam;

};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}




