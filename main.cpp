#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"Circle.h"
#include"Circle2.h"
#include"Circle3.h"
#include"Messenger.h"
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "test");
   
    Messenger Operator;
    MsgingObject* a=new Circle(45,'r');
    MsgingObject* a1 = new Circle2(44, 'r');
    MsgingObject* a2 = new Circle3(46, 'r');
    Operator.Subscribe(a);
    Operator.Subscribe(a1);
    Operator.Subscribe(a2);
    Operator.Run(window);
   

    return 0;
}