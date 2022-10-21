#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() { cout << "Quote" << endl; }

    Quote(const string &book, double pri)
        : bookNo(book), price(pri)
    {
        cout << "Quote(const string &book, double pri)" << endl;
    }

    virtual ~Quote()
    {
        cout << "~Quote" << endl;
    }
    Quote(const Quote &rhs) : price(rhs.price), bookNo(rhs.bookNo)
    {
        cout << "Quote(const Quote &rhs)" << endl;
    }
    Quote(Quote &&rhs) : price(move(rhs.price)),
                         bookNo(move(rhs.bookNo))
    {
        cout << "Quote(Quote &&rhs)" << endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        cout << "operator=(const Quote &rhs)" << endl;
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        cout << "operator=(Quote &&rhs)" << endl;
        price = move(rhs.price);
        bookNo = move(rhs.bookNo);
        return *this;
    }

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
    Disc_quote()
    {
        cout << "Disc_quote" << endl;
    }
    Disc_quote(const string &book, double pri,
               size_t qty, double disc)
        : Quote(book, pri), quantity(qty), discount(disc)
    {
        cout << "Disc_quote(const string &book, ... )" << endl;
    }

    ~Disc_quote()
    {
        cout << "~Disc_quote" << endl;
    }
    Disc_quote(const Disc_quote &rhs)
        : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount)
    {
        cout << "Disc_quote(const Disc_quote &rhs)" << endl;
    }
    Disc_quote(Disc_quote &&rhs) : Quote(move(rhs)),
                                   quantity(move(rhs.quantity)),
                                   discount(move(rhs.discount))
    {
        cout << "Disc_quote(Disc_quote &&rhs)" << endl;
    }
    Disc_quote &operator=(const Disc_quote &rhs)
    {
        Quote::operator=(rhs);
        cout << "operator=(const Disc_quote &rhs)" << endl;
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }
    Disc_quote &operator=(Disc_quote &&rhs)
    {
        Quote::operator=(move(rhs));
        cout << "operator=(Disc_quote &&rhs)" << endl;
        quantity = move(rhs.quantity);
        discount = move(rhs.discount);
        return *this;
    }

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
    Limit_quote limit0;
    limit0.debug(cout) << '\n' << endl;

    Limit_quote limit1("abc", 5.5, 5, 0.1);
    limit1.debug(cout) << '\n' << endl;

    Limit_quote limit2(limit1);
    limit2.debug(cout) << '\n' << endl;

    Limit_quote limit3(move(limit2));
    limit3.debug(cout) << endl;
    limit2.debug(cout) << '\n' << endl;

    limit2 = limit3;
    limit2.debug(cout) << '\n' << endl;

    limit3 = move(limit1);
    limit3.debug(cout) << endl;
    limit1.debug(cout) << '\n' << endl;

    return 0;
}