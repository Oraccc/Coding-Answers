#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

class Sales_data;

class Sales_data 
{
friend Sales_data operator+(const Sales_data &, const Sales_data &);
friend istream &operator>>(istream &, Sales_data &);
friend ostream &operator<<(ostream &, const Sales_data &);

public:
    Sales_data() : Sales_data("", 0, 0.0) {}
    explicit Sales_data(const string &no) : Sales_data(no, 0, 0.0) {}
    Sales_data(const string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data(istream &is) : Sales_data() { is >> *this; }

    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator=(const string &);

    string isbn() const { return bookNo; }

private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data operator+(const Sales_data &, const Sales_data &);
istream &operator>>(istream &, Sales_data &);
ostream &operator<<(ostream &, const Sales_data &);


inline double Sales_data::avg_price() const 
{
    return units_sold ? revenue / units_sold : 0;
}


bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) 
{
    return sd1.isbn() < sd2.isbn();
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) 
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) 
{
    Sales_data sum = lhs;  
    sum += rhs;
    return sum;
}

istream &operator>>(istream &is, Sales_data &item) 
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &item) 
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data &Sales_data::operator=(const string &s)
{
    bookNo = s;
    return *this;
}

int main(int argc, char **argv) 
{

    // ifstream in(argv[1]);
    // if (!in) 
    // {
    //     cerr << "Fail to open file: " << argv[1] << endl;
    //     return -1;
    // }
    // vector<Sales_data> vsd;
    // for (Sales_data sd; in >> sd; vsd.push_back(sd)) {}

    // sort(vsd.begin(), vsd.end(), compareIsbn);

    // for (const auto &sd : vsd)
    //     cout << sd << endl;
    // return 0;

    Sales_data s1;
    s1 = "booook";
    cout << s1 << endl;
}