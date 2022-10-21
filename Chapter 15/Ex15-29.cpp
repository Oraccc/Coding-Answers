#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double pri) : bookNo(book), price(pri) {}

    virtual ~Quote() = default;
    Quote(const Quote &) = default;
    Quote(Quote &&) = default;
    Quote &operator=(const Quote &) = default;
    Quote &operator=(Quote &&) = default;

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(move(*this)); }

    virtual ostream &debug(ostream &os) const
    {
        os << "Quote::bookNo " << bookNo << " Quote::price " << price;
        return os;
    }

protected:
    double price = 0.0;

private:
    string bookNo;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double pri,
               size_t qty, double disc)
        : Quote(book, pri), quantity(qty), discount(disc) {}

    virtual ~Disc_quote() = default;
    Disc_quote(const Disc_quote &) = default;
    Disc_quote(Disc_quote &&) = default;
    Disc_quote &operator=(const Disc_quote &) = default;
    Disc_quote &operator=(Disc_quote &&) = default;

    double net_price(size_t n) const = 0;

    ostream &debug(ostream &os) const override
    {
        Quote::debug(os) << " Disc_quote::quantity " << quantity
                         << " Disc_quote::discount " << discount;
        return os;
    }

protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;

    double net_price(size_t n) const override
    {
        if (n >= quantity)
            return n * price * (1 - discount);
        else
            return n * price;
    }
    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() && override { return new Bulk_quote(move(*this)); }
};

class Limit_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;

    double net_price(size_t n) const override
    {
        if (n <= quantity)
            return n * price * (1 - discount);
        else
            return (n - quantity) * price + quantity * price * (1 - discount);
    }
    Limit_quote *clone() const & override { return new Limit_quote(*this); }
    Limit_quote *clone() && override { return new Limit_quote(move(*this)); }
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
       << endl;
    return ret;
}

int main()
{
    vector<shared_ptr<Quote>> v;
    v.push_back(make_shared<Quote>("abc", 5.5));
    v.push_back(make_shared<Bulk_quote>("abc", 5.5, 10, 0.2));
    v.push_back(make_shared<Limit_quote>("abc", 5.5, 10, 0.2));

    for (const auto &q : v)
        print_total(cout, *q, 20);

    return 0;
}