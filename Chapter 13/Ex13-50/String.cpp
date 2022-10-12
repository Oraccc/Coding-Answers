#include <iostream>
#include "String.h"

using namespace std;

allocator<char> String::alloc;

String::String(const_iterator ci) : String() 
{
    cout << "String::String(const_iterator ci)" << endl;
    while (ci && *ci != '\0')
        push_back(*ci++);
}

String::String(initializer_list<char> il) : String() 
{
    for (const auto &c : il)
        push_back(c);
}

void String::push_back(const_reference c) 
{
    if (size() == capacity())
        reallocate(empty() ? 1 : 2 * capacity());
    alloc.construct(first_free++, c);
}

void String::pop_back() 
{
    if (!empty())
        alloc.destroy(--first_free);
}

void String::reserve(size_type n) 
{
    if (n > capacity())
        reallocate(n);
}

void String::resize(size_type n, const_reference c) 
{
    if (n > size()) 
    {
        for (int i = n - size(); i > 0; --i)
        push_back(c);
    } 
    else if (n < size()) 
    {
        for (int i = size() - n; i > 0; --i)
        pop_back();
    }
}

void String::reallocate(size_type n) 
{
    auto new_first_elem = alloc.allocate(n);
    auto new_first_free = new_first_elem;
    for (auto it = begin(); it != end(); ++it)
        alloc.construct(new_first_free++, std::move(*it));
    free();
    first_elem = new_first_elem;
    first_free = new_first_free;
    cap = first_elem + n;
}

void String::free() 
{
    while (!empty())
        alloc.destroy(--first_free);
    alloc.deallocate(first_elem, capacity());
    first_elem = first_free = cap = nullptr;
}

String::~String() 
{
    free();
}

String::String(const String &rhs) 
{
    cout << "String::String(const String &rhs)" << endl;
    first_elem = alloc.allocate(rhs.size());
    first_free = cap = uninitialized_copy(rhs.begin(), rhs.end(),
                                                first_elem);
}

String &String::operator=(const String &rhs) 
{
    cout << "String &String::operator=(const String &rhs)" << endl;
    auto new_first_elem = alloc.allocate(rhs.size());
    auto new_first_free = uninitialized_copy(rhs.begin(), rhs.end(),
                                                    new_first_elem);
    free();
    first_elem = new_first_elem;
    first_free = cap = new_first_free;
    return *this;
}

String::String(String &&rhs) noexcept
    : first_elem(rhs.first_elem), first_free(rhs.first_free), cap(rhs.cap) 
{
    cout << "String::String(String &&rhs)" << endl;
    rhs.first_elem = rhs.first_free = rhs.cap = nullptr;
}

String &String::operator=(String &&rhs) noexcept 
{
    cout << "String &String::operator=(String &&rhs)" << endl;
    if (this != &rhs) 
    {
        free();
        first_elem = rhs.first_elem;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.first_elem = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

String &String::operator=(const_iterator ci) 
{
    cout << "String &String::operator=(const_iterator ci)" << endl;
    *this = String(ci);
    return *this;
}

string String::str() const 
{
    return string(cbegin(), cend());
}