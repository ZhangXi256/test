#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace __specializationTest
{
	template<class T>
	class A
	{
	public:
		A(const T& v)
		{
			cout << v << endl;
		}

		~A()
		{
		}

	private:

	};

	template<>
	class A< int >
	{
	public:
		A(int v)
		{
			cout << "specialization" << endl;
		}

		~A()
		{
		}

	private:

	};

	static void test()
	{
		A<double> a(100.0);
		A<int> b(100.0);
	}
}