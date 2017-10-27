#include "stdafx.h"
#include "basicTest.h"


basicTest::basicTest()
{
}


basicTest::~basicTest()
{
}

namespace __constCharPtrTest
{
	void f(const char* s)
	{
		//s[0] = 'a';//error
		s = NULL;
	}
	void test()
	{

	}
}

namespace __basicTest
{
	void test()
	{

	}
}
