#pragma once
#include"Msg.h"
class MsgColor :public Msg
{
public:
  

    char GetColor() {
        return Color;
    }
 
    MsgColor(int idR, char Color, int idS )
    {
        IdRecipient.push_back(idR);
        IdSender.push_back(idS);
        this->Color = Color;
        if(idS==0)
        temp = ForCircle;
        else if (idS == 1)
        temp = ForBacgroung;
        else if (idS == 2)
        temp = ForRect;
        else
        temp = SpecificRecipient;
        
    };
    States GetState(void) {
        return temp;
    };
    ~MsgColor(){}
    vector<int> GetRecipient() {
        return  IdRecipient;
    }

    

private:
    char Color;
 

};