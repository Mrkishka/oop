#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()

// Функция для генерации двумерного динамического массива
int **genRandMatrix(int size, int *rowSizes, int maxValue)
{
    int **matrix = new int *[size]; // создаём массив указателей для строк

    // Заполняем каждую строку случайными числами
    for (int i = 0; i < size; ++i)
    {
        rowSizes[i] = rand() % 10 + 1;    // случайный размер строки от 1 до 10
        matrix[i] = new int[rowSizes[i]]; // создаём строку
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            matrix[i][j] = rand() % maxValue; // случайные числа от 0 до maxValue
        }
    }

    return matrix;
}

// Функция для вывода матрицы на экран с информацией о количестве элементов
void printMatrix(int **matrix, int size, int *rowSizes)
{
    int totalElements = 0; // для подсчёта общего количества элементов в матрице
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Row " << i + 1 << " (Elements: " << rowSizes[i] << "): ";
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
        totalElements += rowSizes[i]; // суммируем количество элементов в строке
    }
    std::cout << "Total elements in matrix: " << totalElements << std::endl;
}

// Очистка памяти
void freeMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i]; // освобождаем каждую строку
    }
    delete[] matrix; // освобождаем массив указателей
}

int main()
{
    srand(time(0));             // инициализируем генератор случайных чисел
    int size = rand() % 10 + 1; // случайное количество строк от 1 до 10
    int maxValue = 100;

    int *rowSizes = new int[size]; // массив для хранения размеров каждой строки

    // Генерация матрицы
    int **matrix = genRandMatrix(size, rowSizes, maxValue);

    // Вывод матрицы и количества элементов
    printMatrix(matrix, size, rowSizes);

    // Очистка памяти
    freeMatrix(matrix, size);
    delete[] rowSizes; // освобождаем память, выделенную для размеров строк

    return 0;
}
