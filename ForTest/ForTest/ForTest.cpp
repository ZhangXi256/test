// ForTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "basicTest.h"
#include "boostTest.h"
#include "cpp11Test.h"
#include "classTest.h"
#include "templateTest.h"
#include "tstringTest.h"

int main()
{
	__safely_specialize_function_templates::test();
	return 0;
}

