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

	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

	// std::cout << "len: " << (ite - it) << std::endl;
	// for (; it != ite; ++it)
	// 	*it = (ite - it);

	// it = vct.begin();
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
	// for (int i = 0; it != ite; ++it)
	// 	*it = ++i * 5;

	// it = vct.begin();
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
	// for (int i = 0; it != ite; ++it)
	// 	*it = ++i * 7;
	// vct_copy.push_back(42);
	// vct_copy.push_back(21);

	// std::cout << "\t-- PART ONE --" << std::endl;
	// printSize(vct);
	// printSize(vct_range);
	// printSize(vct_copy);

	// vct = vct_copy;
	// vct_copy = vct_range;
	// vct_range.clear();

	// std::cout << "\t-- PART TWO --" << std::endl;
	// printSize(vct);
	// printSize(vct_range);
	// printVec(vct_copy);
	// printSize(vct_copy);

	TESTED_NAMESPACE::map<int, int> mymap;

	TESTED_NAMESPACE::map<int, int>::iterator ite;

	// insert 1000000 random numbers:
	for (int i = 0; i < 1000000; ++i)
		mymap.insert(TESTED_NAMESPACE::make_pair(i, i * 2));
	
	// show content:
	// for (ite = mymap.begin(); ite != mymap.end(); ++ite)
	// 	std::cout << ite->first << " => " << ite->second << '\n';

	// TEST ALL STACK FUNCTIONS
	TESTED_NAMESPACE::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);
	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	// continue with empty, size, top, push, pop, operator =, operator ==, operator !=, operator <, operator <=, operator >, operator >=, copy constructor and destructor 
	mystack.push(42);
	mystack.push(21);
	mystack.push(84);
	mystack.push(42);
	mystack.push(21);
	mystack.push(84);
	printf("size: %lu\n", mystack.size());
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	mystack.pop();
	printf("top: %d\n", mystack.top());
	printf("empty: %d\n", mystack.empty());
	// show all operators
	TESTED_NAMESPACE::stack<int> mystack2;
	mystack2.push(42);
	mystack2.push(21);
	mystack2.push(84);
	mystack2.push(42);
	mystack2.push(21);
	// test operator ==
	printf("operator ==: %d\n", mystack == mystack2);
	// test operator !=
	printf("operator !=: %d\n", mystack != mystack2);
	// test operator <
	printf("operator <: %d\n", mystack < mystack2);
	// test operator <=

	// test operator >
	printf("operator >: %d\n", mystack > mystack2);
	// test operator >=
	printf("operator >=: %d\n", mystack >= mystack2);
	// test copy constructor
	TESTED_NAMESPACE::stack<int> mystack3(mystack);
	printf("size: %lu\n", mystack3.size());
	printf("top: %d\n", mystack3.top());
	mystack3.pop();
	printf("top: %d\n", mystack3.top());
	mystack3.pop();
	printf("top: %d\n", mystack3.top());
	mystack3.pop();
	// printf("top: %d\n", mystack3.top());

	// // test operator =
	// mystack3 = mystack2;
	// printf("size: %lu\n", mystack3.size());
	// printf("top: %d\n", mystack3.top());
	// mystack3.pop();
	// printf("top: %d\n", mystack3.top());
	// mystack3.pop();
	// printf("top: %d\n", mystack3.top());
	// mystack3.pop();

	// test destructor
	mystack3.~stack();
	printf("size: %lu\n", mystack3.size());
	printf("top: %d\n", mystack3.top());
	mystack3.pop();
	printf("top: %d\n", mystack3.top());
	mystack3.pop();

	
	return 0;

}
