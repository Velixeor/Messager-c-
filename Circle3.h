#pragma once
#include"MsgObj.h"
#include"Msg.h"
#include"EmptyMsg.h"
#include"MsgTime.h"
using namespace std;

class Circle3 :public MsgingObject
{
public:
	Circle3(int id, char Color);

	shared_ptr<Msg> SandMsg();
	void HandleMsg(shared_ptr<Msg>);

	shared_ptr<Msg> Run(Event event, RenderWindow& window, shared_ptr<Msg> msg);
private:
	char Color;
	CircleShape shape;
	float time;
};


