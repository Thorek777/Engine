#pragma once

#include <WS2tcpip.h>

void make_minidump(EXCEPTION_POINTERS* e);
LONG __stdcall EterExceptionFilter(_EXCEPTION_POINTERS* pExceptionInfo);
