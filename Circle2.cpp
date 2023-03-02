#pragma once
#include"Circle2.h"

Circle2::Circle2(int id, char Color)
{
	this->id = id;
	this->Color = Color;
}

shared_ptr<Msg> Circle2::Run(Event event, RenderWindow& window, shared_ptr<Msg> msg) {
	HandleMsg(msg);
	if (Color == 'r') {
		shape.setRadius(20);
		shape.setPosition(50, 50);
		shape.setFillColor(sf::Color::Green);
	}
	if (Color == 'w') {
		shape.setRadius(20);
		shape.setPosition(50, 50);
		shape.setFillColor(sf::Color::Red);
	}
	window.draw(shape);
	return SandMsg();
}


shared_ptr<Msg> Circle2::SandMsg() {
	shared_ptr<Msg> msg = make_shared<EmptyMsg>();


	return msg;
}
void Circle2::HandleMsg(shared_ptr<Msg> msg) {
	int ID = 0;
	auto P = dynamic_pointer_cast<MsgColor>(msg);
	if (P) {
		for (int i = 0; i < P->GetRecipient().size(); i++)
		{
			if (P->GetIDRecipient(i) == id||P->GetState()==ForCircle)
				ID = 1;

		}
		if ( ID == 1) {

			Color = P->GetColor();
		}
	}

}