#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Sales_data;
istream &read(istream &is, Sales_data &item);

class Sales_data
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);

public:
    Sales_data() = default;
    explicit Sales_data(const string &no) : bookNo(no) {}
    Sales_data(const string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data (istream &is)
    {
        read(is, *this);
    }

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue 
    << " " << item.avg_price();
    return os;
}


int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    if (!in)
        return -1;

    vector<Sales_data> vsd;
    for (Sales_data sd; read(in, sd); vsd.push_back(sd)) {}
    
    cout << "Before sort:\n";
    for (const auto &sd : vsd)
        print(cout, sd) << endl;

    sort(vsd.begin(), vsd.end(), 
        [](const Sales_data &sd1, const Sales_data &sd2)
        {
            return sd1.isbn() < sd2.isbn();
        });
    cout << "\nAfter sort:\n";
    for (const auto &sd : vsd)
        print(cout, sd) << endl;

    return 0;
}