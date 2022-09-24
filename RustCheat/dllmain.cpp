#include "Includes.hpp"

void mainThread(LPVOID lpParam) {
    /* do The Console */
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    SetConsoleTitleA("[*] Debug Console");
    printf("[+] Allocated Console\n");
    /* do the Rest of the Cheat */
    Hooks::doHooks();

    while (!GetAsyncKeyState(VK_END) & 1)
        Sleep(100);

    /* Unload everything Cheat Related */
    Hooks::undoHooks();

    /* Free the Console and Close its write handle */
    FreeConsole();
    fclose(stdout);

    /* Free the Module from the Game and Exit this Thread */
    FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}

bool __stdcall DllMain(HMODULE hModule, DWORD dwCallReason,LPVOID lpReserved) {
    if (dwCallReason == DLL_PROCESS_ATTACH) {
        if (HANDLE pHandle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainThread), nullptr, NULL, nullptr))
            CloseHandle(pHandle);
    }

    return true;
}

