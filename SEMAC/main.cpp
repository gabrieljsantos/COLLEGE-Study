#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
 struct Body {
        float x;
        float y;
        float vx;
        float vy;
        float ax;
        float ay;
        float m;
    };
int main()
{
    int sizeX = 800;
    int sizeY = 600;

    Body A = {400,400,-3,0,0,0,100};
    Body B = {400,100,+3,0,0,0,100};

    float G = 100;
    float F;


    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "Meu Primeiro");
    window.setFramerateLimit(60);

    sf::CircleShape A_circle(20.f);
    sf::CircleShape B_circle(20.f);
    A_circle.setFillColor(sf::Color::Cyan);
    B_circle.setPosition(A.x, A.y);
    A_circle.setFillColor(sf::Color::Blue);
    B_circle.setPosition(B.x, B.y);


    float dx,dy,dH, dt;
    dt = 0.1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dx = A.x - B.x;
        dy = A.y - B.y;
        dH = sqrt((dx*dx)+(dy*dy));
        F = (G * A.m * B.m) / (dH * dH);

        A.ax = (dx / dH) * (-F / A.m);
        A.vx += A.ax * dt;
        A.x  += A.vx * dt;


        A.ay = (dy / dH) * (-F / A.m);
        A.vy += A.ay * dt;
        A.y  += A.vy * dt;

        B.ax = (dx / dH) * (F / B.m);
        B.vx += B.ax * dt;
        B.x  += B.vx * dt;


        B.ay = (dy / dH) * (F / B.m);
        B.vy += B.ay * dt;
        B.y  += B.vy * dt;

        std::cout << "A.y = " << A.y << " A.vy = " << A.vy << " A.ay = " << A.ay << " F = " << F << std::endl;

        window.clear(sf::Color::Black);
        A_circle.setPosition(A.x, A.y);
        B_circle.setPosition(B.x, B.y);

        window.draw(A_circle);
        window.draw(B_circle);
        window.display();
    }

    return 0;
}
