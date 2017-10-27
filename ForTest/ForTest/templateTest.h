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
		A<int> b((int)100.0);
	}
}

namespace __specializeFunctionTest
{
	template <typename T> int compare(const T &v1, const T &v2)
	{
		std::cout << "template <typename T>" << std::endl;
		if (v1 < v2) return -1;
		if (v2 < v1) return 1;
		return 0;
	}
	template <> int compare<const char *>(const char * const &v1, const char * const &v2)
	{
		std::cout << "template <> int compare<const char *>" << std::endl;
		return strcmp(v1, v2);
	}
	template <> int compare<char *>(char * const &v1, char * const &v2)
	{
		std::cout << "template <> int compare<char *>" << std::endl;
		return strcmp(v1, v2);
	}

	void test()
	{
		char *pc = "ccc";
		char *pd = "ddd";
		cout << compare(pc, pd) << endl;
	}
}

namespace __forwardDeclarationTest
{
	class MyType;

	template<class T>
	class A
	{
		T *t;
	public:
		void print()
		{
			cout << *t << endl;
		}
	};

	void fun()
	{
		A<MyType> a;
		a.print();
	}

	class MyType
	{
		friend ostream& operator<<(ostream&o, const MyType& v);
	public:

	};

	ostream& operator<<(ostream&o, const MyType& v)
	{
		o << "hello, MyType";
		return o;
	}

	void test()
	{
		fun();
	}
}

namespace __safely_specialize_function_templates
{
	/*
	template<class T>
	void printString(const T& s)
	{
		//���ֱ�Ӱ�ʵ��д�������棬����string���͵���Ҳ�ܴ��ݽ��������±��벻������������
	}
	*/

	template<class T>
	struct printStringImpl;

	template<class T>
	void printString(const T& s)
	{
		printStringImpl<T>::f(s);
	}

	template<class T>
	struct printStringImpl
	{
		static void f(const T& s)
		{
			//�������ͣ������ʲôҲ���ɣ�
		}
	};

	//ģ���ػ�
	template<>
	struct printStringImpl<string>
	{
		static void f(const string& s)
		{
			cout << s << endl;
		}
	};
	template<>
	struct printStringImpl<wstring>
	{
		static void f(const wstring& s)
		{
			wcout.imbue(locale("chs"));
			wcout << s << endl;
		}
	};
	/*���⴦��ʽ���ɻ�Ϊʲô��ֱ���ú������أ�
	��ΪprintStringҲ�Ǹ���ĳ�Ա����������Ϊ�����Ǵ�������Ϳ�ʼ��*/
	void test()
	{
		printString<string>("abcdef");
		printString<wstring>(L"����");
		printString<double>(1.1);
	}
}

namespace __templateTest
{
	void test()
	{
		__safely_specialize_function_templates::test();
	}
}