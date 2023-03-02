#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Messenger.h"
using namespace std;

void Messenger::Subscribe(MsgingObject* obj) {
	
	SubscriberList.push_back(obj);
}
shared_ptr<Msg> Messenger::GetMsg() {
	return MsgQueue[0];
}

void Messenger::SetMsg(shared_ptr<Msg> msg) {
	if(msg->GetState()!=Empty)
	MsgQueue.push_back(msg);
}
Messenger::Messenger() {
	
}
Messenger::~Messenger() {

}

void Messenger::Run(RenderWindow &window) {
	Clock clock;
	float TIME=0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;  
		TIME += time * 0.0005;
		if (TIME > 10)
			TIME = 0;
		shared_ptr<Msg> msg =make_shared<MsgTime>(TIME);
		SetMsg(msg);
		
		window.clear();
		
		while (MsgQueue.size()>0){
			
				if (MsgQueue[0]->GetState() == Empty) {

				}
				else {
					for (int i = 0; i < SubscriberList.size(); i++) {
						
						SetMsg(SubscriberList[i]->Run(event, window,GetMsg()));
					}
				}
			
				MsgQueue.erase(MsgQueue.cbegin());
			
		}
		
		window.display();


	}
}