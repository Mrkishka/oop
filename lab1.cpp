#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для генерации динамического массива случайных чисел
int *genRandArray(int size, int maxValue)
{
    // Выделяем память для массива размером size + 1 (первый элемент — это размер массива)
    int *arr = new int[size + 1];

    // Записываем размер массива в первый элемент
    arr[0] = size;

    // Заполняем массив случайными числами
    for (int i = 1; i <= size; i++)
    {
        arr[i] = rand() % (maxValue + 1);
    }

    return arr;
}

// Функция для вывода массива на экран
void print(int *arr)
{
    int size = arr[0]; // Читаем размер массива из первого элемента
    cout << "Размер массива: " << size << endl;
    cout << "Элементы массива: ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел

    int size = rand() % 10; // Генерация случайного размера массива
    int maxValue = 100;     // Максимальное значение для случайных чисел

    // Генерация массива и его вывод
    int *arr = genRandArray(size, maxValue);
    print(arr);

    // Очистка выделенной памяти
    delete[] arr;

    return 0;
}