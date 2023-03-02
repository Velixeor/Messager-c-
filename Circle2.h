
#pragma once
#include"MsgObj.h"
#include"Msg.h"
#include"EmptyMsg.h"
#include"MsgColor.h"
using namespace std;

class Circle2 :public MsgingObject
{
public:
	Circle2(int id, char Color);

	shared_ptr<Msg> SandMsg();
	void HandleMsg(shared_ptr<Msg>);
	
	shared_ptr<Msg> Run(Event event, RenderWindow& window, shared_ptr<Msg> msg);
private:
	char Color;
	CircleShape shape;
};


