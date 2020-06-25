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
    string GetFullName(int year) {
        string res;
        string first_n;
        string second_n;

        for (auto& i : fam) {
            if (i.first <= year) {
                if (!i.second.first_name.empty())
                    first_n = i.second.first_name;
                if (!i.second.last_name.empty())
                    second_n = i.second.last_name;
            }
            else {
                break;
            }
        }
        if (first_n.empty() && second_n.empty()) {
            res = "Incognito";
        }
        else if (first_n.empty()) {
            res += second_n;
            res += " with unknown first name";
        }
        else if (second_n.empty()) {
            res += first_n;
            res += " with unknown last name";
        } else {
            res += first_n;
            res += " ";
            res += second_n;
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


