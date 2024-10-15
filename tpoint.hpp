#ifndef TPOINT_H
#define TPOINT_H

#include <cstdlib>
#include <ctime>

class tPoint
{
private:
    int x, y;
    int screenWidth, screenHeight;
    sf::Color color;

public:
    tPoint() : x(0), y(0), screenWidth(800), screenHeight(600) {}

    tPoint(int x, int y, int screenWidth, int screenHeight)
        : x(x), y(y), screenWidth(screenWidth), screenHeight(screenHeight)
    {
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }
    sf::Color getColor() const
    {
        return color;
    }
    int
    getX() const
    {
        return x;
    }
    int getY() const { return y; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void moveStraight(int &dx, int &dy, float speed)
    {
        x += dx * speed;
        y += dy * speed;

        if (x <= 0 || x >= screenWidth)
        {
            dx = -dx;
            if (x < 0)
                x = 0;
            if (x > screenWidth)
                x = screenWidth;
        }

        if (y <= 0 || y >= screenHeight)
        {
            dy = -dy;
            if (y < 0)
                y = 0;
            if (y > screenHeight)
                y = screenHeight;
        }
    }

    void moveRandom(float speed)
    {
        static int dx = rand() % 21 - 10;
        static int dy = rand() % 21 - 10;

        moveStraight(dx, dy, speed);
    }

#endif // TPOINT_H
};