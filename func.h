#ifndef FUNC_H
#define FUNC_H

class Polynom
{
public:
    Polynom(int a);
    ~ Polynom();
    Polynom(const Polynom &org);
    Polynom operator+(const Polynom &sum);
    Polynom operator*(const Polynom &ar);
    Polynom & operator=(const Polynom &org);
    Polynom proizvodnaya (const Polynom &ar);
    Polynom integral (const Polynom &ar);

private:
    class PolynomIm;
    PolynomIm *pimpl;
    Polynom(const PolynomIm &org);

protected:
    int get_n()const;
    double *get_x()const;

};

#endif // FUNC_H
