#include "stdafx.h"
#include "classTest.h"


classTest::classTest()
{
}


classTest::~classTest()
{
}

namespace __sizeofTest
{
	class A
	{
	public:
		const int a = 100;
		const int b = 100;
		const int c = 100;
		const static int d = 100;
		const int e;
		A():e(100){}
	};

	void test()
	{
		cout << sizeof(A) << endl;
	}
}

namespace __classTest
{
	void test()
	{
		__sizeofTest::test();
	}
}
