#ifndef STRBLOBSTR_H
#define STRBLOBSTR_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

class StrBlob;

using namespace std;

class StrBlobPtr {
public:
    typedef vector<string>::size_type size_type;

    StrBlobPtr();
    explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);

    string &deref() const;
    StrBlobPtr &inc();

private:
    weak_ptr<vector<string>> wptr;
    size_type curr;

    shared_ptr<vector<string>> check(size_type pos, const string &msg) const;
};

#endif