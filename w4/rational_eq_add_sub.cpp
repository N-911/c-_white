#include <iostream>
#include <numeric>

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
        }
        else if (denominator < 0 && numerator < 0){
            numerator1 = abs(numerator);
        }
        else {
            numerator1 = numerator;
        }
        denominator1 = abs(denominator);
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
