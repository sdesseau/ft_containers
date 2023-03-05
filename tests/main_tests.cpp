#include "test_include.hpp"

int main()
{
	 /* Tests Vector */

	// std::cout << std::endl << "                   New Test" << std::endl;
    // test_assign();
	// std::cout << std::endl << "                   New Test" << std::endl;
    // test_bidirect_it();
	// std::cout << std::endl << "                   New Test" << std::endl;
    // test_size();
	// std::cout << std::endl << "                   New Test" << std::endl;
    // test_erase();
	// std::cout << std::endl << "                   New Test" << std::endl;
    // test_ite();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_ite_eq_ope();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_rev_it();

	// /* Tests Stack */

	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_push();

	// // /* Test Map */

	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_map_copyconstruct();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_construct_hard();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_insert();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_erase_map();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_ite_map();
	// std::cout << std::endl << "                   New Test" << std::endl;
	// test_equalrange();

	TESTED_NAMESPACE::vector<char> v3;
	TESTED_NAMESPACE::vector<char> v4;
	v4.clear();
	v3.clear();
	std::cout << v3.empty() << std::endl;
	for (TESTED_NAMESPACE::vector<char>::size_type i = 0; i < 7; i++){
		v4.insert(v4.begin() + i, 'a' + i);
	printVec(v4);
		v3.insert(v3.begin() + i, 'A' + i);
	}
	v3.insert(v3.begin()+3, 2, 'X');
	v3.insert(v3.begin()+4, v4.begin(), v4.end());
	printVec(v3);
	printVec(v4);
	v3.swap(v4);
	printVec(v3);
	printVec(v4);

}
