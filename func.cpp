#include "func.h"
class Polynom::PolynomIm
{
public:

    PolynomIm(int a);
    ~ PolynomIm();
    PolynomIm(const PolynomIm &org);
    PolynomIm &operator=(const PolynomIm &org);
    PolynomIm operator+(const PolynomIm &sum);
    PolynomIm operator*(const PolynomIm &ar);
    PolynomIm proizvodnaya (const PolynomIm &ar);
    PolynomIm integral (const PolynomIm &ar);

    int get_n()const;
    double *get_x()const;

private:
    int n;
    double *x;
};

//***********************************

Polynom::Polynom(int a):
    pimpl(0)
{
    pimpl = new PolynomIm(a);

}

Polynom::~Polynom()
{
    delete pimpl;
    pimpl=0;

}
Polynom::Polynom(const Polynom &org):
    pimpl(0)
{
    pimpl = new PolynomIm(*(org.pimpl));

}

Polynom &Polynom::operator=(const Polynom &org)
{
    *(this->pimpl) = *(org.pimpl);
    return *this;
}

Polynom Polynom::operator+(const Polynom &sum)
{
    return Polynom(pimpl->operator+(*(sum.pimpl)));
}

Polynom Polynom::operator*(const Polynom &ar)
{
    return Polynom(pimpl->operator*(*(ar.pimpl)));
}

Polynom Polynom::proizvodnaya(const Polynom &ar)
{
    return Polynom(pimpl->proizvodnaya(*(ar.pimpl)));
}

Polynom Polynom::integral(const Polynom &ar)
{
    return Polynom(pimpl->integral(*(ar.pimpl)));
}

int Polynom::get_n()const
{

    return pimpl->get_n();
}
double *Polynom::get_x()const
{
    return pimpl->get_x();
}

//***********************************
Polynom::PolynomIm::PolynomIm(int a):
    n(a), x(0)
{

    x=new double[n+1];
};

Polynom::PolynomIm::~PolynomIm()
{
    delete[]x;
    x=0;
}
Polynom::Polynom(const PolynomIm &org):
    pimpl(0)
{
    pimpl = new PolynomIm(org);

}
Polynom::PolynomIm::PolynomIm(const PolynomIm& org):
    n(org.n), x(0)
{
    x=new double[n+1];
    for(int i=n; i>=0; i--)
        x[i]=org.x[i];
}

Polynom::PolynomIm &Polynom::PolynomIm::operator=(const PolynomIm &org)
{
    if(this==&org)
        return *this;
    delete [] x;
    n=org.n;
    x=new double[n+1];
    for(int i=0; i<n+1; ++i)
        x[i]=org.x[i];
    return *this;
}
Polynom::PolynomIm Polynom::PolynomIm::operator*(const PolynomIm&ar)
{
    PolynomIm temp(n+ar.n-1);
    for(int i=n; i>=0; --i)
    {
        for(int j=ar.n; j>=0; --j)
        {
            temp.x[i+j]+=x[i]*ar.x[j];
        }
    }
    return temp;
}

Polynom::PolynomIm Polynom::PolynomIm::operator+(const PolynomIm &sum)
{
    int max;
    if( n>sum.n) max=n;
    else max=sum.n;
    PolynomIm temp(max);
    int i, j;
    if(n==sum.n)
    {
        for(i=0; i<sum.n+1; ++i)
            temp.x[i]=x[i]+sum.x[i];

    }
    if(n>sum.n)
    {
        for(i=0; i<sum.n+1; i++)
        {
            temp.x[i]=x[i]+sum.x[i];
        }
        for(j=i; j<n+1; j++)
        {
            temp.x[j]=x[j];
        }
    }
    if(n<sum.n)
    {
        for( i=0; i<n+1; i++)
        {
            temp.x[i]=x[i]+sum.x[i];
        }
        for( j=i; j<sum.n+1; j++)
        {
            temp.x[j]=sum.x[j];
        }
    }

    return temp;
}

Polynom::PolynomIm Polynom::PolynomIm::proizvodnaya (const PolynomIm &ar)
{

    PolynomIm result(n-1);
    int j=n;
    for ( int i=n-1; i>=0; --i)
    {
        result.x[i]=ar.x[j]*j;
        --j ;
    }
    return result;
}
Polynom::PolynomIm Polynom::PolynomIm::integral (const PolynomIm &ar )

{
    PolynomIm result(n+1);
    int j=n;
    for ( int i=n+1; i>=0; --i)
    {
        if(i==0)
        {
            result.x[i]=0;
        }
        else
        {
            result.x[i]=ar.x[j]/(j+1);
            --j ;
        }
    }

    return result;
}


double *Polynom::PolynomIm::get_x()const
{
    return x;
}

int  Polynom::PolynomIm::get_n()const
{
    return n;
}

