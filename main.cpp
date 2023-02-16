#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
	// #include <map.hpp>
	#include "stack.hpp"
	#include "vector.hpp"
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

 #define VECTYPE int

template <class T>
	void	printVec(ft::vector<T> v)
	{
		for (typename ft::vector<T>::size_type i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Size : " << v.size() << ", Capacity : " << v.capacity() << std::endl;
		std::cout << std::endl;
	}


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	ft::vector<int> iterable_vector;
	for (int letter = 0; letter <= 25; letter++)
		iterable_vector.push_back(letter);
	for (ft::vector<int>::reverse_iterator it = iterable_vector.rbegin(); it != iterable_vector.rend(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;			

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl << std::endl;



	ft::vector<int> test(5, 42);
    ft::vector<int>::iterator beg = test.begin();
    // ft::vector<int>::iterator end = test.end();
    for (ft::vector<int>::iterator j = test.begin(); j < test.end(); *j++)
        std::cout << *j << std::endl;
std::cout <<std::endl<<std::endl;
// beg--;
    test.insert(beg, 1);
    for (ft::vector<int>::iterator j = test.begin(); j < test.end(); *j++)
        std::cout << *j << std::endl;

    ft::vector<int>test2(5, 42);
    ft::vector<int>::iterator beg2 = test2.begin();

    try
    {
        test2.insert(beg2 + 1, 12);
    }
    catch(std::exception &e)
    {std::cout << "rentre";}
    
	ft::vector<int>::iterator end = test2.end();
    beg2 = test2.begin();
    ft::vector<int>v(3, 0);
    v.insert(v.end(), beg2, end);
    for (ft::vector<int>::iterator j = v.begin(); j != v.end(); j++)
        std::cout << *j << " ";
    std::cout << std::endl;
    

    ft::vector<VECTYPE> v1;
	ft::vector<VECTYPE> v2(4, 98);
	v1 = v2;
	ft::vector<VECTYPE> v3(v1.begin(),v1.end());
	ft::vector<VECTYPE> v4(v3);
	printVec(v4);

    v4[1] = 65 + 1;
	v4.at(2) = 65 + 2;
	v4.front() = 65 + 0;
	v4.back() = 65 + 3;
	printVec(v4);

    v4.resize(2);
    printVec(v4);
    v4.reserve(20);
    printVec(v4);

	v4.push_back(72);
	v4.push_back(72);
	v4.push_back(72);
	v4.push_back(72);
    printVec(v4);

	v4.empty();
	printVec(v4);

	v4
	return (0);
}