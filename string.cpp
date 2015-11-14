/********************************************************************************************************
** Function Name:           String Class
** Descriptions:                To achieve the string by class,and its operations,including Addition,
**                                     Equivalent and Addition and Equivalent.
**
** Created By:                 WangXiaoming
** Created Date:             2015-11-11 PM
*********************************************************************************************************/
#include<iostream>
using namespace std;

class String
{
private:
	char *data;
	size_t length;
public:
	String();
	String(const char *str);
	String(const String &str);
	~String();

	String operator+(const String &str) const;
	String& operator=(const String &str);
	String& operator+=(const String &str);

	size_t size() const;
	const char* c_str() const;

	friend istream& operator>>(istream &os, String &str);
	friend ostream& operator<<(ostream &os, String &str);
};

String::String()
{
	length = 0;
	data = new char[1];
	*data = '\0';
}

String::String(const char *str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}

String::String(const String &str)
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}

String::~String()
{
	delete[] data;
	length = 0;
}

String String::operator+(const String &str) const
{
	String newstring;
	newstring.length = length + str.size();
	newstring.data = new char[newstring.length + 1];
	strcpy(newstring.data, data);
	strcat(newstring.data, str.data);
	return newstring;
}

String& String::operator=(const String &str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[] data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

String& String::operator+=(const String &str)
{
	length += str.length;
	char *newData = new char[length + 1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[] data;
	data = newData;
	return *this;
}

inline size_t String::size() const
{
	return length;
}

inline const char* String::c_str() const
{
	return data;
}

istream& operator>>(istream &os, String &str)
{
	os >> str.data;
	return os;
}

ostream& operator<<(ostream &out, String &str)
{
	out << str.data;
	return out;
}

int main()
{
	String a("abc");
	String b("efgh");
	cout << a << endl;
	cout << b << endl;
	cout << a.size() << endl;
	cout << b.size() << endl;
	cout << a + b << endl;
	cout << (a += b) << endl;
	/*
	String a;
	cin >> a;
	cout << a << endl;
	*/
}