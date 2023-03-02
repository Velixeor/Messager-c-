#pragma once
#include"MsgObj.h"
#include"MsgTime.h"

class Msg;
class MsgingObject;
//Message handler
class Messenger
{
public:
	Messenger();
	~Messenger();
	//Method of adding an object to the vector of all participants in the interaction of messages
	void Subscribe(MsgingObject* obj);
	//Launch Message handler
	void Run(RenderWindow& windows);
	//Returning the first pointer message from the queue
	shared_ptr<Msg>  GetMsg();
	//Writing a pointer message to the end of the queue
	void SetMsg(shared_ptr<Msg> msg);
private:

	vector<shared_ptr<Msg>>MsgQueue;

	vector<MsgingObject*>SubscriberList;
	
};

