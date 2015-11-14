/*********************************************************************************************************
** Function Name:           Complex Class
** Descriptions:                To achieve a complex number by class,and its four operations,including Addition,
**                                     Subtraction,Multiplicative and  Division.
**
** Created By:                 WangXiaoming
** Created Date:             2015-11-10,PM
*********************************************************************************************************/
#include<iostream>
using namespace std;

class Complex
{
private:
	double Re;
	double Im;
public:
	Complex(double r = 0, double i = 0)
	{
		Re = r;
		Im = i;
	}
	Complex &operator=(Complex &c)
	{
		Re = c.Re;
		Im = c.Im;
		return *this;
	}
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex operator/(Complex &c1, Complex &c2);

	friend istream& operator>> (istream& input, Complex& c);
	friend ostream& operator<< (ostream& output, Complex& c);
};

Complex operator+(Complex &c1, Complex &c2)
{
	Complex c;
	c.Re = c1.Re + c2.Re;
	c.Im = c1.Im + c2.Im;
	return c;
}

Complex operator-(Complex &c1, Complex &c2)
{
	Complex c;
	c.Re = c1.Re - c2.Re;
	c.Im = c1.Im - c2.Im;
	return c;
}

Complex operator*(Complex &c1, Complex &c2)
{
	Complex c;
	c.Re = c1.Re*c2.Re - c1.Im*c2.Im;
	c.Im = c1.Im*c2.Re + c1.Re*c2.Im;
	return c;
}

Complex operator/(Complex &c1, Complex &c2)
{
	Complex c;
	c.Re = (c1.Re*c2.Re + c1.Im*c2.Im) / (c2.Re*c2.Re + c2.Im*c2.Im);
	c.Im = (c1.Im*c2.Re - c1.Re*c2.Im) / (c2.Re*c2.Re + c2.Im*c2.Im);
	return c;
}

istream& operator>> (istream& input, Complex& c)
{
	input >> c.Re;
	input >> c.Im;
	return input;
}

ostream &operator << (ostream& output, Complex &c)
{
	output << c.Re;
	if (c.Im >= 0)
		output << "+";
	output << c.Im << "i";
	return output;
}

int main()                                                                                          
{
	Complex a(2, 3);
	Complex b(3, 4);
	cout << "a=" << a << endl;
	cout << "a=" << b << endl;
	cout << "a+b=" << a + b << endl;
	cout << "a-b=" << a - b << endl;
	cout << "a*b=" << a * b << endl;
	cout << "a/b=" << a / b << endl;
	
	Complex c;
	cin >> c;
	cout << c << endl;
}