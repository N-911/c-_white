#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        fam[year].first_name = first_name;
        update_fam(year);
    }

    void ChangeLastName(int year, const string& last_name) {
        fam[year].last_name = last_name;
        update_fam(year);
    }

    string GetFullName(int year) {
        string res;
        if (fam.count(year) == 0) {
            ChangeFirstName(year, "");
//            ChangeLastName(year, "");
        }
        if (fam[year].first_name.empty() && fam[year].last_name.empty()) {

            res = "Incognito";
        }
        else {
//            update_fam(year);
            if (fam[year].first_name.empty()) {
                res += fam[year].last_name;
                res += "with unknown first name";
            } else if (fam[year].last_name.empty()) {
                res += fam[year].first_name;
                res += " with unknown last name";
            } else {
                res += fam[year].first_name;
                res += " ";
                res += fam[year].last_name;
            }
        }
        return res;
    }
private:
    struct name {
        string first_name;
        string last_name;
    };
    map<int, name, greater<int>> fam;

    void update_fam(int year) {
        map<int , name> ::iterator i;
//        cout << "update_fam " << year << endl;
        if (!fam[year].first_name.empty() && !fam[year].last_name.empty()) {
//            i = fam.upper_bound(year);
            cout << "update " << i->first << endl;
            for (i =  fam.upper_bound(year); i != fam.begin(); i--) {
                cout << "update " << i->first << endl;
                if (fam[year].first_name != i->second.first_name) {
                    if (i != end(fam)) {
                        i->second.first_name = fam[year].first_name;
                    }
                }
                if (fam[year].last_name!= i->second.first_name) {
                    if (i != end(fam)) {
                        i->second.last_name = fam[year].last_name;
                    }
                }

            }
        }
        else {
            i = fam.lower_bound(year - 1);
            if (fam[year].first_name.empty()) {
//            fam[year].first_name = fam.lower_bound(year)->second.first_name;
                if (i != end(fam)) {
                    fam[year].first_name = i->second.first_name;
                }
            }
            if (fam[year].last_name.empty()) {
                if (i != end(fam)) {
                    fam[year].last_name = i->second.last_name;
                }
            }
        }
    }
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

