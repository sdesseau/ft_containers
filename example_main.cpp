#include "vector.hpp"
#include "iterator.hpp"

int main()
{
    ft::vector<std::string>v(12, "cacca");
    ft::vector<std::string>::iterator i(v.begin());
    std::cout << *i << std::endl;
    ft::vector<std::string>::iterator j(i);
    std::cout << *j << std::endl;
    ft::vector<std::string>::iterator k = i;
    std::cout << *k << std::endl;
    // while(v.size())
    //     v.pop_back();
    // i = v.begin();
    for (ft::vector<std::string>::iterator j = v.begin(); j < v.end(); *j++)
        std::cout << *j << std::endl;
}
