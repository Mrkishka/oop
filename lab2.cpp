#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int>> createMatrix(int N)
{
    vector<vector<int>> matrix(N, vector<int>(N));
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

vector<int> rightDiagonals(const vector<vector<int>> &matrix, int N)
{
    vector<int> D;
    for (int k = 0; k < 2 * N - 1; k++)
    {
        for (int i = 0; i < N; i++)
        {
            int j = N - 1 - k + i;
            if (j >= 0 && j < N)
            {
                D.push_back(matrix[i][j]);
            }
        }
    }
    return D;
}

vector<int> leftDiagonals(const vector<vector<int>> &matrix, int N)
{
    vector<int> D;
    for (int k = 0; k < 2 * N - 1; k++)
    {
        for (int i = 0; i < N; i++)
        {
            int j = k - i;
            if (j >= 0 && j < N)
            {
                D.push_back(matrix[i][j]);
            }
        }
    }
    return D;
}

vector<int> spiralFromCenter(const vector<vector<int>> &matrix, int N)
{
    vector<int> D;

    int x = N / 2, y = N / 2;  // Центр матрицы
    D.push_back(matrix[x][y]); // Добавляем центральный элемент

    int step = 1; // Длина шага для движения (увеличивается после двух направлений)
    while (step < N)
    {
        for (int i = 0; i < step && x + 1 < N; i++)
        {
            x++;
            D.push_back(matrix[y][x]);
        }

        for (int i = 0; i < step && y + 1 < N; i++)
        {
            y++;
            D.push_back(matrix[y][x]);
        }

        step++;

        for (int i = 0; i < step && x - 1 >= 0; i++)
        {
            x--;
            D.push_back(matrix[y][x]);
        }

        for (int i = 0; i < step && y - 1 >= 0; i++)
        {
            y--;
            D.push_back(matrix[y][x]);
        }

        step++;
    }

    if (N % 2 == 0)
    {
        for (int i = 0; i < step - 1 && x + 1 < N; i++)
        {
            x++;
            D.push_back(matrix[y][x]);
        }
    }

    return D;
}

vector<int> spiralFromTopLeft(const vector<vector<int>> &matrix, int N)
{
    vector<int> D;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            D.push_back(matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            D.push_back(matrix[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                D.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                D.push_back(matrix[i][left]);
            left++;
        }
    }
    return D;
}

int main()
{
    int N;
    cout << "Введите размер матрицы N: ";
    cin >> N;

    vector<vector<int>> matrix = createMatrix(N);

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);
    vector<int> D = rightDiagonals(matrix, N);
    cout << "\nЭлементы по правым диагоналям: ";
    for (int elem : D)
        cout << elem << " ";

    D = leftDiagonals(matrix, N);
    cout << "\nЭлементы по левым диагоналям: ";
    for (int elem : D)
        cout << elem << " ";
    D = spiralFromCenter(matrix, N);
    cout << "\nЭлементы по спирали (с центра): ";
    for (int elem : D)
        cout << elem << " ";
    D = spiralFromTopLeft(matrix, N);
    cout << "\nЭлементы по спирали (с левого верхнего угла): ";
    for (int elem : D)
        cout << elem << " ";
    cout << "\n";
    return 0;
}
