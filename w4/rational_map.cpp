#include <iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;


class Rational {
public:
    Rational() {
        numerator1 = 0;
        denominator1 = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0 && numerator > 0) {
            numerator1 = -numerator;
            denominator1 = abs(denominator);
        }
        else if (denominator < 0 && numerator < 0){
            numerator1 = abs(numerator);
            denominator1 = abs(denominator);
        }
        else if (numerator == 0) {
            numerator1 = 0;
            denominator1 = 1;
        }
        else {
            numerator1 = numerator;
            denominator1 = abs(denominator);
        }
    }


    int Numerator() const {
        int temp = gcd(numerator1, denominator1);
        return numerator1 / temp;
    }

    int Denominator() const {
        int temp = gcd(numerator1, denominator1);
        return  denominator1 / temp;
    }

private:
    int numerator1;
    int denominator1;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) {
        return true;
    }
    else {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational((lhs.Numerator() * (temp / lhs.Denominator())) +
                    (rhs.Numerator() * (temp / rhs.Denominator())), temp);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational((lhs.Numerator() * (temp / lhs.Denominator())) -
                    (rhs.Numerator() * (temp / rhs.Denominator())), temp);
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int n = 0;
    int d = 0;

    if (stream) {
        stream >> n;
    }
    else {
        return stream;
    }
    stream.ignore(1);
    if (stream) {
        stream >> d;
    }
    else {
        return stream;
    }
    rational = Rational(n, d);
    return stream;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    if ((lhs.Numerator() * (temp / lhs.Denominator())) >
                    (rhs.Numerator() * (temp / rhs.Denominator()))) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    if ((lhs.Numerator() * (temp / lhs.Denominator())) <
        (rhs.Numerator() * (temp / rhs.Denominator()))) {
        return true;
    }
    else {
        return false;
    }
}



int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
