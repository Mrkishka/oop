#include <SFML/Graphics.hpp>
#include "tpoint.hpp"
#include <vector>

int main()
{
    srand(static_cast<unsigned>(time(0)));

    const int screenWidth = 800;
    const int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Straight Moving Points");

    std::vector<tPoint> points;
    std::vector<int> dx(100);
    std::vector<int> dy(100);

    for (int i = 0; i < 100; ++i)
    {

        points.push_back(tPoint(rand() % screenWidth, rand() % screenHeight, screenWidth, screenHeight));
        dx[i] = rand() % 3 - 1;
        dy[i] = rand() % 3 - 1;

        if (dx[i] == 0 && dy[i] == 0)
        {
            dx[i] = 1;
        }
    }

    float speed = 1.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < points.size(); ++i)
        {
            points[i].moveStraight(dx[i], dy[i], speed);

            points[i].moveRandom(speed);
            sf::CircleShape shape(3);
            shape.setPosition(points[i].getX(), points[i].getY());
            shape.setFillColor(points[i].getColor());

            window.draw(shape);
        }

        window.display();
    }

    return 0;
}
