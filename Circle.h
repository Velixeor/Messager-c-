#pragma once
#include"MsgObj.h"
#include"Msg.h"
#include"EmptyMsg.h"
#include"MsgColor.h"
using namespace std;

class Circle:public MsgingObject
{
public:
	Circle(int id, char Color);
	
	shared_ptr<Msg> SandMsg();
	shared_ptr<Msg> SandMsgIGNORE();
	void HandleMsg(shared_ptr<Msg>);

	shared_ptr<Msg> Run(Event event, RenderWindow& window, shared_ptr<Msg> msg);
private:
	char Color;
	CircleShape shape;
};


