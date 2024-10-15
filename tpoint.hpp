#ifndef TPOINT_H
#define TPOINT_H

#include <cstdlib> // для функции rand()
#include <ctime>   // для функции time()

class tPoint
{
private:
    int x, y;                      // Координаты точки
    int screenWidth, screenHeight; // Размер экрана
    sf::Color color;

public:
    // Конструктор по умолчанию
    tPoint() : x(0), y(0), screenWidth(800), screenHeight(600) {}

    // Конструктор с параметрами
    tPoint(int x, int y, int screenWidth, int screenHeight)
        : x(x), y(y), screenWidth(screenWidth), screenHeight(screenHeight)
    {
        // Генерируем случайный цвет один раз при создании точки
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }
    // Геттер для цвета
    sf::Color getColor() const
    {
        return color;
    }
    // Получить координаты
    int
    getX() const
    {
        return x;
    }
    int getY() const { return y; }
    // Установить координаты
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void moveStraight(int &dx, int &dy, float speed)
    {
        // Изменение координат с учетом скорости
        x += dx * speed;
        y += dy * speed;

        // Проверка на отражение от стенок
        if (x <= 0 || x >= screenWidth)
        {
            dx = -dx; // Меняем направление по оси X
            if (x < 0)
                x = 0; // Фиксируем точку на границе
            if (x > screenWidth)
                x = screenWidth;
        }

        if (y <= 0 || y >= screenHeight)
        {
            dy = -dy; // Меняем направление по оси Y
            if (y < 0)
                y = 0; // Фиксируем точку на границе
            if (y > screenHeight)
                y = screenHeight;
        }
    }

    void moveRandom(float speed)
    {
        static int dx = rand() % 21 - 10; // Случайное начальное движение по X
        static int dy = rand() % 21 - 10; // Случайное начальное движение по Y

        moveStraight(dx, dy, speed); // Используем уже исправленный метод
    }

#endif // TPOINT_H
};