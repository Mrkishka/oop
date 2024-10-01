#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
using namespace std;

class Matrix
{
public:
    // Выбор метода для каждого варианта
    void toSpiralOrDiagonal(int **data, int size, int *D, char method)
    {
        switch (method)
        {
        case 'a':
            toRightDiagonals(data, size, D);
            break;
        case 'b':
            toLeftDiagonals(data, size, D);
            break;
        case 'c':
            toSpiralCenter(data, size, D);
            break;
        case 'd':
            toSpiralTopLeft(data, size, D);
            break;
        default:
            cout << "Invalid method" << endl;
        }
    }

    // Вывод элементов массива D
    void printArray(int *D, int size, const string &message)
    {
        cout << message;
        for (int i = 0; i < size; i++)
        {
            cout << D[i] << " ";
        }
        cout << endl;
    }

private:
    // a) Заполнение по правым диагоналям, начиная с правого верхнего элемента
    void toRightDiagonals(int **data, int size, int *D)
    {
        int index = 0;
        for (int diag = 0; diag < 2 * size - 1; diag++)
        {
            for (int x = 0; x < size; x++)
            {
                int y = diag - x;
                if (y >= 0 && y < size)
                {
                    D[index++] = data[x][y];
                }
            }
        }
    }

    // b) Заполнение по левым диагоналям, начиная с левого верхнего элемента
    void toLeftDiagonals(int **data, int size, int *D)
    {
        int index = 0;
        for (int diag = 0; diag < 2 * size - 1; diag++)
        {
            for (int x = 0; x < size; x++)
            {
                int y = diag - (size - 1 - x);
                if (y >= 0 && y < size)
                {
                    D[index++] = data[x][y];
                }
            }
        }
    }

    // c) Заполнение по спирали, начиная с центрального элемента
    void toSpiralCenter(int **data, int size, int *D)
    {
        int x = (size - 1) / 2;
        int y = (size - 1) / 2;
        int index = 0;
        D[index++] = data[x][y];

        int directions[4][2] = {
            {0, 1},  // вправо
            {1, 0},  // вниз
            {0, -1}, // влево
            {-1, 0}  // вверх
        };

        for (int layer = 1; layer < size; layer += 2)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                for (int step = 0; step < (dir < 2 ? layer : layer + 1); step++)
                {
                    x += directions[dir][0];
                    y += directions[dir][1];

                    if (x >= 0 && x < size && y >= 0 && y < size)
                    {
                        D[index++] = data[x][y];
                    }
                }
            }
        }
    }

    // d) Заполнение по спирали, начиная с левого верхнего элемента
    void toSpiralTopLeft(int **data, int size, int *D)
    {
        int x = 0, y = 0;
        int index = 0;
        D[index++] = data[x][y];

        int directions[4][2] = {
            {0, 1},  // вправо
            {1, 0},  // вниз
            {0, -1}, // влево
            {-1, 0}  // вверх
        };

        int layer = 0;
        while (index < size * size)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                for (int step = 0; step < (dir % 2 == 0 ? size - layer : size - layer - 1); step++)
                {
                    x += directions[dir][0];
                    y += directions[dir][1];

                    if (x >= 0 && x < size && y >= 0 && y < size)
                    {
                        D[index++] = data[x][y];
                    }
                }
            }
            layer++;
        }
    }
};

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел

    int size;
    cout << "Введите размер матрицы N: ";
    cin >> size;

    // Создание динамической двумерной матрицы размером N×N
    int **matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 100;  // Заполняем случайными числами
            cout << matrix[i][j] << "\t"; // Выводим матрицу
        }
        cout << endl;
    }

    // Создаем одномерный массив D размером N * N
    int *D = new int[size * size];

    Matrix mat;

    // a) Элементы по правым диагоналям
    mat.toSpiralOrDiagonal(matrix, size, D, 'a');
    mat.printArray(D, size * size, "Элементы по правым диагоналям: ");

    // b) Элементы по левым диагоналям
    mat.toSpiralOrDiagonal(matrix, size, D, 'b');
    mat.printArray(D, size * size, "Элементы по левым диагоналям: ");

    // c) Элементы по спирали (с центра)
    mat.toSpiralOrDiagonal(matrix, size, D, 'c');
    mat.printArray(D, size * size, "Элементы по спирали (с центра): ");

    // d) Элементы по спирали (с левого верхнего угла)
    mat.toSpiralOrDiagonal(matrix, size, D, 'd');
    mat.printArray(D, size * size, "Элементы по спирали (с левого верхнего угла): ");

    // Освобождаем память
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] D;

    return 0;
}
