#include "Array.hpp"

int main() 
{
    try 
    {
        // Test access const
        const Array<int> const_arr(5);
        std::cout << "Access const test: " << const_arr[3] << std::endl;

        const_arr[10];  // throw an exception
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test affectation
    Array<int> arr(5);
    arr[0] = 42;
    Array<int> arr_test(3);
    arr_test = arr;
    std::cout << "Affectation test: " << arr_test[0] << std::endl;

    return 0;
}