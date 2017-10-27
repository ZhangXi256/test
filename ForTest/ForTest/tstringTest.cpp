#include "stdafx.h"
#include "tstringTest.h"


tstringTest::tstringTest()
{
}


tstringTest::~tstringTest()
{
}

#undef _UNICODE

namespace __tstringTest
{
#ifdef _UNICODE
	typedef wchar_t* LPTSTR;
	typedef wstring tstring;
#else
	typedef char* LPTSTR;
	typedef string tstring;
#endif // _UNICODE

	wchar_t* W2W(const wchar_t* w)
	{
		return (wchar_t*)w;
	}

	template<size_t N = 128>
	class W2A
	{
		char data[N] = {};
	public:
		char* operator()(const wchar_t* w)
		{
			wcstombs(data, w, N << 1);
			return data;
		}

	};


#ifdef _UNICODE
#define W2T W2W
#else
#define W2T W2A<>()	
#endif // _UNICODE

	void test()
	{
		tstring s(W2T(L"abcdef"));
#ifdef _UNICODE
		wcout << s << endl;
#else
		cout << s << endl;
#endif // _UNICODE
	}
}