#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, trans;

    std::cout << "Enter Transactions: " << std::endl;

    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
            
        }
        
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No Data?!" << std::endl;
        return -1;
    }
    return 0;
}