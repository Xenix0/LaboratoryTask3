﻿#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 6;
const int WIDTH = 3;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;


void set_element(int matrix[][N], int x, int y, int offset_x, int offset_y) {
    *(*(matrix + y) + x) = (rand() % (N * N)) + 1;
    destCoord.X = (x + offset_x) * WIDTH;
    destCoord.Y = y + offset_y;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << *(*(matrix + y) + x);
    Sleep(10);
}

void print_matrix(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destCoord.X = (i + offset_x) * WIDTH;
            destCoord.Y = j + offset_y;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);
        }
    }
}

void print_float_matrix(float matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destCoord.X = (i + offset_x) * WIDTH;
            destCoord.Y = j + offset_y;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);
        }
    }
}

void quicksort(int arr[][N], int end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    int index = (f + l) / 2;
    mid = *(*(arr + index % N) + index / N);
    while (f < l) {
        while (*(*(arr + f % N) + f / N) < mid) f++;
        while (*(*(arr + l % N) + l / N) > mid) l--;
        if (f <= l) {
            swap(*(*(arr + f % N) + f / N), *(*(arr + l % N) + l / N));
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}






void show_a(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = offset_x + j * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[31m" << *(*(matrix + i + N / 2) + j) << "\033[0m";

            destCoord.X = offset_x + (j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[32m" << *(*(matrix + i) + j) << "\033[0m";

            destCoord.X = offset_x + j * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[34m" << *(*(matrix + i + N / 2) + j + N / 2) << "\033[0m" ;

            destCoord.X = offset_x + (j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[33m" << *(*(matrix + i) + j + N / 2) << "\033[0m" ;
        }
    }
}

void show_b(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + (j + N / 2)) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[31m" << *(*(matrix + i + N / 2) + j) << "\033[0m" ;

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[32m" << *(*(matrix + i) + j) << "\033[0m" ;

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[34m" << *(*(matrix + i + N / 2) + j + N / 2) << "\033[0m" ;

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[33m" << *(*(matrix + i) + j + N / 2) << "\033[0m" ;
        }
    }
}

void show_c(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[31m" << *(*(matrix + i + N / 2) + j) << "\033[0m" ;

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[32m" << *(*(matrix + i) + j) << "\033[0m" ;

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[34m" << *(*(matrix + i + N / 2) + j + N / 2) << "\033[0m" ;

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[33m" << *(*(matrix + i) + j + N / 2) << "\033[0m" ;
        }
    }
}

void show_d(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[31m" << *(*(matrix + i + N / 2) + j) << "\033[0m" ;

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[32m" << *(*(matrix + i) + j) << "\033[0m";

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[34m" << *(*(matrix + i + N / 2) + j + N / 2) << "\033[0m" ;

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << "\033[33m" << *(*(matrix + i) + j + N / 2) << "\033[0m" ;
        }
    }
}

int main() {
    srand(time(nullptr));
    system("cls");
    setlocale(0, "");

    int matrixA[N][N], matrixB[N][N], y = 0, x = 0;

    cout << "Исходные матрицы: ";
    for (int i = 0; i < N * 2 - 1; ++i) {
        switch (i % 4) {
        case 0:
            y = i / 4;
            for (x = i / 4; x < N - i / 4; ++x) {
                set_element(matrixA, x, y, 0, 1);
            }
            break;
        case 1:
            x = N - i / 4 - 1;
            for (y = i / 4 + 1; y < N - i / 4; ++y) {
                set_element(matrixA, x, y, 0, 1);
            }
            break;
        case 2:
            y = N - i / 4 - 1;
            for (x = N - i / 4 - 2; x >= i / 4; --x) {
                set_element(matrixA, x, y, 0, 1);
            }
            break;
        case 3:
            x = i / 4;
            for (y = N - i / 4 - 2; y >= i / 4 + 1; --y) {
                set_element(matrixA, x, y, 0, 1);
            }
            break;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) {
                set_element(matrixB, i, j, N + 2, 1);
            }
        }
        else {
            for (int j = N - 1; j >= 0; --j) {
                set_element(matrixB, i, j, N + 2, 1);
            }
        }
    }

    destCoord.X = 0;
    destCoord.Y = N + 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Перестановки первой матрицы: ";

    show_a(matrixA, 0, N + 3);
    show_b(matrixA, N + 1, N + 3);
    show_c(matrixA, (N + 1) * 2, N + 3);
    show_d(matrixA, (N + 1) * 3, N + 3);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Перестановки второй матрицы: ";

    show_a(matrixB, 0, (N + 2) * 2 + 1);
    show_b(matrixB, N + 1, (N + 2) * 2 + 1);
    show_c(matrixB, (N + 1) * 2, (N + 2) * 2 + 1);
    show_d(matrixB, (N + 1) * 3, (N + 2) * 2 + 1);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 3;
    SetConsoleCursorPosition(hStdout, destCoord);

    system("pause");
    system("cls");

    cout << "Исходные матрицы: ";
    print_matrix(matrixA, 0, 1);
    print_matrix(matrixB, N + 1, 1);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 1;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Отсортированные матрицы: ";
    quicksort(matrixA, N * N - 1, 0);
    quicksort(matrixB, N * N - 1, 0);
    int size = N * N - 1;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (*(matrixA + j) > *(matrixA + j + 1)) {
                int temp = **(matrixA + j);
                **(matrixA + j) = **(matrixA + j + 1);
                **(matrixA + j + 1) = temp;
            }
        }
    }
    print_matrix(matrixA, 0, (N + 2) * 1 + 1);
    print_matrix(matrixB, N + 1, (N + 2) * 1 + 1);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    system("pause");
    system("cls");

    float matrixD[N][N];
    float matrixF[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrixD[i][j] = static_cast<float>(matrixA[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrixF[i][j] = static_cast<float>(matrixB[i][j]);
        }
    }
    cout << "Модификация всех элементов матрицы" << endl;
    cout << "Введите число: ";
    int number;
    cin >> number;

    char operation;
    do {
        cout << "Введите знак операции (+, -, *, /): ";
        cin >> operation;
        
    } while (operation != '+' && operation != '-' && operation != '*' && operation != '/');

    system("cls");
    cout << "Исходные матрицы: ";
    print_matrix(matrixA, 0, 1);
    print_matrix(matrixB, N + 1, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            switch (operation) {
            case '+':
                *(*(matrixA + i) + j) += number;
                *(*(matrixB + i) + j) += number;
                break;
            case '-':
                *(*(matrixA + i) + j) -= number;
                *(*(matrixB + i) + j) -= number;
                break;
            case '*':
                *(*(matrixA + i) + j) *= number;
                *(*(matrixB + i) + j) *= number;
                break;
            case '/':

                if (number == 0) {
                    *(*(matrixD + i) + j) /= number;
                    *(*(matrixF + i) + j) /= number;
                }
                else {
                    *(*(matrixA + i) + j) /= number;
                    *(*(matrixB + i) + j) /= number;
                }
                
                break;
            }
        }
    }

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 1;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Результат: ";
    if (number == 0 && operation == '/') {
        print_float_matrix(matrixD, 0, (N + 2) * 1 + 1);
        print_float_matrix(matrixF, N + 1, (N + 2) * 1 + 1);
    }
    else {
        print_matrix(matrixA, 0, (N + 2) * 1 + 1);
        print_matrix(matrixB, N + 1, (N + 2) * 1 + 1);

    }
   

    cout << endl;
    system("pause");
    system("cls");

    cout << "Индивидуальное домашнее задание №10" << endl;
    cout << "Матрица 3x3 со случайными числами от -30 до 30: " << endl;

    int matrixC[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            *(*(matrixC + i) + j) = rand() % 61 - 30;
            cout << *(*(matrixC + i) + j) << '\t';
        }
        cout << endl;
    }


    int a = *(*(matrixC + 0) + 0) * *(*(matrixC + 1) + 1) * *(*(matrixC + 2) + 2);
    int b = *(*(matrixC + 0) + 1) * *(*(matrixC + 1) + 2) * *(*(matrixC + 2) + 0);
    int c = *(*(matrixC + 0) + 2) * *(*(matrixC + 1) + 0) * *(*(matrixC + 2) + 1);
    int d = *(*(matrixC + 0) + 2) * *(*(matrixC + 1) + 1) * *(*(matrixC + 2) + 0);
    int e = *(*(matrixC + 0) + 0) * *(*(matrixC + 1) + 2) * *(*(matrixC + 2) + 1);
    int f = *(*(matrixC + 0) + 1) * *(*(matrixC + 1) + 0) * *(*(matrixC + 2) + 2);
    int det = a + b + c - (d + e + f);
    cout << "Вычисление определителя матрицы..." << endl;
    Sleep(50);
    cout << "Произведение элементов главной диагонали: " << a << endl;
    Sleep(50);
    cout << "Произведение элементов первого треугольника параллельного главной диагонали: " << b << endl;
    Sleep(50);
    cout << "Произведение элементов второго треугольника параллельного главной диагонали: " << c << endl;
    Sleep(50);
    cout << "Произведение элементов побочной диагонали: " << d << endl;
    Sleep(50);
    cout << "Произведение элементов первого треугольника параллельного побочной диагонали: " << e << endl;
    Sleep(50);
    cout << "Произведение элементов второго треугольника параллельного побочной диагонали: " << f << endl;
    Sleep(50);
    cout << "Вычисленный определитель: " << det << endl;
    return 0;
}