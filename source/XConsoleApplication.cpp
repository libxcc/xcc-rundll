﻿#include <source/XConsoleApplication.h>



// constructor
XConsoleApplication::XConsoleApplication() noexcept = default;

// destructor
XConsoleApplication::~XConsoleApplication() noexcept = default;



// 分析参数
bool XConsoleApplication::analysisArg(int _Argc, char** _Argv) noexcept
{
	if(_Argc < 3)
	{
		return false;
	}

	// 动态库
	memberDynamicPath = _Argv[1];
#if defined(XCC_SYSTEM_WINDOWS)
	if(XFile::exist(XString::fromAString(_Argv[1])))
	{
		memberDynamicPath = XString::fromAString(_Argv[1]);
	}
#endif

	// 入口点
	memberEntryPoint = _Argv[2];

	// 参数
	for(auto vIndex = 3; vIndex < _Argc; ++vIndex)
	{
		memberParamArray.emplace_back(_Argv[vIndex]);
	}

	if(memberDynamicPath.empty() || memberEntryPoint.empty())
	{
		return false;
	}
	return true;
}



// 调用: all
int XConsoleApplication::call(void* _Func, const std::vector<XString>& _Args) noexcept
{
	auto		vSize = _Args.size();
	switch (vSize)
	{
		case 0:		return XConsoleApplication::call(_Func);
		case 1:		return XConsoleApplication::call(_Func, _Args[0]);
		case 2:		return XConsoleApplication::call(_Func, _Args[0], _Args[1]);
		case 3:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2]);
		case 4:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2], _Args[3]);
		case 5:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2], _Args[3], _Args[4]);
		case 6:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2], _Args[3], _Args[4], _Args[5]);
		case 7:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2], _Args[3], _Args[4], _Args[5], _Args[6]);
		case 8:		return XConsoleApplication::call(_Func, _Args[0], _Args[1], _Args[2], _Args[3], _Args[4], _Args[5], _Args[6], _Args[7]);
		default:	return E2BIG;
	}
}

// 调用: 0
int XConsoleApplication::call(void* _Func) noexcept
{
	typedef int(__xcall__ * func_call_type)();

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress();
	return vSync;
}

// 调用: 1
int XConsoleApplication::call(void* _Func, const XString& _Arg1) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data());
	return vSync;
}

// 调用: 2
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data());
	return vSync;
}

// 调用: 3
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data());
	return vSync;
}

// 调用: 4
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3, const char* _Arg4);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data(), _Arg4.data());
	return vSync;
}

// 调用: 5
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3, const char* _Arg4, const char* _Arg5);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data(), _Arg4.data(), _Arg5.data());
	return vSync;
}

// 调用: 6
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3, const char* _Arg4, const char* _Arg5, const char* _Arg6);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data(), _Arg4.data(), _Arg5.data(), _Arg6.data());
	return vSync;
}

// 调用: 7
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6, const XString& _Arg7) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3, const char* _Arg4, const char* _Arg5, const char* _Arg6, const char* _Arg7);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data(), _Arg4.data(), _Arg5.data(), _Arg6.data(), _Arg7.data());
	return vSync;
}

// 调用: 8
int XConsoleApplication::call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6, const XString& _Arg7, const XString& _Arg8) noexcept
{
	typedef int(__xcall__ * func_call_type)(const char* _Arg1, const char* _Arg2, const char* _Arg3, const char* _Arg4, const char* _Arg5, const char* _Arg6, const char* _Arg7, const char* _Arg8);

	auto		vFuncAddress = (func_call_type)_Func;
	auto		vSync = vFuncAddress(_Arg1.data(), _Arg2.data(), _Arg3.data(), _Arg4.data(), _Arg5.data(), _Arg6.data(), _Arg7.data(), _Arg8.data());
	return vSync;
}



// 执行
int XConsoleApplication::run(int _Argc, char** _Argv) noexcept
{
	// 检查参数
	if(!this->analysisArg(_Argc, _Argv))
	{
		XLOG_ERROR(nullptr, u8"[%s : %d] Invalid parameter", __XFUNCTION__, __XLINE__);
		return EINVAL;
	}

	// 检查文件是否存在
	if(!XFile::exist(memberDynamicPath))
	{
		XLOG_ERROR(nullptr, u8"[%s : %d] Unable to find dynamic library file : %s", __XFUNCTION__, __XLINE__, memberDynamicPath.data());
		return ENOEXEC;
	}

	// 打开动态库
	auto		vHandle = XDynamicLibrary::open(memberDynamicPath);
	if(vHandle == nullptr)
	{
		auto		vErrorS = XDynamicLibrary::error();
		XLOG_ERROR(nullptr, u8"[%s : %d] File could not be loaded : %s\n%s", __XFUNCTION__, __XLINE__, memberDynamicPath.data(), vErrorS.data());
		return ENXIO;
	}

	// 查找入口点
	auto		vFuncAddress = XDynamicLibrary::find(vHandle, memberEntryPoint);
	if(vFuncAddress == nullptr)
	{
		XLOG_ERROR(nullptr, u8"[%s : %d] The specified entry point was not found : %s", __XFUNCTION__, __XLINE__, memberEntryPoint.data());
		XDynamicLibrary::close(vHandle);
		return ESRCH;
	}

	// 执行程序
	auto		vSync = XConsoleApplication::call(vFuncAddress, memberParamArray);
	XDynamicLibrary::close(vHandle);
	XLOG_INFO(nullptr, u8"[%s : %d] call %s returns %d", __XFUNCTION__, __XLINE__, memberEntryPoint.data(), vSync);
	return vSync;
}
