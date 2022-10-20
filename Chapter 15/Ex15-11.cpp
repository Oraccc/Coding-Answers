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

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double pri,
               size_t qty, double disc)
        : Quote(book, pri), min_qty(qty), discount(disc) {}

    double net_price(size_t n) const override
    {
        if (n >= min_qty)
            return n * price * (1 - discount);
        else
            return n * price;
    }

    virtual ostream &debug(ostream &os) const override
    {
        os << "Limit_quote::min_qty " << min_qty << " Limit_quote::discount " << discount;
        return os;
    }

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_quote : public Quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double pri,
                size_t qty, double disc)
        : Quote(book, pri), max_qty(qty), discount(disc) {}

    double net_price(size_t n) const override
    {
        if (n <= max_qty)
            return n * price * (1 - discount);
        else
            return (n - max_qty) * price + max_qty * price * (1 - discount);
    }

    virtual ostream &debug(ostream &os) const override
    {
        os << "Limit_quote::max_qty " << max_qty << " Limit_quote::discount " << discount;
        return os;
    }

private:
    size_t max_qty = 0;
    double discount = 0.0;
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

    // print_total(cout, basic, 20);
    // print_total(cout, bulk, 20);
    // print_total(cout, limit, 20);

    basic.debug(cout) << endl;
    bulk.debug(cout) << endl;
    limit.debug(cout) << endl;

    return 0;
}