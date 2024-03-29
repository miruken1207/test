#include "SystemCommands.h"

void Input(char& key)
{
    key = _getch();
}

void Clear()
{
    system("cls");
}

void Error()
{
    MessageBeep(MB_ICONHAND);
}

void GoToXY(short x, short y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void RED()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
}
void YELLOW()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14);
}
void GREEN()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
}
void PURPLE()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13);
}
void WHITE()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
}
void GRAY()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 8);
}
void BLACK()
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 0);
}

void FRAME()
{
    YELLOW();

    const int LENGTH = 120;
    const int HEIIGHT = 29;

    GoToXY(0, 0);
    for (int i = 1; i <= LENGTH; i++)
    {
        if (i == 1 or i == 120)
            cout << '#';
        else
            cout << '-';
    }

    int y = 1;
    for (int i = 1; i <= HEIIGHT; i++)
    {
        GoToXY(0, y++);
        cout << '|';
    }

    y = 1;
    for (int i = 1; i <= HEIIGHT; i++)
    {
        GoToXY(119, y++);
        cout << '|';
    }

    GoToXY(0, 29);
    for (int i = 1; i <= LENGTH; i++)
    {
        if (i == 1 or i == 120)
            cout << '#';
        else
            cout << '-';
    }
}
void GameZoneFRAME()
{
    YELLOW();

    const int LENGTH = 120;
    const int HEIIGHT = 28;

    GoToXY(0, 0);
    for (int i = 1; i <= LENGTH; i++)
    {
        if (i == 1 or i == 120)
            cout << '#';
        else
            cout << '-';
    }

    int y = 1;
    for (int i = 1; i <= HEIIGHT; i++)
    {
        GoToXY(60, y++);
        if (y != 3)
            cout << '|';
    }

    y = 1;
    for (int i = 1; i <= HEIIGHT; i++)
    {
        GoToXY(0, y++);
        cout << '|';
    }

    y = 1;
    for (int i = 1; i <= HEIIGHT; i++)
    {
        GoToXY(119, y++);
        cout << '|';
    }

    GoToXY(0, 29);
    for (int i = 1; i <= LENGTH; i++)
    {
        if (i == 1 or i == 120)
            cout << '#';
        else
            cout << '-';
    }
}

void RockOutPlayer()
{
    const char rock[10][14]
    {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ','_',' ','_','_',' ','_','_',' ','_','_',' ',' ',' ',
        '/',' ','/',' ',' ','/',' ',' ','/',' ',' ','/','_',' ',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\\',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 25, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << rock[i][j];

        }
        GoToXY(x, ++y);
    }
}
void RockOutBot()
{
    const char rock[10][14]
    {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ','_',' ','_','_',' ','_','_',' ','_','_',' ',' ',' ',
        '/',' ','/',' ',' ','/',' ',' ','/',' ',' ','/','_',' ',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\\',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 80, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << rock[i][j];

        }
        GoToXY(x, ++y);
    }
}

void ScissorsOutPlayer()
{
    const char scissors[10][14]
    {
        ' ',' ',' ',' ','^',' ',' ',' ',' ',' ',' ',' ',' ','^',
        ' ',' ',' ',' ','\\',' ','\\',' ',' ',' ',' ','/',' ','/',
        ' ',' ',' ',' ',' ','\\',' ','\\',' ',' ','/',' ','/',' ',
        ' ','_','_',' ','_','_','\\',' ','\\','/',' ','/','_',' ',
        '/',' ',' ','/',' ',' ',' ',' ',' ',' ',' ','|',' ','\\',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 25, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << scissors[i][j];

        }
        GoToXY(x, ++y);
    }
}
void ScissorsOutBot()
{
    const char scissors[10][14]
    {
        ' ',' ',' ',' ','^',' ',' ',' ',' ',' ',' ',' ',' ','^',
        ' ',' ',' ',' ','\\',' ','\\',' ',' ',' ',' ','/',' ','/',
        ' ',' ',' ',' ',' ','\\',' ','\\',' ',' ','/',' ','/',' ',
        ' ','_','_',' ','_','_','\\',' ','\\','/',' ','/','_',' ',
        '/',' ',' ','/',' ',' ',' ',' ',' ',' ',' ','|',' ','\\',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 80, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << scissors[i][j];
        }
        GoToXY(x, ++y);
    }
}

void PaperOutPlayer()
{
    const char paper[10][14]
    {
        ' ',' ',' ',' ',' ',' ',' ','^',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ','^',' ','|',' ','|',' ','^',' ',' ',' ',
        ' ','^',' ','|',' ','|','|',' ','|','|',' ','|',' ',' ',
        '|',' ','|','|',' ','|','|',' ','|','|',' ','|',' ',' ',
        '|',' ','|','|',' ','|','|',' ','|','|',' ','|','^',' ',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 25, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << paper[i][j];

        }
        GoToXY(x, ++y);
    }
}
void PaperOutBot()
{
    const char paper[10][14]
    {
        ' ',' ',' ',' ',' ',' ',' ','^',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ','^',' ','|',' ','|',' ','^',' ',' ',' ',
        ' ','^',' ','|',' ','|','|',' ','|','|',' ','|',' ',' ',
        '|',' ','|','|',' ','|','|',' ','|','|',' ','|',' ',' ',
        '|',' ','|','|',' ','|','|',' ','|','|',' ','|','^',' ',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        ' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ','\\','_','_','_','_','_','_','_','_','/',' ',' ',
    };

    int x = 80, y = 10;
    GoToXY(x, y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cout << paper[i][j];
        }
        GoToXY(x, ++y);
    }
}

void UnkownOutBot()
{
    const char unknown[12][13] =
    {
        ' ',' ','_','_','_','_','_','_','_','_','_',' ',' ',
        ' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\',' ',
        '/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\',
        '\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
        ' ',' ',' ',' ',' ',' ',' ','_','_','_','/',' ',' ',
        ' ',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ','_',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ','(','_',')',' ',' ',' ',' ',' ',
    };

    int x = 80, y = 8;
    GoToXY(x, y);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            cout << unknown[i][j];
        }
        GoToXY(x, ++y);
    }
}














