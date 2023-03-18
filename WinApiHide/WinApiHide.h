constexpr uint32_t DJB2_HASH(const char* str, uint32_t hash = 5381) {
    return *str ? DJB2_HASH(str + 1, ((hash << 5) + hash) ^ *str) : hash;
}

FARPROC GetProcAddressByHash(HMODULE hModule, uint32_t dwHash) {
    if (!hModule) {
        return nullptr;
    }

    PIMAGE_DOS_HEADER pDOSHeader = (PIMAGE_DOS_HEADER)hModule;
    PIMAGE_NT_HEADERS pNTHeaders = (PIMAGE_NT_HEADERS)((LPBYTE)hModule + pDOSHeader->e_lfanew);
    PIMAGE_EXPORT_DIRECTORY pExportDirectory = (PIMAGE_EXPORT_DIRECTORY)((LPBYTE)hModule + pNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
    LPDWORD pNameRVAs = (LPDWORD)((LPBYTE)hModule + pExportDirectory->AddressOfNames);
    LPWORD pNameOrdinals = (LPWORD)((LPBYTE)hModule + pExportDirectory->AddressOfNameOrdinals);

    for (DWORD i = 0; i < pExportDirectory->NumberOfNames; ++i) {
        char* pFunctionName = (char*)((LPBYTE)hModule + pNameRVAs[i]);
        if (DJB2_HASH(pFunctionName) == dwHash) {
            DWORD dwFunctionRVA = ((LPDWORD)((LPBYTE)hModule + pExportDirectory->AddressOfFunctions))[pNameOrdinals[i]];
            return (FARPROC)((LPBYTE)hModule + dwFunctionRVA);
        }
    }

    return nullptr;
}