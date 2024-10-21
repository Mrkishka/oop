#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Figure
{
protected:
    int x, y; // Координаты центра фигуры
public:
    // Конструктор по умолчанию
    Figure() : x(rand() % 101), y(rand() % 101) {}

    // Конструктор с параметрами
    Figure(int x, int y) : x(x), y(y) {}

    // Ввод координат
    void input()
    {
        cout << "Введите координаты (x, y): ";
        cin >> x >> y;
    }

    // Вывод координат
    void display() const
    {
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
    }

    // Деструктор
    virtual ~Figure() {}
};

class Line : public Figure
{
protected:
    int x2, y2;
    double length;

public:
    // Конструктор по умолчанию
    Line() : Figure(), x2(rand() % 101), y2(rand() % 101)
    {
        computeLength();
    }

    // Конструктор с параметрами
    Line(int x1, int y1, int x2, int y2) : Figure(x1, y1), x2(x2), y2(y2)
    {
        computeLength();
    }

    // Метод для вычисления длины линии
    void computeLength()
    {
        length = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }

    // Вывод длины линии
    void displayLength() const
    {
        cout << "Длина линии: " << length << endl;
    }

    // Ввод данных
    void input()
    {
        Figure::input();
        cout << "Введите координаты конца линии (x2, y2): ";
        cin >> x2 >> y2;
        computeLength();
    }

    // Вывод координат
    void display() const
    {
        Figure::display();
        cout << "Конец линии: (" << x2 << ", " << y2 << ")" << endl;
    }
};

class Circle : public Figure
{
protected:
    int radius;

public:
    // Конструктор по умолчанию
    Circle() : Figure(), radius(rand() % 50 + 1) {}

    // Конструктор с параметрами
    Circle(int x, int y, int r) : Figure(x, y), radius(r) {}

    // Ввод данных
    void input()
    {
        Figure::input();
        cout << "Введите радиус: ";
        cin >> radius;
    }

    // Вывод данных
    void display() const
    {
        Figure::display();
        cout << "Радиус: " << radius << endl;
    }
};

class Square : public Line
{
public:
    // Конструктор по умолчанию
    Square() : Line() {}

    // Конструктор с параметрами
    Square(int x1, int y1, int side) : Line(x1, y1, x1 + side, y1) {}

    // Вычисление периметра
    int perimeter() const
    {
        return 4 * (x2 - x);
    }

    // Вычисление площади
    int area() const
    {
        return pow(x2 - x, 2);
    }

    // Вывод периметра и площади
    void displayMetrics() const
    {
        cout << "Периметр квадрата: " << perimeter() << endl;
        cout << "Площадь квадрата: " << area() << endl;
    }

    // Ввод данных с клавиатуры
    void manualInput()
    {
        Line::input();
    }

    // Ввод случайных данных
    void randomInput()
    {
        x = rand() % 101;
        y = rand() % 101;
        int side = rand() % 50 + 1;
        x2 = x + side;
        y2 = y;
        computeLength();
    }

    // Метод для выбора способа ввода данных
    void inputChoice()
    {
        int choice;
        cout << "Выберите способ ввода данных для квадрата (1 - вручную, 2 - случайно): ";
        cin >> choice;
        if (choice == 1)
        {
            manualInput();
        }
        else
        {
            randomInput();
        }
    }
};

class Rectangle : public Square
{
private:
    int height;

public:
    // Конструктор по умолчанию
    Rectangle() : Square(), height(rand() % 50 + 1) {}

    // Конструктор с параметрами
    Rectangle(int x1, int y1, int w, int h) : Square(x1, y1, w), height(h) {}

    // Вычисление периметра
    int perimeter() const
    {
        return 2 * (x2 - x + height);
    }

    // Вычисление площади
    int area() const
    {
        return (x2 - x) * height;
    }

    // Вывод периметра и площади
    void displayMetrics() const
    {
        cout << "Периметр прямоугольника: " << perimeter() << endl;
        cout << "Площадь прямоугольника: " << area() << endl;
    }

    // Ввод данных вручную
    void manualInput()
    {
        Square::input();
        cout << "Введите высоту: ";
        cin >> height;
    }

    // Ввод случайных данных
    void randomInput()
    {
        Square::randomInput();
        height = rand() % 50 + 1;
    }

    // Метод для выбора способа ввода данных
    void inputChoice()
    {
        int choice;
        cout << "Выберите способ ввода данных для прямоугольника (1 - вручную, 2 - случайно): ";
        cin >> choice;
        if (choice == 1)
        {
            manualInput();
        }
        else
        {
            randomInput();
        }
    }

    // Вывод данных
    void display() const
    {
        Square::display();
        cout << "Высота: " << height << endl;
    }
};

int main()
{
    srand(time(0));

    // Создание объектов классов
    Line line1;
    Circle circle1;
    Square square1;
    Rectangle rectangle1;

    // Ввод данных с выбором
    square1.inputChoice();
    rectangle1.inputChoice();

    // Вывод данных для линии и круга
    cout << "\nЛиния:\n";
    line1.display();
    line1.displayLength();

    cout << "\nКруг:\n";
    circle1.display();

    // Вывод данных для квадрата и прямоугольника
    cout << "\nКвадрат:\n";
    square1.display();
    square1.displayMetrics();

    cout << "\nПрямоугольник:\n";
    rectangle1.display();
    rectangle1.displayMetrics();

    // Динамический массив объектов класса Прямоугольник
    Rectangle *rectangles = new Rectangle[3]{
        Rectangle(0, 0, 4, 6),
        Rectangle(1, 1, 5, 7),
        Rectangle(2, 2, 8, 10)};

    // Вывод периметров и площадей всех прямоугольников
    cout << "\nДинамический массив прямоугольников:\n";
    for (int i = 0; i < 3; ++i)
    {
        rectangles[i].display();
        rectangles[i].displayMetrics();
    }

    // Удаление динамического массива
    delete[] rectangles;

    return 0;
}
