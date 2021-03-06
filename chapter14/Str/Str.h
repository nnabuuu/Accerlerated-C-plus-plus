#ifndef Str_H
#define Str_H
#include "Vec.h"
#include "Ptr.h"
#include <cstring>
#include <iostream>
template<> Vec<char>* clone(const Vec<char>*);
class Str
{
    friend std::istream& operator>>(std::istream&,Str&);

public:
    typedef Vec<char>::size_type size_type;
    typedef char* iterator;
    typedef const char* const_iterator;

    Str():data(new Vec<char>) {}
    Str(const char* cp):data(new Vec<char>)
    {
        std::copy(cp,cp+std::strlen(cp),std::back_inserter(*data));
    }
    Str(size_type n,char c):data(new Vec<char>(n,c)) {}
    template<class In>
    Str(In i,In j):data(new Vec<char>)
    {
        std::copy(i,j,std::back_inserter(*data));
    }

    Str& operator+=(const Str& s)
    {
        data.make_unique();
        std::copy(s.data->begin(),s.data->end(),std::back_inserter(*data));
        return *this;
    }
    char& operator[] (size_type i)
    {
        data.make_unique();
        return (*data)[i];
    }
    const char& operator[] (size_type i) const { return (*data)[i]; }
    size_type size() const { return data->size(); }

    iterator begin() { return data->begin(); }
    const_iterator begin() const { return data->begin(); }
    iterator end() { return data->end(); }
    const_iterator end() const { return data->end(); }

public:
    Ptr<Vec<char> > data;
};

std::ostream& operator<< (std::ostream& os,const Str& s);
Str operator+ (const Str& x,const Str& y);
std::istream& getline(std::istream&is, Str& s);

bool operator<(const Str& lhs, const Str& rhs);
bool operator>(const Str& lhs, const Str& rhs);
bool operator<=(const Str& lhs, const Str& rhs);
bool operator>=(const Str& lhs, const Str& rhs);
bool operator==(const Str& lhs, const Str& rhs);
bool operator!=(const Str& lhs, const Str& rhs);
#endif // Str_H
