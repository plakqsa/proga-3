#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int N = 8;

void Matr(int(*A)[N]) {
    int* end = A[0] + N * N - 1;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            destCoord.X = i * 4;
            destCoord.Y = j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << A[i][j];
        }
}

void PerestanovkaVertical(int(*A)[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(A[i][j], A[i][j + (N / 2)]);
        }
    }
}

void PerestanovkaGorizont(int(*A)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < N; j++) {
            swap(A[i][j], A[i + (N / 2)][j]);
        }
    }
}

void Sort(int(*A)[N]) {
    int* pt = A[0];
    bool sorted = false;

    while (sorted != true) {
        sorted = true;
        for (int i = 0; i < (N * N - 1); i++)
            if (*(pt + i) > *(pt + i + 1)) {
                swap(*(pt + i), *(pt + i + 1));
                sorted = false;
            }

    }
}

int main()
{
    setlocale(0, "");
    srand(time(0));

    int A[N][N];

    /*  Задание №1   */ {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = 0;
            }

        Matr(A);

        int* end = A[0] + N * N - 1; 

        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int* pt = A[0], i = 0, x = 0, y = 0; pt <= end + (N - 1); pt++, i++, y++) {
            if (i % N == 0 && i != 0) {
                x++;
                y = 0;
                if (x % 2 == 0)
                    pt = &A[x][y];
                else
                    pt = &A[x][y + N - 1];
            }
            if (x % 2 == 0) {
                destCoord.X = x * 4;
                destCoord.Y = y;
                SetConsoleCursorPosition(hStdout, destCoord);
                *pt = 1 + rand() % (N * N);
                cout << *pt;
                Sleep(50);
            }
            else {
                destCoord.X = x * 4;
                destCoord.Y = N - y - 1;
                SetConsoleCursorPosition(hStdout, destCoord);
                *(pt - y - y) = 1 + rand() % (N * N);
                cout << *(pt - y - y);
                Sleep(50);
            }
        }

        cout << "\r";
        for (int i = 1; i <= N; i++)
            cout << "\n";
        system("pause");
    }

    /*  Задание №2   */ {
        
        system("cls");
        PerestanovkaVertical(A);
        Matr(A);
        Sleep(5000);

        system("cls");
        PerestanovkaGorizont(A);
        Matr(A);

        cout << "\n";
        system("pause");
    }

    /*  Задание №3   */ {
        system("cls");
        Sort(A);
        Matr(A);

        cout << "\n";
        system("pause");
    }

    /*  Задание №4   */ {
        int chislo;
        string sign;

    Menu: {
        cout << "Введите действие ('+', '-', '*', '/')\n";
        cin >> sign;
        cout << "Введите число:\n";
        cin >> chislo;


        }
    if (chislo == 0 && sign == "/") {
        cout << "НЕЛЬЗЯ ДЕЛИТЬ НА НОЛЬ";
    }
    else{
        if (sign == "+") {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A[i][j] += chislo;
        }
        else if (sign == "-") {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A[i][j] -= chislo;
        }
        else if (sign == "*") {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A[i][j] *= chislo;
        }
        else if (sign == "/") {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A[i][j] /= chislo;
        }
        else {
            goto Menu;
        }

        system("cls");
        Matr(A);

        cout << "\n";
    }
    }
}
