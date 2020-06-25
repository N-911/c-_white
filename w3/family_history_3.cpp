#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

string vector_name_to_str(vector<string> v) {
    string res;
    int c = v.size();

    reverse(begin(v), end(v));
    res += v[0];
    if (v.size() > 1) {
        res += " (";
        for (int i = 1; i < c ; ++i) {
            res += v[i];
            if (i + 1 < c) {
                res += ", ";
            }
            else {
                res += ")";
            }
        }
    }
    return res;
}


class Person {
public:

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birthday) {
            fam[year].first_name = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birthday) {
            fam[year].last_name = last_name;
        }
    }
    vector<string> find_change(int year) const {
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


    string GetFullNameWithHistory(int year) const {
        if (year < birthday) {
            return "No person";
        }
        vector<string> f_n;
        vector<string> l_n;

        for (auto& i : fam) {
            if (i.first <= year) {
                if (!i.second.first_name.empty() && (f_n.empty() || (i.second.first_name != f_n.back()))) {
                    f_n.push_back(i.second.first_name);
                }
                if (!i.second.last_name.empty() && (l_n.empty() || (i.second.last_name != l_n.back()))) {
                    l_n.push_back(i.second.last_name);
                }
            }
        }
        string res;

        if (f_n.empty() && l_n.empty()) {
            res = "Incognito";
        }
        else if (f_n.empty()) {  // if first name not changed
            res = vector_name_to_str(l_n);
            res += " with unknown first name";
        }
        else if (l_n.empty()) {  // if last name not changed
            res = vector_name_to_str(f_n);
            res += " with unknown last name";
        }
        else {
            res = vector_name_to_str(f_n);
            res += " ";
            res += vector_name_to_str(l_n);
        }
        return res;
    }

    string GetFullName(int year) const {
        if (year < birthday) {
            return "No person";
        }
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

     Person (const string& f_n, const string& l_n, int year){
        fam[year].first_name = f_n;
        fam[year].last_name = l_n;
        birthday = year;
    }

private:
    struct name {
        string first_name;
        string last_name;
    };
    int birthday;
    map<int, name> fam;

};


