#include <cstdio>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <locale.h>
#include <math.h>
using namespace std;
///функция с явно заданными параметрами
void getName(const char* name = "Алексей", const char* adress = "Пушкина 12", int age = 20) {
    cout << name << "\n" << adress << "\n" << age;
}

float muss(int k, ...)
//явный параметр k задает количество чисел
{
    int* p = &k;//настроили указатель на параметр k
    int s = 0, i = 0, max;
    int* arr = new int[k];
    for (; k != 0; k--) {
        arr[i] = *(++p);
        i++;
    }
    max = arr[0];
    for (k = 0; k < i; k++) {
        if ((k + 1) % 2 != 0) {
            if (arr[k] > max) {
                max = arr[k];
            }
        }
    }
    return max;
}

/// Перегрузка функций
int* arraySort(int* arr, int length) {
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

float* arraySort(float* arr, int length) {
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
///шаблон функции
template< class T >
T* GetAverage(T* arr, int length)
{
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}


typedef float(*fptr)(float);//тип-указатель на функцию уравнения

/*решение уравнения методом половинного деления, уравнение передается с помощью указателя на функцию */
float root(fptr f, float a, float b, float e)
{
    float x;
    do
    {
        x = (a + b) / 2;			//находим середину отрезка
        if ((*f)(a) * f(x) < 0)		//выбираем отрезок
            b = x;
        else a = x;
    } while ((*f)(x) > e && fabs(a - b) > e);
    return x;
}

//функция, для которой ищется корень
float testf(float x)
{
    return 0.25 * x * x * x + x - 1.2502;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    getName();
    cout << "\n";
    getName("Иван");
    cout << "\n";
    cout << "Максимальный элемент: " << muss(9, 1, 2, 3, 4, 5, 6, 7, 8, 0);
    int a[6] = { 1,2,5,4,3,7 };
    int* b = arraySort(a, 6);
    cout << "\n";
    cout << "Отсартированный массив(Перегрузка функций): ";
    for (int i = 0; i < 6; i++) {
        cout << b[i] << "\t";
    }
    cout << "\n";
    float a1[6] = { 1.1,1.2,1.2,1.3,2.5,3.4 };
    float* b1 = arraySort(a1, 6);
    cout << "Отсартированный массив(Перегрузка функций): ";
    for (int i = 0; i < 6; i++) {
        cout << b1[i] << "\t";
    }
    cout << "\n";

    float* b2 = GetAverage(a1, 6);
    cout << "Отсартированный массив(шаблон функции): ";
    for (int i = 0; i < 6; i++) {
        cout << b2[i] << "\t";
    }
    cout << "\n";

    /*в функцию root передается указатель на функцию, координаты отрезка и точность */
    float res = root(testf, 0, 2, 1.0001);
    cout << "\nX = " << res;


    return 0;
}