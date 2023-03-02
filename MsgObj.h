#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Messenger;
class Msg;
//A purely virtual class from which all objects that participate in messaging are inherited
class MsgingObject
{
public:
	
	//Process the message
	virtual void HandleMsg(shared_ptr<Msg>) = 0;
	//Send a message
	virtual shared_ptr<Msg> SandMsg() = 0;
	
	virtual  shared_ptr<Msg> Run(Event event, RenderWindow& window, shared_ptr<Msg>msg) = 0;
    protected:
	int id;
};

