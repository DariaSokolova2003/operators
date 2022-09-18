#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


class String {
private:
	char* buffer = NULL;
	unsigned int size = 0;
public:

	String() = default;
	String(const char* str)
	{
		if (str) {

			size = strlen(str);
			buffer = new char[size + 1];
			strcpy(buffer, str);

		}

	}
	String(const String& r) {
		size = r.size;
		buffer = new char[size + 1];
		strcpy(buffer, r.buffer);

	}

	~String() {
		delete[] buffer;
	}

	void Print()
	{
		cout << buffer << endl;

	}

	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;
		if (size != s.size || size == 0)
		{
			delete[] buffer;
			size = s.size;
			buffer = new char[size + 1];
		}
		strcpy(buffer, s.buffer);
		return *this;
	}
	String operator+(const String& s)
	{
		String newStr;

		newStr.size = size + s.size;
		newStr.buffer = new char[newStr.size + 1];
		strcpy(newStr.buffer, buffer);
		strcat(newStr.buffer, s.buffer);
		return newStr;
	}


	String& operator+=(const char* _str)
	{
		strcat(buffer, _str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		int newSize = size + strlen(str.buffer);
		char* tmp = new char[newSize + 1];

		strcpy(tmp, buffer);
		strcat(tmp, str.buffer);

		delete[] buffer;

		buffer = tmp;
		size = newSize;

		return *this;
	}

	/* const char* get_buffer()
	{
		return buffer;
	}
	String& operator+=( String& str)
	{
		strcat(buffer, str.get_buffer());
		return *this;
	} */
};


int main()
{
	String s1 = "Hello";
	String s2 = "world";
	s1 = s2;
	s1.Print();

	String str1 = "HELLO";
	String str2 = "WORLD";
	str1 += str2;
	str1.Print();


	String str3 = "123";
	String str4 = "456";
	String str5 = str3 + str4;
	str5.Print();

	return 0;
}
