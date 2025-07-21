#include "Array.hpp"

int main() 
{
    int * a = new int();
    std::cout << "Test subject: " << *a << std::endl;

    try 
    {
        // Test access const
        const Array<int> const_arr(5);
        std::cout << "Access const test: " << const_arr[3] << std::endl;
        std::cout << "Array size: " << const_arr.size() << std::endl;

        std::cout << "Exception test: ";
        std::cout << const_arr[10] << std::endl; // throw an exception
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try 
    {
        // Test affectation
        Array<int> arr(5);
        Array<int> arr_test;

        arr[0] = 42;
        arr_test = arr;
        std::cout << "Affectation test: " << arr_test[0] << std::endl;
        std::cout << "Array size: " << arr_test.size() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}