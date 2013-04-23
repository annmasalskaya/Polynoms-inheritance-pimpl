#include "func.h"
#include <iostream>
using namespace std;
class NewPolynom: public Polynom
{
public:

    NewPolynom(int a);
    ~ NewPolynom();
    NewPolynom(const NewPolynom &org);
    NewPolynom & operator=(const NewPolynom &org);
    NewPolynom operator+(const NewPolynom &sum);
    NewPolynom operator*(const NewPolynom &ar);
    NewPolynom proizvodnaya (const NewPolynom &ar);
    NewPolynom integral (const NewPolynom &ar);

    friend ostream& operator<<(ostream &out ,const NewPolynom &a);
    friend istream& operator>>(istream& in,NewPolynom &a);

private:
    NewPolynom(const Polynom &org);

};

NewPolynom::NewPolynom(int a):
    Polynom(a)
{

}
NewPolynom::NewPolynom(const NewPolynom &org):
    Polynom(org)
{

}
NewPolynom::NewPolynom(const Polynom &org):
    Polynom(org)
{

}

NewPolynom &NewPolynom::operator=(const NewPolynom &org)
{
    Polynom::operator=(org);
    return *this;
}

NewPolynom NewPolynom::integral(const NewPolynom &ar )
{

    return NewPolynom(Polynom::integral(ar));
}

NewPolynom NewPolynom::proizvodnaya(const NewPolynom &ar )
{

    return NewPolynom(Polynom::proizvodnaya(ar));
}

NewPolynom NewPolynom::operator+(const NewPolynom &sum )
{
    Polynom::operator+(sum);
    return NewPolynom(Polynom::operator+(sum));
}

NewPolynom NewPolynom::operator*(const NewPolynom &ar )
{
    Polynom::operator*(ar);
    return NewPolynom(Polynom::operator*(ar));
}

NewPolynom::~NewPolynom()
{

}

istream& operator>>(istream& in,NewPolynom &a)
{
    int n=a.get_n();
    double *x=a.get_x();
    for ( int i=n-1; i>=0; --i)
    {
        cout << "x^" << i << ":";
        in >>x[i];
    }
    return in;
}
ostream& operator<<(ostream &out ,const NewPolynom &a)
{
    double *x=a.get_x();
    for ( int i =a.get_n()-1; i >= 0; i-- )
    {
        out << x[i];
        if (i!=0) cout << "*x^" << i <<" + ";
    }
    return out;
}

int main()

{
    cout<<"Введите степень первого многочлена : "<<endl;
    int first;
    cin>>first;
    NewPolynom a(first+1);
    cout<<"#1 Введите коэффициенты при 'x' первого многочлена "<<endl;
    cin>>a;
    cout<<a;
    cout<<endl<<endl;
    cout<<"Введите степень второго многочлена : "<<endl;
    int second;
    cin>>second;
    NewPolynom b(second+1);
    cout<<"#2 Введите коэффициенты при 'x' второго многочлена"<<endl;
    cin>>b;
    cout<<b;
    cout<<endl<<endl;
    cout<<"Сумма 2-х полиномов"<<endl;
    cout<<a+b<<endl<<endl;
    cout<<"Произведение 2-х полиномов"<<endl;
    cout<<a*b<<endl<<endl;
    NewPolynom c=a.proizvodnaya(a);
    cout<<"Производная от первого полинома "<<endl;
    cout<<c<<endl<<endl;
    NewPolynom d=a.integral(a);
    cout<<"Интеграл от первого полинома "<<endl;
    cout<<d<<",где 0=const"<<endl<<endl<<endl;

    return 0;
}








