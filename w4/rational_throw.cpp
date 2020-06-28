#include <iostream>
#include <exception>
#include <stdexcept>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    };
    Rational(int n, int d) {
        int temp = gcd(n, d);
        if (d == 0) {
            throw invalid_argument(" d = 0");
        }
        if (n == 0) {
            throw domain_error("n = 0");
        }
        numerator = n / temp;
        denominator = d /temp;
        if (d < 0) {
            numerator = -n;
            denominator = -d;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return  denominator;
    }

private:
    int numerator;
    int denominator;
};

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * rhs.Numerator()};
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
