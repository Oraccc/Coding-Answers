#include <iostream>

int main()
{
    std::cout << "Please Input Two Numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    int val = v1;
    // std::cout << v2 << std::endl;
    while (v1 <= val & val <= v2) {
        std::cout << val << std::endl;
        ++val;
    }

    return 0;
}