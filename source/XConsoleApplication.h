#ifndef			_X_CONSOLE_APPLICATION_H_
#define			_X_CONSOLE_APPLICATION_H_

#include <source/XConsoleHeader.h>


// 主进程
class XConsoleApplication
{
public:
	// constructor
	XConsoleApplication() noexcept;

	// destructor
	virtual ~XConsoleApplication() noexcept;

private:
	// 动态库名称
	XString				memberDynamicPath;

	// 入口点
	XString				memberEntryPoint;

	// 参数列表
	std::vector<XString>		memberParamArray;

private:
	// 分析参数
	virtual bool analysisArg(int _Argc, char** _Argv) noexcept final;

private:
	// 调用: all
	static int call(void* _Func, const std::vector<XString>& _Args) noexcept;

	// 调用: 0
	static int call(void* _Func) noexcept;

	// 调用: 1
	static int call(void* _Func, const XString& _Arg1) noexcept;

	// 调用: 2
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2) noexcept;

	// 调用: 3
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3) noexcept;

	// 调用: 4
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4) noexcept;

	// 调用: 5
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5) noexcept;

	// 调用: 6
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6) noexcept;

	// 调用: 7
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6, const XString& _Arg7) noexcept;

	// 调用: 8
	static int call(void* _Func, const XString& _Arg1, const XString& _Arg2, const XString& _Arg3, const XString& _Arg4, const XString& _Arg5, const XString& _Arg6, const XString& _Arg7, const XString& _Arg8) noexcept;

public:
	// 执行
	virtual int run(int _Argc, char** _Argv) noexcept final;
};

#endif
