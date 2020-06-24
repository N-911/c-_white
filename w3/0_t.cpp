#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
class Person{
private:
    map <int, string> first_names;
    map <int, string> last_names;
public:
    void ChangeFirstName(int year, const string& first_name){
        // izmenenie imeni v god
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name){
        // izmenenie familii v god
        last_names[year] = last_name;
    }
    string GetFullName(int year){
        // poluchit' polnoe imya
        string First_name;
        string Last_name;
        bool ChangeFirstName = false;
        bool ChangeLastName = false;
        for (const auto& name : first_names){
            if (name.first <= year){
                First_name = name.second;
                ChangeFirstName = true;
            }
        }
        for (const auto& surname : last_names){
            if (surname.first <= year){
                Last_name = surname.second;
                ChangeLastName = true;
            }
        }
        stringstream ss;
        if (ChangeFirstName == false && ChangeLastName == false){
            ss << "Incognito" << endl;
            return ss.str();
        }
        if (ChangeFirstName == true && ChangeLastName == false){
            ss << First_name << " first name with unknown last name" << endl;
            return ss.str();
        }
        if (ChangeFirstName == false && ChangeLastName == true){
            ss << Last_name << " last name with unknown first name" << endl;
            return ss.str();
        }
        if (ChangeFirstName == true && ChangeLastName == true){
            ss << First_name << " " << Last_name << endl;
            return ss.str();
        }
    }
};
int main(){
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}){
        cout << person.GetFullName(year);
    }
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}){
        cout << person.GetFullName(year);
    }
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}){
        cout << person.GetFullName(year);
    }
    return 0;
}
