#include "vector.hpp"

int main()
{
    ft::vector<int> test(3, 12);

    std::cout << test.empty() << std::endl;
    std::cout << test.size() << std::endl;
    std::cout << test.capacity() << std::endl << std::endl;  
    

    ft::vector<int> test2;

    test2.swap(test);
    std::cout << test2[0] << " , " << test2[1] << " , " << test2[2] << std::endl;
    std::cout << test2.empty() << std::endl;
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl<< std::endl;

    try {
    test2.pop_back();
    test2.pop_back();
    test2.pop_back();
    }
    catch (std::exception) { std::cout << "exception" << std::endl; }
    std::cout << test2.empty() << std::endl;
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl << std::endl;

    try {
        test2.resize(10, 42);
    }
    catch (std::exception) { std::cout << "exception" << std::endl; }
    std::cout << test2[7] << std::endl;
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl << std::endl;

    ft::vector<int> copie(test2);
    std::cout << copie[7] << std::endl;
    std::cout << copie.size() << std::endl;
    std::cout << copie.capacity() << std::endl << std::endl;

    test2.clear();
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl << std::endl;

    test2.assign(10, 1212);
    std::cout << test2[7] << std::endl;
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl << std::endl;

    test2.resize(3);
    std::cout << test2.size() << std::endl;
    std::cout << test2.capacity() << std::endl << std::endl;
    return (0);
}
