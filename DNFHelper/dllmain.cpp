// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "激活.h"
#include "LDR断链 清除PE.h"
#include "劫持.h"
#include <exception>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	try
	{
		Load();
		HMODULE myModule = hModule;
		switch (ul_reason_for_call)
		{
		case DLL_PROCESS_ATTACH:
			Hide(hModule);
			激活();
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
		}
	}
	catch (std::exception){}
    return TRUE;
}

