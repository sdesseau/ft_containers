
#include "test_include.hpp"


// typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
// typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

// static int iter = 0;

// template <typename MAP>
// void	ft_bound(MAP &mp, const T1 &param)
// {
// 	ft_iterator ite = mp.end(), it[2];
// 	_pair<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

int main()
{
	 /* Tests Vector */

	// std::cout << std::endl << "                   New Test" << std::endl;
    test_assign();
	// std::cout << std::endl << "                   New Test" << std::endl;
    test_bidirect_it();
	// std::cout << std::endl << "                   New Test" << std::endl;
    test_size();
	// std::cout << std::endl << "                   New Test" << std::endl;
    test_erase();

	// /* Test Iterator Vector */

	// std::cout << std::endl << "                   New Test" << std::endl;
    test_ite();
	// std::cout << std::endl << "                   New Test" << std::endl;
	test_ite_eq_ope();
	// std::cout << std::endl << "                   New Test" << std::endl;
	test_rev_it();

	// /* Test Map */

	// std::cout << std::endl << "                   New Test" << std::endl;
	test_map_copyconstruct();
	// std::cout << std::endl << "                   New Test" << std::endl;
	test_construct_hard();

	// TESTED_NAMESPACE::map<char,int> first;
	// TESTED_NAMESPACE::map<char,int> second;

	// first['x']=8;
	// first['y']=16;
	// first['z']=32;

	// second=first;                // second now contains 3 ints
	// first=TESTED_NAMESPACE::map<char,int>();  // and first is now empty

	// std::cout << "Size of first: " << first.size() << '\n';
	// std::cout << "Size of second: " << second.size() << '\n';

	// TESTED_NAMESPACE::map<char,std::string> mymap2;

	// mymap2['a']="an element";
	// mymap2['b']="another element";
	// mymap2['c']=mymap2['b'];

	// std::cout << "mymap2['a'] is " << mymap2['a'] << '\n';
	// std::cout << "mymap2['b'] is " << mymap2['b'] << '\n';
	// std::cout << "mymap2['c'] is " << mymap2['c'] << '\n';
	// std::cout << "mymap2['d'] is " << mymap2['d'] << '\n';

	// std::cout << "mymap2 now contains " << mymap2.size() << " elements.\n";


	// TESTED_NAMESPACE::vector<int> v;
	// for (int i = 0; i < 10; i++)
	// 	v.push_back(i * 4);

	// // std::string s = "0101010001111010101010101001010111101";

	// // for (unsigned int i = 0; i < s.size(); i++)
	// // {
	// // 	if (s[i] == '1')
	// // 		v.push_back(i);
	// // 	if (s[i] == '0')
	// // 		v.pop_back();
	// // }
	
	// // for (TESTED_NAMESPACE::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	// TESTED_NAMESPACE::vector<int>::const_reverse_iterator it = v.rbegin();
	// TESTED_NAMESPACE::vector<int>::const_reverse_iterator ite = v.rend();
	// while (it != ite){
	// 	std::cout << (*(it)) << std::endl;
	// 	it++;



	// TESTED_NAMESPACE::vector<int> v;
	// for (int i = 0; i < 10; i++)
	// 	v.push_back(i * 4);

	// std::string s = "0101010001111010101010101001010111101";

	// for (unsigned int i = 0; i < s.size(); i++)
	// {
	// 	if (s[i] == '1')
	// 		v.push_back(i);
	// 	if (s[i] == '0')
	// 		v.pop_back();
	// }
	
	// // for (TESTED_NAMESPACE::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	// TESTED_NAMESPACE::vector<int>::const_reverse_iterator it = v.rbegin();
	// TESTED_NAMESPACE::vector<int>::const_reverse_iterator ite = v.rend();
	// while (it != ite){
	// 	std::cout << (*(it)) << std::endl;
	// 	it++;
	// }


	// TESTED_NAMESPACE::map<int, int> v;
	// for (int i = 0; i < 10; i++)
	// 	v.insert(TESTED_NAMESPACE::pair<int, int>(i * 4, i));
	
	// // for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	// TESTED_NAMESPACE::map<int, int>::const_reverse_iterator it2 = v.rbegin();
	// TESTED_NAMESPACE::map<int, int>::const_reverse_iterator ite2 = v.rend();
	// while (it2 != ite2){
	// 	std::cout << (*(it2)).first << std::endl;
	// 	it2++;
	// }
    // std::cout << std::endl;


	// std::list<T3> lst;
	// unsigned int lst_size = 7;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(T3(lst_size - i, i));

	// TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	// TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	// TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	// for (int i = 0; it != ite; ++it)
	// 	it->second = ++i * 5;

	// it = mp.begin(); ite = --(--mp.end());
	// TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	// for (int i = 0; it != ite; ++it)
	// 	it->second = ++i * 7;

	// std::cout << "\t-- PART ONE --" << std::endl;
	// printSizeMap(mp);
	// printSizeMap(mp_range);
	// printSizeMap(mp_copy);

	// mp = mp_copy;
	// mp_copy = mp_range;
	// mp_range.clear();

	// std::cout << "\t-- PART TWO --" << std::endl;
	// printSizeMap(mp);
	// printSizeMap(mp_range);
	// printSizeMap(mp_copy);




// std::list<T3> lst2;
// 	unsigned int lst2_size2 = 10;
// 	for (unsigned int i = 0; i < lst2_size2; ++i)
// 		lst2.push_back(T3(i + 1, (i + 1) * 3));
// 	TESTED_NAMESPACE::map<T1, T2> mp3(lst2.begin(), lst2.end());
// 	printSizeMap(mp3);

// 	ft_const_bound(mp3, -10);
// 	ft_const_bound(mp3, 1);
// 	ft_const_bound(mp3, 5);
// 	ft_const_bound(mp3, 10);
// 	ft_const_bound(mp3, 50);

// 	printSizeMap(mp3);

// 	mp3.lower_bound(3)->second = 404;
// 	mp3.upper_bound(7)->second = 842;
// 	ft_bound(mp3, 5);
// 	ft_bound(mp3, 7);

// 	printSizeMap(mp3);

//  TESTED_NAMESPACE::map<char,int> mymap;

//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;

//   TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<char,int>::iterator,TESTED_NAMESPACE::map<char,int>::iterator> ret;
//   ret = mymap.equal_range('b');

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';
  



// TESTED_NAMESPACE::vector<int> v;
// 	for (int i = 0; i < 10; i++)
// 		v.push_back(i * 4);

// 	std::string s = "0101010001111010101010101001010111101";

// 	for (unsigned int i = 0; i < s.size(); i++)
// 	{
// 		if (s[i] == '1')
// 			v.push_back(i);
// 		if (s[i] == '0')
// 			v.pop_back();
// 	}
	
// 	// for (TESTED_NAMESPACE::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
// 	TESTED_NAMESPACE::vector<int>::const_reverse_iterator it = v.rbegin();
// 	TESTED_NAMESPACE::vector<int>::const_reverse_iterator ite = v.rend();
// 	while (it != ite){
// 		std::cout << (*(it)) << std::endl;
// 		it++;
// 	}


	// TESTED_NAMESPACE::map<std::string, T2> mapp;

	// mapp["Bonbon"] = 10;
	// mapp["Canard"] = 20;
	// mapp["Durite"] = 30;
	// mapp["Elephant"] = 40;
	// TESTED_NAMESPACE::map<std::string, T2> mapp2(mapp);
	// TESTED_NAMESPACE::map<std::string, T2>::iterator t2332 = mapp2.begin();

	// TESTED_NAMESPACE::map<std::string, T2>::iterator t = mapp.begin();
	// while (t != mapp.end())
	// 	std::cout << "ite* = " << (*(t++)).second << std::endl;
	// TESTED_NAMESPACE::map<std::string, T2>::iterator itt = mapp.begin();
	// 	std::cout << "itttte* = " << (*(itt)).second << std::endl;
	
	// (*(itt)).second = 42;
	// mapp.erase("Canard");
	// t = mapp.begin();
	// while (t != mapp.end())
	// 	std::cout << "ite* = " << (*(t++)).second << std::endl;

	// mapp.swap(mapp2);
	// t = mapp.begin();
	// while (t != mapp.end())
	// 	std::cout << "ite* = " << (*(t++)).second << std::endl;
	// std::cout << "itttte* = " << (*(itt)).second << std::endl;
	// std::cout << "t2332* = " << (*(t2332)).second << std::endl;

	TESTED_NAMESPACE::map<T1, T2> mapp;
	for (int i = 0; i < 200000; i++)
		mapp[i] = i * 4;
	mapp.insert(mapp.begin(), mapp.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator t = mapp.begin();
	// while (t != mapp.end())
	// 	std::cout << "ite* = " << (*(t++)).second << std::endl;
	for (int i = 0; i < 200000; i++)
		mapp.erase(i);
	for (int i = 0; i < 200000; i++)
		mapp[i] = i * 4;
	mapp.erase(mapp.begin(), mapp.end());
	t = mapp.begin();
	while (t != mapp.end())
		std::cout << "ite* = " << (*(t++)).second << std::endl;
}
