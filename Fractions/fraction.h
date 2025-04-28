#include <iostream>
#include <cstdlib>

namespace math {

    template<typename T>
    class Fraction {
    private:
        T numerator;
        T denominator;

    public:
        Fraction(T num = 0, T denom = 1) {
            if (denom < 1) {
                denom = 1;
            }
            numerator = num;
            denominator = denom;
        }

        T getNumerator() const { return numerator; }
        T getDenominator() const { return denominator; }

        void simplify() {
            T gcd = findGCD(std::abs(numerator), std::abs(denominator));
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        double toDouble() const {
            return static_cast<double>(numerator) / denominator;
        }

        Fraction operator+(const Fraction& other) const {
            Fraction result(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
            result.simplify();
            return result;
        }

        Fraction operator-(const Fraction& other) const {
            Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
            result.simplify();
            return result;
        }

        Fraction operator*(const Fraction& other) const {
            Fraction result(numerator * other.numerator, denominator * other.denominator);
            result.simplify();
            return result;
        }

        Fraction operator/(const Fraction& other) const {
            if (other.numerator == 0) {
                throw std::invalid_argument("Cannot divide by zero fraction.");
            }
            Fraction result(numerator * other.denominator, denominator * other.numerator);
            result.simplify();
            return result;
        }

        bool operator==(const Fraction& other) const {
            return numerator * other.denominator == other.numerator * denominator;
        }

        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }

        bool operator<(const Fraction& other) const {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator>(const Fraction& other) const {
            return other < *this;
        }

        bool operator<=(const Fraction& other) const {
            return !(*this > other);
        }

        bool operator>=(const Fraction& other) const {
            return !(*this < other);
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Fraction<U>& frac);

        template<typename U>
        friend std::istream& operator>>(std::istream& is, Fraction<U>& frac);

    private:
        T findGCD(T a, T b) const {
            while (b != 0) {
                T temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };

    template<typename U>
    std::ostream& operator<<(std::ostream& os, const Fraction<U>& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    template<typename U>
    std::istream& operator>>(std::istream& is, Fraction<U>& frac) {
        U num{}, denom{};
        char slash = 0;
        is >> num >> slash >> denom;
        if (slash != '/' || denom == 0) {
            is.setstate(std::ios::failbit);
        }
        else {
            frac = Fraction<U>(num, denom);
        }
        return is;
    }
}