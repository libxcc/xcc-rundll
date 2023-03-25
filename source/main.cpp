#include <source/XConsoleApplication.h>


// main
int main(int _Argc, char** _Argv)
{
	XCC_UNUSED(_Argc);
	XCC_UNUSED(_Argv);

#if defined(XCC_SYSTEM_WINDOWS)
	WSADATA		vWsaData;
	WSAStartup(MAKEWORD(2, 2), &vWsaData);
	OleInitialize(nullptr);
#else
	signal(SIGPIPE, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
#endif
	x_posix_setlocale(LC_ALL, "chs");

	auto		vSync = XConsoleApplication().run(_Argc, _Argv);

#if defined(XCC_SYSTEM_WINDOWS)
	OleUninitialize();
	WSACleanup();
#endif
	return vSync;
}
