#include "Array.hpp"

int main() 
{
    try 
    {
        // Test access const
        const Array<int> const_arr(5);
        std::cout << const_arr[3] << std::endl;
        // throw an exception
        const_arr[10];
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test affectation
    Array<int> arr(5);
    arr = arr;
    return 0;
}