
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>

// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
	m_data = new  char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	delete[] m_data;
}

size_t sfw::string::length() const
{
	return strlen(m_data);
}





sfw::string::string(size_t size)
{
	m_data = new char[m_size = size + 1];
	m_data[m_size - 1] = '\0';
}

sfw::string::string(const char * a, size_t size)
{
	m_data = new char[m_size = size];
	strncpy_s(m_data,m_size, a, size - 1);
}

sfw::string::string(const char * a)
{
	if (a != nullptr)
	{
		m_data = new char[m_size = strlen(a) + 1];
		strcpy_s(m_data, m_size, a);
	}
	else
	{
		m_data = new  char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(const string & a)
{
	m_size = a.m_size;
	m_data = new char[m_size];
	strncpy_s(m_data, m_size, a.m_data, a.m_size - 1);
}

// move assignment
sfw::string::string(string && a)
{
	// TODO:
	if (m_data != nullptr)
	{
		delete[]m_data;
	}
	m_size = a.m_size;
	m_data = a.m_data;

	a.m_size = 1;
	a.m_data = new char[a.m_size];
	a.m_data[0] = '\0';
}

sfw::string & sfw::string::operator=(const string & a)
{
	if (this != &a)
	{
		char *h = new char[a.m_size];
		strcpy_s(h, a.m_size, a.cstring);
	}
		return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	
	return *this;
}

sfw::string & sfw::string::operator=(const char * a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const string & a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(const char * a)
{
	// TODO:
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	// TODO:
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	// TODO: Is this finished?
	return this->m_data[0];
}

const char & sfw::string::operator[](size_t index) const
{
	// TODO: Is this finished?
	return this->m_data[0];
}




size_t sfw::string::size() const
{
	// TODO:

	return size_t(m_size - 1);
}

void sfw::string::resize(size_t size)
{
	if (size < 1) { size = 1; }
	char *h = new char[size];
	strcpy_s(h, size, m_data);
	delete[] m_data;
	m_data = h;
	m_data[size - 1] = '/0';
}

void sfw::string::clear()
{
	m_data[0] = '/0';
}

bool sfw::string::empty() const
{
	if (m_data[0] = '/0') return true;
	else return false;
}

const char * sfw::string::cstring() const
{
	return m_data;
}

bool sfw::operator<(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) < 0) return true;
	else return false;
}

bool sfw::operator<(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) < 0) return true;
	else return false;
}

bool sfw::operator<(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) < 0) return true;
	else return false;
}

bool sfw::operator<=(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) <= 0) return true;
	else return false;
}

bool sfw::operator<=(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) <= 0) return true;
	else return false;
}

bool sfw::operator<=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) <= 0) return true;
	else return false;
}

bool sfw::operator>(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) > 0) return true;
	else return false;
}

bool sfw::operator>(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) > 0) return true;
	else return false;
}

bool sfw::operator>(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) > 0) return true;
	else return false;
}

bool sfw::operator>=(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) >= 0) return true;
	else return false;
}

bool sfw::operator>=(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) >= 0) return true;
	else return false;
}

bool sfw::operator>=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) >= 0) return true;
	else return false;
}

bool sfw::operator!=(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) != 0) return true;
	else return false;
}

bool sfw::operator!=(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) != 0) return true;
	else return false;
}

bool sfw::operator!=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) != 0) return true;
	else return false;
}

bool sfw::operator==(const string & a, const string & b)
{
	if (strcmp(a.cstring, b.cstring) == 0) return true;
	else return false;
}

bool sfw::operator==(const string & a, const char * b)
{
	if (strcmp(a.cstring, b) == 0) return true;
	else return false;
}

bool sfw::operator==(const char * a, const string & b)
{
	if (strcmp(a, b.cstring) == 0) return true;
	else return false;
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	
	return string();
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, char b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(char a, const string & b)
{
	// TODO:
	return string();
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	// TODO:
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p)
{
	// TODO:
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	// TODO:
	return string(a, len + 1);
}
