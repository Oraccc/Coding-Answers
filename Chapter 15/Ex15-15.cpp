#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double pri)
        : bookNo(book), price(pri) {}

    virtual ~Quote() = default;

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

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
    Bulk_quote() = default;
    Bulk_quote(const string &book, double pri, size_t qty, double disc)
        : Disc_quote(book, pri, qty, disc) {}

    double net_price(size_t n) const override
    {
        if (n >= quantity)
            return n * price * (1 - discount);
        else
            return n * price;
    }
};

class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double pri, size_t qty, double disc)
        : Disc_quote(book, pri, qty, disc) {}

    double net_price(size_t n) const override
    {
        if (n <= quantity)
            return n * price * (1 - discount);
        else
            return (n - quantity) * price + quantity * price * (1 - discount);
    }
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
    Quote basic("abc", 5.5);
    Bulk_quote bulk("abc", 5.5, 10, 0.2);
    Limit_quote limit("abc", 5.5, 5, 0.2);

    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    print_total(cout, limit, 20);

    // basic.debug(cout) << endl;
    // bulk.debug(cout) << endl;
    // limit.debug(cout) << endl;

    return 0;
}