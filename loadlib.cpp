#include <windows.h>
#include <stdio.h>
#include "USINE-SDK-PUBLIC/sdk/UserModule.h"

typedef void (*CreateModuleFunc)(void *&pModule, AnsiCharPtr optionalString, LongBool Flag, TMasterInfo *pMasterInfo, AnsiCharPtr optionalContent);

void print_last_error()
{
    DWORD errorCode = GetLastError();
    char *messageBuffer = NULL;

    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, 0, (LPSTR)&messageBuffer, 0, NULL);

    if (messageBuffer)
    {
        fprintf(stderr, "LoadLibrary failed with error %lu: %s\n", errorCode, messageBuffer);
        LocalFree(messageBuffer);
    }
    else
    {
        fprintf(stderr, "LoadLibrary failed with unknown error code: %lu\n", errorCode);
    }
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Not enough args: loadlib <lib.dll>\n");
        return 1;
    }

    HMODULE lib = LoadLibrary(argv[1]);
    if (!lib)
    {
        print_last_error();
        printf("Could not load DLL\n");
        return 1;
    }

    CreateModuleFunc create = (CreateModuleFunc)GetProcAddress(lib, "Create");
    if (!create)
    {
        printf("Could not find function\n");
        FreeLibrary(lib);
        return 1;
    }

    void *mod = NULL;

    create(mod, NULL, false, NULL, NULL);

    UserModuleBase *module = (UserModuleBase *)module;

    printf("Module: %p\n", module);

    FreeLibrary(lib);
    return 0;
}
