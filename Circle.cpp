#pragma once
#include"Circle.h"

Circle::Circle(int id, char Color)
{
	
	this->id = id;
	this->Color = Color;
}

shared_ptr<Msg> Circle::Run(Event event, RenderWindow& window, shared_ptr<Msg> msg) {
	int u=0;
	if ((Keyboard::isKeyPressed(Keyboard::W))) {
		Color = 'r';
		u = 1;
	}
	if ((Keyboard::isKeyPressed(Keyboard::S))) {
		Color = 'w';
		u = 1;
	}
	if (Color == 'w') {
		shape.setRadius(20);
		shape.setPosition(20, 20);
		shape.setFillColor(sf::Color::White);
	}

	if (Color == 'r') {
		shape.setRadius(20);
		shape.setPosition(20, 20);
		shape.setFillColor(sf::Color::Red);
	}
	if (Color == 'g') {
		shape.setRadius(20);
		shape.setPosition(20, 20);
		shape.setFillColor(sf::Color::Green);
	}
	window.draw(shape);
	if(u ==1)
	return SandMsg();
	return SandMsgIGNORE();
}
shared_ptr<Msg>Circle::SandMsgIGNORE() {
	
	shared_ptr<Msg> msg= make_shared<EmptyMsg>();


	return msg;
}

shared_ptr<Msg> Circle::SandMsg() {
	
	shared_ptr<Msg> msg= make_shared<MsgColor>(44,Color,id);
	

	return msg;
}
void Circle::HandleMsg(shared_ptr<Msg> msg) {
	

}