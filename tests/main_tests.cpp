#include "test_include.hpp"

void test_all()
{
	 /* Tests Vector */

	 std::cout << "Tests Vector" << std::endl;

	std::cout << std::endl << "                   New Test::assign" << std::endl;
    test_assign();
	std::cout << std::endl << "                   New Test::bidirect_it" << std::endl;
    test_bidirect_it();
	std::cout << std::endl << "                   New Test::size" << std::endl;
    test_size();
	std::cout << std::endl << "                   New Test::erase" << std::endl;
    test_erase();
	std::cout << std::endl << "                   New Test::ite" << std::endl;
    test_ite();
	std::cout << std::endl << "                   New Test::ite_ope" << std::endl;
	test_ite_eq_ope();
	std::cout << std::endl << "                   New Test::revi_ite" << std::endl;
	test_rev_it();

	/* Tests Stack */

	std::cout << "Tests Stack" << std::endl;

	// std::cout << std::endl << "                   New Test::push" << std::endl;
	// test_push();
	// std::cout << std::endl << "                   New Test::stack" << std::endl;
	// tests_stack();

	// /* Test Map */

	std::cout << "Tests Map" << std::endl;

	std::cout << std::endl << "                   New Test::map_cpy" << std::endl;
	test_map_copyconstruct();
	std::cout << std::endl << "                   New Test::map_construct" << std::endl;
	test_construct_hard();
	std::cout << std::endl << "                   New Test::map_insert" << std::endl;
	test_insert();
	std::cout << std::endl << "                   New Test::erase_map" << std::endl;
	test_erase_map();
	std::cout << std::endl << "                   New Test::ite_map" << std::endl;
	test_ite_map();
	std::cout << std::endl << "                   New Test::equalrange" << std::endl;
	test_equalrange();
}

int main()
{
	/* Tests Vector */

	//  std::cout << "Tests Vector" << std::endl;

	// std::cout << std::endl << "                   New Test::assign" << std::endl;
    // test_assign();
	// std::cout << std::endl << "                   New Test::bidirect_it" << std::endl;
    // test_bidirect_it();
	// std::cout << std::endl << "                   New Test::size" << std::endl;
    // test_size();
	// std::cout << std::endl << "                   New Test::erase" << std::endl;
    // test_erase();
	// std::cout << std::endl << "                   New Test::ite" << std::endl;
    // test_ite();
	// std::cout << std::endl << "                   New Test::ite_ope" << std::endl;
	// test_ite_eq_ope();
	// std::cout << std::endl << "                   New Test::revi_ite" << std::endl;
	// test_rev_it();

	// /* Tests Stack */

	// std::cout << "Tests Stack" << std::endl;

	// std::cout << std::endl << "                   New Test::push" << std::endl;
	// test_push();
	// std::cout << std::endl << "                   New Test::stack" << std::endl;
	// tests_stack();

	// // /* Test Map */

	// std::cout << "Tests Map" << std::endl;

	// std::cout << std::endl << "                   New Test::map_cpy" << std::endl;
	// test_map_copyconstruct();
	// std::cout << std::endl << "                   New Test::map_construct" << std::endl;
	// test_construct_hard();
	// std::cout << std::endl << "                   New Test::map_insert" << std::endl;
	// test_insert();
	// std::cout << std::endl << "                   New Test::erase_map" << std::endl;
	// test_erase_map();
	// std::cout << std::endl << "                   New Test::ite_map" << std::endl;
	// test_ite_map();
	// std::cout << std::endl << "                   New Test::equalrange" << std::endl;
	// test_equalrange();

	// print_tree();

	// test all the tests
	// test_all(); 
	return (0);
}
