
#include "test_include.hpp"

int main()
{
	 /* Tests Vector */

	std::cout << std::endl << "                   New Test" << std::endl;
    test_assign();
	std::cout << std::endl << "                   New Test" << std::endl;
    test_bidirect_it();
	std::cout << std::endl << "                   New Test" << std::endl;
    test_size();
	std::cout << std::endl << "                   New Test" << std::endl;
    test_erase();
	std::cout << std::endl << "                   New Test" << std::endl;
    test_ite();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_ite_eq_ope();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_rev_it();

	/* Tests Stack */


	// /* Test Map */

	std::cout << std::endl << "                   New Test" << std::endl;
	test_map_copyconstruct();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_construct_hard();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_insert();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_erase_map();
	std::cout << std::endl << "                   New Test" << std::endl;
	test_ite_map();
}
