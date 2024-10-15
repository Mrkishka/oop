#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Figure
{
protected:
    double x, y; // Координаты фигуры
public:
    Figure()
    { // Конструктор по умолчанию
        x = rand() % 100;
        y = rand() % 100;
    }

    Figure(double x, double y)
    { // Конструктор с параметрами
        this->x = x;
        this->y = y;
    }

    void move(double dx, double dy)
    { // Метод перемещения
        x += dx;
        y += dy;
    }

    virtual void input()
    { // Ввод данных
        cout << "Введите координаты (x, y): ";
        cin >> x >> y;
    }

    virtual void display() const
    { // Вывод данных
        cout << "Координаты: (" << x << ", " << y << ")\n";
    }

    virtual ~Figure() {} // Виртуальный деструктор
};

class Line : public Figure
{
private:
    double x2, y2; // Координаты второго конца линии
    double length; // Длина линии
public:
    Line() : Figure()
    { // Конструктор по умолчанию
        x2 = rand() % 100;
        y2 = rand() % 100;
        length = calculateLength();
    }

    Line(double x1, double y1, double x2, double y2) : Figure(x1, y1), x2(x2), y2(y2)
    {
        length = calculateLength();
    }

    double calculateLength()
    {
        return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    }

    void input() override
    {
        Figure::input();
        cout << "Введите координаты второго конца линии (x2, y2): ";
        cin >> x2 >> y2;
        length = calculateLength();
    }

    void display() const override
    {
        Figure::display();
        cout << "Координаты второго конца: (" << x2 << ", " << y2 << ")\n";
        cout << "Длина линии: " << length << endl;
    }
};

class Circle : public Figure
{
protected:
    double radius;

public:
    Circle() : Figure()
    {
        radius = rand() % 100;
    }

    Circle(double x, double y, double radius) : Figure(x, y), radius(radius) {}

    void input() override
    {
        Figure::input();
        cout << "Введите радиус: ";
        cin >> radius;
    }

    void display() const override
    {
        Figure::display();
        cout << "Радиус: " << radius << endl;
    }
};

class Ellipse : public Circle
{
protected:
    double minorRadius; // Малый радиус эллипса
public:
    Ellipse() : Circle()
    {
        minorRadius = rand() % 50;
    }

    Ellipse(double x, double y, double majorRadius, double minorRadius) : Circle(x, y, majorRadius), minorRadius(minorRadius) {}

    void input() override
    {
        Circle::input();
        cout << "Введите малый радиус: ";
        cin >> minorRadius;
    }

    void display() const override
    {
        Circle::display();
        cout << "Малый радиус: " << minorRadius << endl;
    }
};

class Square : public Figure
{
protected:
    double side;

public:
    Square() : Figure()
    {
        side = rand() % 50;
    }

    Square(double x, double y, double side) : Figure(x, y), side(side) {}

    void input() override
    {
        Figure::input();
        cout << "Введите длину стороны: ";
        cin >> side;
    }

    double perimeter() const
    {
        return 4 * side;
    }

    double area() const
    {
        return side * side;
    }

    void display() const override
    {
        Figure::display();
        cout << "Сторона квадрата: " << side << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
    }
};

class Rectangle : public Square
{
protected:
    double width;

public:
    Rectangle() : Square()
    {
        width = rand() % 50;
    }

    Rectangle(double x, double y, double length, double width) : Square(x, y, length), width(width) {}

    void input() override
    {
        Square::input();
        cout << "Введите ширину: ";
        cin >> width;
    }

    double perimeter() const
    {
        return 2 * (side + width);
    }

    double area() const
    {
        return side * width;
    }

    void display() const override
    {
        Figure::display();
        cout << "Длина: " << side << ", Ширина: " << width << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
    }
};

int main()
{
    srand(time(0));

    Line line1;
    line1.display();

    Square square1(0, 0, 5);
    square1.display();

    Rectangle rectArray[3] = {
        Rectangle(1, 1, 5, 3),
        Rectangle(2, 2, 6, 4),
        Rectangle(3, 3, 7, 5)};

    for (int i = 0; i < 3; i++)
    {
        rectArray[i].display();
    }

    return 0;
}
