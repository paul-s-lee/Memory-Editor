#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

DWORD pid; // process id

string addr; // address without prefix
string wndt; // window title
string addr_with_prefix = "0x"; // address prefix

int val; // value we want to change

int main()
{
	cout << "Enter process window title: ";
	getline(cin, wndt);

	cout << "Enter new value: ";
	cin >> val;

	cout << "Enter address: ";
	cin >> addr;

	// concatenate 0x prefix with addr
	addr_with_prefix += addr;

	// convert addr_with_prefix to DWORD value
	DWORD addr_dw = strtol(addr_with_prefix.c_str(), 0, 0);

	// create handle to a window
	HWND wHandle = FindWindow(0, (wndt.c_str()));

	// obtain process id of game
	GetWindowThreadProcessId(wHandle, &pid);

	// create handle to process
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	// Write new data to process memory
	WriteProcessMemory(pHandle, (LPVOID)addr_dw, &val, sizeof(val), 0);

	system("pause");
}
