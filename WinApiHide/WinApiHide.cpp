#include <Windows.h>
#include <cstdint>
#include <string>

#include "WinApiHide.h"

int main() {
    constexpr uint32_t MessageBoxAHash = DJB2_HASH("MessageBoxA");
    HMODULE hUser32 = LoadLibrary(L"user32.dll");

    if (hUser32) {
        using MessageBoxA_t = int(WINAPI*)(HWND, LPCSTR, LPCSTR, UINT);
        MessageBoxA_t pMessageBoxA = (MessageBoxA_t)GetProcAddressByHash(hUser32, MessageBoxAHash);

        if (pMessageBoxA) {
            pMessageBoxA(NULL, "Hello, World!", "Example", MB_OK);
        }
        else {
            printf("Could not get the MessageBoxA address by hash value"); // Не удалось получить адрес MessageBoxA по хеш-значению
        }
        FreeLibrary(hUser32);
    }
    else {
        printf("Failed to get a module descriptor user32.dll"); // Не удалось получить дескриптор модуля user32.dll
    }

    return 0;
}