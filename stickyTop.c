#include <windows.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//          List opened windows titles without system windows         //
////////////////////////////////////////////////////////////////////////

BOOL IsWindowVisibleAndOwned(HWND hwnd)
{
    DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
    if (!(dwStyle & WS_VISIBLE))
        return FALSE;
    if (GetWindow(hwnd, GW_OWNER) != NULL)
        return FALSE;
    return TRUE;
}

void ListUserWindows()
{
    HWND hwnd = GetTopWindow(NULL);
    while (hwnd != NULL)
    {
        wchar_t szWindowName[256];
        if (IsWindowVisibleAndOwned(hwnd))
        {
            if (GetWindowTextW(hwnd, szWindowName, sizeof(szWindowName)/sizeof(wchar_t)) > 0)
            {
                wprintf(L"%s\n", szWindowName);
            }
        }
        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
    }
}

////////////////////////////////////////////////////////////////////////
//          Set a window to be on top of all other windows            //
////////////////////////////////////////////////////////////////////////

// Get the handle of the target window from its title
// Returns NULL if the window is not found
// The handle of a window is a unique identifier that allows it to be identified
HWND GetTargetWindowHandle(char* windowTitle) {
    HWND hwnd = FindWindowA(NULL, windowTitle);
    if (!hwnd) {
        printf("La fenetre \"%s\" n'a pas ete trouvee.\n", windowTitle);
        return NULL;
    }
    return hwnd;
}

// Set the window to be on top of all other windows using windows functions
void SetWindowTopMost(HWND hwnd) {
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

// Set the window to be normal (not topmost) using windows functions
void SetWindowNormal(HWND hwnd) {
    SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

int Apply(char* windowTitle, char* action) {
    HWND hwnd = GetTargetWindowHandle(windowTitle);

    if (!hwnd) {
        printf("Error: could not find window \"%s\"\n", windowTitle);
        return 1;
    }

    if (strcmp(action, "top") == 0){
        SetWindowTopMost(hwnd);
        printf("Window \"%s\" is now on top\n", windowTitle);
    }
    else if (strcmp(action, "normal") == 0) {
        SetWindowNormal(hwnd);
        printf("Window \"%s\" is now normal\n", windowTitle);
    }
    else {
        printf("Invalid action \"%s\"\n", action);
        return 1;
    }

    return 0;
}

// get the window title from arguments
int main(int argc, char *argv[]) {
    if (argc == 2){
        if (strcmp(argv[1], "-list") == 0) {
            ListUserWindows();
            return 0;
        }
    }
    else if (argc == 3) {
        char* action = argv[1];
        char* windowTitle = argv[2];

        if (strcmp(action, "-top") == 0) {
            Apply(windowTitle, "top");
        }
        else if (strcmp(action, "-normal") == 0) {
            Apply(windowTitle, "normal");
        }
        else {
            printf("Invalid argument \"%s\"\n", argv[2]);
            return 1;
        }
    }
    else {
        printf("Usage : \n \"-top [window title]\" to set a window always in top \n \"-normal [window title]\" to set a window to be normal\n \"-list\" to list all opened windows \n");
        printf("\nPress any key to exit...\n");
        getchar();
        return 1;
    }
    

    return 0;
}
