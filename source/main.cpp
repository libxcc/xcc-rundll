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
#if defined(XANADU_BUILD_DEBUG)
	AllocConsole();
	SetConsoleTitleW(L"xcc-rundll 调试模式");
	SetWindowPos(GetConsoleWindow(), HWND_TOP, 10, 10, 0, 0, SWP_NOSIZE);
	auto		vConsoleHandle = x_posix_freopen("CONOUT$", "w+t", stdout);
#endif
#else
	signal(SIGPIPE, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
#endif
	x_posix_setlocale(LC_ALL, "chs");

	auto		vSync = XConsoleApplication().run(_Argc, _Argv);

	// x_posix_system("PAUSE");
#if defined(XCC_SYSTEM_WINDOWS)
#if defined(XANADU_BUILD_DEBUG)
	if(vConsoleHandle)
	{
		x_posix_fclose(vConsoleHandle);
		vConsoleHandle = nullptr;
	}
	FreeConsole();
	SendMessageW(GetConsoleWindow(), WM_CLOSE, NULL, NULL);
#endif
	OleUninitialize();
	WSACleanup();
#endif
	return vSync;
}
