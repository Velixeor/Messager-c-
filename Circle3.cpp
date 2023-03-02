#pragma once
#include"Circle3.h"
Circle3::Circle3(int id, char Color)
{
	this->id = id;
	this->Color = Color;
	time = 0;
}

shared_ptr<Msg> Circle3::Run(Event event, RenderWindow& window, shared_ptr<Msg> msg) {
	HandleMsg(msg);
	if (time > 5) {
		shape.setRadius(20);
		shape.setPosition(150, 150);
		shape.setFillColor(sf::Color::Blue);
	}
	if (time <  5) {
		shape.setRadius(20);
		shape.setPosition(90, 90);
		shape.setFillColor(sf::Color::Cyan);
	}
	window.draw(shape);
	return SandMsg();
}


shared_ptr<Msg> Circle3::SandMsg() {
	shared_ptr<Msg> msg = make_shared<EmptyMsg>();


	return msg;
}
void Circle3::HandleMsg(shared_ptr<Msg>msg) {
	auto P= dynamic_pointer_cast<MsgTime>(msg) ;
	if (P) {
		if (P->GetTime() > 0) {
			time = P->GetTime();
		}
	}
}