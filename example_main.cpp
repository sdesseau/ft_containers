#include "vector.hpp"
#include "iterator.hpp"
#include "utils.hpp"
#include <vector>


 #define VECTYPE std::string

template <class T>
void	printVec(ft::vector<T> v){
	for (typename ft::vector<T>::size_type i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
    std::cout << std::endl;
    std::cout << "Size : " << v.size() << ", Capacity : " << v.capacity() << std::endl;
    std::cout << std::endl;
}

int main()
{
//     std::vector<int> test(5, 42);
//     std::vector<int>::iterator beg = test.begin();
//     // std::vector<int>::iterator end = test.end();
//     for (std::vector<int>::iterator j = test.begin(); j < test.end(); *j++)
//         std::cout << *j << std::endl;
// std::cout <<std::endl<<std::endl;
// // beg--;
//     test.insert(beg, 1);
//     for (std::vector<int>::iterator j = test.begin(); j < test.end(); *j++)
//         std::cout << *j << std::endl;

    // ft::vector<int>test(5, 42);
    // ft::vector<int>::iterator beg = test.begin();
    // try
    // {
    //     test.insert(beg + 1, 12);
    // }
    // catch(std::exception &e)
    // {std::cout << "rentre";}
    // ft::vector<int>::iterator end = test.end();
    // beg = test.begin();
    // ft::vector<int>v(3, 0);
    // v.insert(v.end(), beg, end);
    // for (ft::vector<int>::iterator j = v.begin(); j != v.end(); j++)
    //     std::cout << *j << " ";
    // std::cout << std::endl;
    

    // ft::vector<VECTYPE> v1;
	// ft::vector<VECTYPE> v2(4, 98);
	// v1 = v2;
	// ft::vector<VECTYPE> v3(v1.begin(),v1.end());
	// ft::vector<VECTYPE> v4(v3);
	// printVec(v4);

    // v4[1] = 65 + 1;
	// v4.at(2) = 65 + 2;
	// v4.front() = 65 + 0;
	// v4.back() = 65 + 3;
	// printVec(v4);

    // v4.resize(2);
    // printVec(v4);
    // v4.reserve(20);
    // printVec(v4);

	// v4.push_back(72);
	// v4.push_back(72);
	// v4.push_back(72);
	// v4.push_back(72);
    // printVec(v4);

    // ft::vector<VECTYPE> v1;
	// ft::vector<VECTYPE> v2(4, "caca");
	// v1 = v2;
	// ft::vector<VECTYPE> v3(v1.begin(),v1.end());
	// ft::vector<VECTYPE> v4(v3);
	// printVec(v4);

    // v4[1] = "65 + 1";
	// v4.at(2) = "65 + 2";
	// v4.front() = "65 + 0";
	// v4.back() = "65 + 3";
	// printVec(v4);

    // v4.resize(2);
    // printVec(v4);
    // v4.reserve(200);
    // printVec(v4);

	// v4.push_back("72");
	// v4.push_back("72");
	// v4.push_back("72");
	// v4.push_back("72");
    // printVec(v4);

    // v4.pop_back();
	// v4.pop_back();
    // // printVec(v4);

	// v4.clear();
    // // printVec(v4);

}