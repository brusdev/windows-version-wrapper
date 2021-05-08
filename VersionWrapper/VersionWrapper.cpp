// VersionWrapper.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "VersionWrapper.h"

typedef DWORD(CALLBACK* LPFN_GET_FILE_VERSION_INFO_SIZE_A)(LPCSTR, LPDWORD);

DWORD
APIENTRY
GetFileVersionInfoSizeA(
    _In_        LPCSTR lptstrFilename, /* Filename of version stamped file */
    _Out_opt_ LPDWORD lpdwHandle       /* Information for use by GetFileVersionInfo */
) {
    HINSTANCE hDLL;
    LPFN_GET_FILE_VERSION_INFO_SIZE_A lpfnGetFileVersionInfoSizeA;
    DWORD returnVal;

    hDLL = LoadLibrary(L"/Windows/System32/version.dll");
    if (NULL != hDLL)
    {
        lpfnGetFileVersionInfoSizeA = (LPFN_GET_FILE_VERSION_INFO_SIZE_A)
            GetProcAddress(hDLL, "GetFileVersionInfoSizeA");
        if (NULL != lpfnGetFileVersionInfoSizeA)
        {
            returnVal = lpfnGetFileVersionInfoSizeA(lptstrFilename, lpdwHandle);
        }
        else
        {
            returnVal = ERROR_DELAY_LOAD_FAILED;
        }
        FreeLibrary(hDLL);
    }
    else
    {
        returnVal = ERROR_DELAY_LOAD_FAILED;
    }

    return returnVal;
}

