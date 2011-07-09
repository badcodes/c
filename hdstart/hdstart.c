#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "resource.h"
#include "hcstart.h"

HINSTANCE hInst;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            /*
             * TODO: Add code to initialize the dialog.
             */
            return TRUE;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                /*
                 * TODO: Add more control ID's, when needed.
                 */
                case IDC_BTN_QUIT:
                    EndDialog(hwndDlg, 0);
                    return TRUE;

                case IDC_BTN_TEST:
                    MessageBox(hwndDlg, "You clicked \"Test\" button!", "Information", MB_ICONINFORMATION);
                    return TRUE;
            }
    }

    return FALSE;
}

#ifndef STANDALONE
#else
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    LPTSTR cmdline = GetCommandLine();
    int* argc;
    LPTSTR* argv;
    argv = CommandlineToArgv(LPTSTR,*argc)
    int r = HDSTART_MAIN(*argc,LPTSTR);
    GlobalFree(LPTSTR);
    return r;

    hInst = hInstance;
    if(strlen(lpCmdLine) == 0) {
        return MessageBox(NULL,"Usage:\n" HDSTART_NAME_TEXT " [Command lines...]",THIS_APP_NAME,MB_OK);
    }
    ShellExecute()
    // The user interface is a modal dialog box
    // return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}
#endif

int HDSTART_MAIN(int argc,TCHAR* argv) {
    if(argc<1) {
         return MessageBox(NULL,"Usage:\n" HDSTART_NAME_TEXT " [Command lines...]",THIS_APP_NAME,MB_OK);
    }

}




