#include "stdafx.h"
#include "cpp11Test.h"

cpp11Test::cpp11Test()
{
}


cpp11Test::~cpp11Test()
{
}

namespace __constReferenceFunctionTest
{
	void trv(const function<void(int&)>& f = {})
	{
		vector<int> vt = { 1,2,3,4,5 };
		for (int& v : vt)
		{
			f(v);
		}
		cout << "\n---------------------\n";
		for (int v : vt)
		{
			cout << v << ",";
		}
	}

	void test()
	{
		auto f = [](int& v)->void {
			cout << v++ << endl;
		};
		trv(f);
	}
}

namespace __functionTest
{
	// a class with data members:
	struct MyValue {
		int value;
		int fifth() { return value / 5; }
	};
	void test()
	{
		// stuff with members:
		std::function<int(MyValue&)> value = &MyValue::value;  // pointer to data member
		std::function<int(MyValue&)> fifth = &MyValue::fifth;  // pointer to member function

		MyValue sixty{ 60 };

		std::cout << "value(sixty): " << value(sixty) << '\n';
		std::cout << "fifth(sixty): " << fifth(sixty) << '\n';
	}
}

namespace __moveTest
{
	void test()
	{
		string s2;
		//调的是move语义的operator=
		s2 = string("123456");
	}
}

namespace __cpp11Test
{
	void test()
	{
		__moveTest::test();
	}
}