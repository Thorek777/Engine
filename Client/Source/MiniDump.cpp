/*
 * Author: Thorek
 */

#include <format>
#include <iomanip>
#include <sstream>
#include "Version.h"
#include "MiniDump.h"
#include <minidumpapiset.h>

#pragma warning(disable: 4996)

void make_minidump(EXCEPTION_POINTERS* e)
{
	const auto hDbgHelp = LoadLibraryA("dbghelp");

	if (hDbgHelp == nullptr)
	{
		return;
	}

	const auto pMiniDumpWriteDump = reinterpret_cast<decltype(&MiniDumpWriteDump)>(GetProcAddress(hDbgHelp, "MiniDumpWriteDump"));

	if (pMiniDumpWriteDump == nullptr)
	{
		return;
	}

	const std::string folder = "logs";
	CreateDirectoryA(folder.c_str(), nullptr);
	const auto t = std::time(nullptr);
	std::ostringstream timefmt;
	timefmt << std::put_time(std::localtime(&t), "%Y%m%d_%H%M%S");
	const std::string filename = format("{}\\client_{}_{}.dmp", folder, GetVer(), timefmt.str());
	const auto hFile = CreateFileA(filename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = e;
	exceptionInfo.ClientPointers = FALSE;
	pMiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, static_cast<MINIDUMP_TYPE>(MiniDumpWithIndirectlyReferencedMemory | MiniDumpScanMemory), e ? &exceptionInfo : nullptr, nullptr, nullptr);
	CloseHandle(hFile);
}

LONG __stdcall EterExceptionFilter(_EXCEPTION_POINTERS* pExceptionInfo)
{
	make_minidump(pExceptionInfo);
	return EXCEPTION_EXECUTE_HANDLER;
}
