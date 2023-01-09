#pragma once
#include <iostream>

using namespace std;

unsigned int NOD(unsigned int a, unsigned int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return NOD(a % b, b);
    return NOD(a, b % a);
}

class Fraction
{
private:
    long c;
    long numerator;
    long denominator;
public:

    Fraction()
    {
        c = 0;
        numerator = 0;
        denominator = 1;
    }

    Fraction(int c) : c(c), numerator(0), denominator(1)
    {

    }

    Fraction(int af, int bf, int cf) : c(af), numerator(bf), denominator(cf)
    {
        /*if (af < 0)
        {
            c = 0;
        }
        else
        {
            c = af;
        }
        if (bf <= 0)
        {
            numerator = 1;
        }
        else
        {
            numerator = bf;
        }
        if (cf <= 0)
        {
            denominator = 0;
        }
        else
        {
            denominator = cf;
        }*/
    }
    Fraction(int bf, int cf) : c(0), numerator(bf), denominator(cf)
    {
       /* c = 0;
        if (bf <= 0)
        {
            numerator = 1;
        }
        else
        {
            numerator = bf;
        }
        if (cf <= 0)
        {
            denominator = 0;
        }
        else
        {
            denominator = cf;
        }*/
    }

    void set_whole(int a)
    {
        if (a < 0)
        {
            c = 0;
        }
        else
        {
            c = a;
        }
    }

    void set_numerator(int a)
    {
        if (a <= 0)
        {
            numerator = 1;
        }
        else
        {
            numerator = a;
        }
    }

    void set_denominator(int a)
    {
        if (a <= 0)
        {
            denominator = 1;
        }
        else
        {
            denominator = a;
        }
    }

    long get_whole() const
    {
        return c;
    }

    long get_numerator() const
    {
        return numerator;
    }

    long get_denominator() const
    {
        return denominator;
    }

    void print()
    {
        if (c == 0 and numerator == 0)
        {
            cout << 0;
            return;
        }
        if (numerator == 0)
        {
            cout << c;
            return;
        }
        if (c == 0)
        {
            cout << numerator << endl;
            cout << denominator << endl;
            cout << endl;
        }
        else
        {
            cout << "  " << numerator << endl;
            cout << c << " " << denominator << endl;
            cout << endl;
        }
    }

    Fraction whole_destroy()
    {
        if (c == 0)
        {
            return *this;
        }
        numerator = (c * denominator) + numerator;
        c = 0;
    }

    Fraction improperand_to_proper()
    {
        if (numerator < denominator)
        {
            return *this;
        }
        c = numerator / denominator;
        numerator -= denominator * c;
    }

    Fraction operator*(Fraction f2)
    {
        return Fraction();
    }

    Fraction operator*(int f)
    {
        return *this * Fraction(f);
    }

    friend Fraction operator*(int n, Fraction f);


    Fraction operator+(Fraction f2)
    {
        Fraction res;

        whole_destroy();
        f2.whole_destroy();

        res.c = 0;
        res.numerator = numerator * f2.denominator + f2.numerator * denominator;
        res.denominator = denominator * f2.denominator;

        int a = NOD(res.numerator, res.denominator);

        res.numerator = res.numerator / a;
        res.denominator = res.denominator / a;

        res.improperand_to_proper();

        return res;
    }

    Fraction minFraction(Fraction f2)
    {
        Fraction res;

        whole_destroy();
        f2.whole_destroy();

        res.c = 0;
        res.numerator = numerator * f2.denominator - f2.numerator * denominator;
        res.denominator = denominator * f2.denominator;

        int a = NOD(res.numerator, res.denominator);

        res.numerator = res.numerator / a;
        res.denominator = res.denominator / a;

        res.improperand_to_proper();

        return res;
    }

    Fraction multiFraction(Fraction f2)
    {
        Fraction res;

        whole_destroy();
        f2.whole_destroy();

        res.c = 0;
        res.numerator = numerator * f2.numerator;
        res.denominator = denominator * f2.denominator;

        int a = NOD(res.numerator, res.denominator);

        res.numerator = res.numerator / a;
        res.denominator = res.denominator / a;

        res.improperand_to_proper();

        return res;
    }

    Fraction divFraction(Fraction f2)
    {
        Fraction res;

        whole_destroy();
        f2.whole_destroy();

        res.c = 0;
        res.numerator = numerator * f2.denominator;
        res.denominator = denominator * f2.numerator;

        int a = NOD(res.numerator, res.denominator);

        res.numerator = res.numerator / a;
        res.denominator = res.denominator / a;

        res.improperand_to_proper();

        return res;
    }

    Fraction operator-()
    {
        return Fraction(-numerator, denominator);
    }

    Fraction operator+()
    {
        return *this;
    }

    Fraction operator++() // prefix
    {
        c += 1;
        return *this;
    }

    Fraction operator++(int) // postfix
    {
        Fraction res(*this);
        c += 1;
        return res;
    }

    bool operator!()
    {
        return numerator == 0;
    }

    bool operator==(const Fraction& f)
    {
        return c == f.c && numerator == f.numerator && denominator == f.denominator;
    }

    bool operator!=(const Fraction& f)
    {
        return !(*this == f);
    }

    /*bool operator>(const Fraction& f)
    {
        return (float)(c * denominator + numerator) / denominator > (float)(f.c * f.denominator + f.numerator) / f.denominator;
    }

    bool operator<(const Fraction& f)
    {
        return (float)(c * denominator + numerator) / denominator < (float)(f.c * f.denominator + f.numerator) / f.denominator;
    }*/

    auto operator<=>(const Fraction& f) const
    {
        return (float)(c * denominator + numerator) / denominator <=> (float)(f.c* f.denominator + f.numerator) / f.denominator;
    }

    operator bool()
    {
        return numerator;
    }

    operator double()
    {
        return (double)(c * denominator + numerator) / denominator;
    }

    operator float()
    {
        return (float)(c * denominator + numerator) / denominator;
    }

    void operator()(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    long& operator[](int ind)
    {
        if (ind == 0)
            return c;
        if (ind == 1)
            return numerator;
        if (ind == 2)
            return denominator;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);

    //friend Fraction operator+(Fraction f1, Fraction f2);
};


Fraction operator*(int n, Fraction f)
{
    return f * n;
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    if (f.c)
        out << f.c << ".";
    out << f.numerator << "/" << f.denominator;
    return out;
}

inline istream& operator>>(istream& in, Fraction& f)
{
    in >> f.c >> f.numerator >> f.denominator;
    return in;
}

//Fraction operator+(Fraction f1, Fraction f2)
//{
//    Fraction res;
//
//    f1.whole_destroy();
//    f2.whole_destroy();
//
//    res.c = 0;
//    res.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
//    res.denominator = f1.denominator * f2.denominator;
//
//    int a = NOD(res.numerator, res.denominator);
//
//    res.numerator = res.numerator / a;
//    res.denominator = res.denominator / a;
//
//    res.improperand_to_proper();
//
//    return res;
//}


//Fraction operator+(Fraction f1, Fraction f2)
//{
//    Fraction res;
//
//    f1.whole_destroy();
//    f2.whole_destroy();
//
//    res.set_whole(0);
//    res.set_numerator( f1.get_numerator() * f2.get_denominator() + f2.get_numerator() * f1.get_denominator());
//    res.set_denominator(f1.get_denominator() * f2.get_denominator());
//
//    int a = NOD(res.get_numerator(), res.get_denominator());
//
//    res.set_numerator(res.get_numerator() / a);
//    res.set_denominator(res.get_denominator() / a);
//
//    res.improperand_to_proper();
//
//    return res;
//}