#include "vector.hpp"
#include "iterator.hpp"
#include "utils.hpp"
#include <vector>
#include <list>
#include "containers_test/srcs/base.hpp"

#define TESTED_TYPE foo<int>
#define TESTED_NAMESPACE std

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type


void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <class T>
void	printVec(ft::vector<T> v){
	for (typename ft::vector<T>::size_type i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
    std::cout << std::endl;
    std::cout << "Size : " << v.size() << ", Capacity : " << v.capacity() << std::endl;
    std::cout << std::endl;
}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

// void test_assign()
// {
//     TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 3;
// 	for (unsigned long int i = 0; i < vct_two.size(); ++i)
// 		vct_two[i] = (vct_two.size() - i) * 5;
// 	printSize(vct);
// 	printSize(vct_two);

// 	vct_three.assign(vct.begin(), vct.end());
// 	vct.assign(vct_two.begin(), vct_two.end());
// 	vct_two.assign(2, 42);
// 	vct_four.assign(4, 21);

// 	std::cout << "\t### After assign(): ###" << std::endl;

// 	printSize(vct);
// 	printSize(vct_two);
// 	printSize(vct_three);
// 	printSize(vct_four);

// 	vct_four.assign(6, 84);
// 	printSize(vct_four);

// 	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

// 	vct.assign(5, 53);
// 	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

// 	printSize(vct);
// 	printSize(vct_two);
// }

// void test_bidirect_it()
// {
//     TESTED_NAMESPACE::vector<TESTED_TYPE> lst;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator lst_it;
// 	for (int i = 1; i < 5; ++i)
// 		lst.push_back(i * 3);

// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
// 	printSize(vct);

// 	lst_it = lst.begin();
// 	for (int i = 1; lst_it != lst.end(); ++i)
// 		*lst_it++ = i * 5;
// 	vct.assign(lst.begin(), lst.end());
// 	printSize(vct);

// 	vct.insert(vct.end(), lst.rbegin(), lst.rend());
// 	printSize(vct);
// }

// void test_size()
// {
//     const int start_size = 7;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

// 	for (int i = 0; i < start_size; ++i)
// 		it[i] = (start_size - i) * 3;
// 	printSize(vct, true);

// 	vct.resize(10, 42);
// 	printSize(vct, true);

// 	vct.resize(18, 43);
// 	printSize(vct, true);
// 	vct.resize(10);
// 	printSize(vct, true);
// 	vct.resize(23, 44);
// 	printSize(vct, true);
// 	vct.resize(5);
// 	printSize(vct, true);
// 	vct.reserve(5);
// 	vct.reserve(3);
// 	printSize(vct, true);
// 	vct.resize(87);
// 	vct.resize(5);
// 	printSize(vct, true);

// 	is_empty(vct2);
// 	vct2 = vct;
// 	is_empty(vct2);
// 	vct.reserve(vct.capacity() + 1);
// 	printSize(vct, true);
// 	printSize(vct2, true);

// 	vct2.resize(0);
// 	is_empty(vct2);
// 	printSize(vct2, true);
// }

// void test_erase()
// {
//     TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = std::string((vct.size() - i), i + 65);
// 	printSize(vct);

// 	checkErase(vct, vct.erase(vct.begin() + 2));

// 	checkErase(vct, vct.erase(vct.begin()));
// 	checkErase(vct, vct.erase(vct.end() - 1));

// 	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

// 	vct.push_back("Hello");
// 	vct.push_back("Hi there");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

// 	vct.push_back("ONE");
// 	vct.push_back("TWO");
// 	vct.push_back("THREE");
// 	vct.push_back("FOUR");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.begin(), vct.end()));
// }

// void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

// 	std::cout << "Pre inc" << std::endl;
// 	it_tmp = ++it;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Pre dec" << std::endl;
// 	it_tmp = --it;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Post inc" << std::endl;
// 	it_tmp = it++;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Post dec" << std::endl;
// 	it_tmp = it--;
// 	std::cout << *it_tmp << " | " << *it << std::endl;
// 	std::cout << "###############################################" << std::endl;
// }

// void test_ite()
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

// 	for (int i = 0; i < size; ++i)
// 		it[i] = (size - i) * 5;
// 	prepost_incdec(vct);

// 	it = it + 5;
// 	it = it - 4;
// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;

// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;

// 	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
// 	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

// 	printSize(vct, true);
// }

void test_ite_arrow()
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it(vct.begin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	printSize(vct, 1);

	it = vct.begin();
	ite = vct.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

}


int main()
{
    // test_assign();
    // test_bidirect_it();
    // test_size();
    // test_erase();
    // test_ite();
    test_ite_arrow();
    return (0);
}