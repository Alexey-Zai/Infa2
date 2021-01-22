#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <clocale>
using namespace std;
 void workmatrix(int  mass[5][5], int rows, int cols)
{
    bool flag = false;
    int tempMax = NULL, tempMin = NULL, indexMaxI = 0, indexMaxJ = 0, indexMinI = 0, indexMinJ = 0;
    for (int i = 0; i < rows; i++) {
        tempMax = mass[i][0];
        for (int j = 0; j < cols; j++) {
            if (mass[i][j] > tempMax) {///найдем максимальный элемент в строке
                tempMax = mass[i][j];
                indexMaxI = i;
                indexMaxJ = j;
            }
        }

        ///проверим является ли он минимальными в столбце
        tempMin = mass[0][indexMaxJ];
        for (int k = 0; k < rows; k++) {
            if (mass[k][indexMaxJ] < tempMin) {
                tempMin = mass[k][indexMaxJ];
                indexMinI = k;

            }
        }
        if ((tempMin = tempMax) && (indexMinI == indexMaxI)) {
            cout << "\n" << "Седловая точка :";
            cout << "[" << indexMaxI << "]" << "[" << indexMaxJ << "] = " << mass[indexMaxI][indexMaxJ] << "\t";
            flag = true;
        }
    }

    tempMax = NULL; tempMin = NULL; indexMaxI = 0; indexMaxJ = 0; indexMinI = 0; indexMinJ = 0;
    for (int i = 0; i < rows; i++) {
        tempMax = mass[i][0];
        for (int j = 0; j < cols; j++) {
            if (mass[i][j] < tempMin) {///найдем минимальный элемент в строке
                tempMax = mass[i][j];
                indexMinI = i;
                indexMinJ = j;
            }
        }
        ///проверим является ли он максимальным в столбце
        tempMax = mass[0][indexMinJ];
        for (int k = 0; k < rows; k++) {
            if (mass[k][indexMinJ] > tempMax) {
                tempMax = mass[k][indexMinJ];
                indexMaxI = k;

            }
        }
        if ((tempMin = tempMax) && (indexMinI == indexMaxI)) {
            cout << "\n" << "Седловая точка :";
            cout << "[" << indexMaxI << "]" << "[" << indexMaxJ << "] = " << mass[indexMaxI][indexMaxJ] << "\t";
            flag = true;
        }
    }
    if (!flag) { cout << "\n" << "Cедловых точек нет"; }
}

void main()
{
    srand(time(0));
    setlocale(LC_ALL, "Rus");
    const int n = 5;
    const int k = 5;
    int matrix[n][k]{ {0,0,0,0,6},
                        {0,0,0,0,7},
                        {1,2,3,4,5},
                        {0,0,0,0,8},
                        {0,0,0,0,9}
    };

    workmatrix(matrix, n, k);
}
