#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
//Types of messages needed mainly for mailing
enum States
{
    ForCircle, ForBacgroung, ForRect,
    Empty,AllTime, SpecificRecipient
};
//Polymorphic message class from which all types of messages are inherited
class Msg
{
public:
    
    Msg(void ) {
        temp = Empty;
    }
    ~Msg() {

    }
   virtual vector<int> GetRecipient() = 0;
   
    int GetIDRecipient(int i) {
        return  IdRecipient[i];
    }
  
protected:
   
   
    vector<int> IdSender;

    vector<int> IdRecipient;
    enum States temp;
public:
    virtual States GetState(void)=0;
};

