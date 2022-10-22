#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrVec
{
public:
    typedef size_t size_type;
    StrVec() : first_elem(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);

    StrVec(const StrVec &);
    ~StrVec();
    StrVec &operator=(const StrVec &);

    void push_back(const string &s);
    void pop_back();

    void reserve(size_type);
    void resize(size_type, const string & = string());

    bool empty() const { return cbegin() == cend(); }
    size_type size() const { return first_free - first_elem; }
    size_type capacity() const { return cap - first_elem; }

    string *begin() { return first_elem; }
    string *end() { return first_free; }
    const string *begin() const { return first_elem; }
    const string *end() const { return first_free; }
    const string *cbegin() const { return begin(); }
    const string *cend() const { return end(); }

private:
    static allocator<string> alloc;

    string *first_elem;
    string *first_free;
    string *cap;

    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    pair<string *, string *>
    alloc_n_copy(const string *, const string *);
    void reallocate();
    void free();
};

#endif