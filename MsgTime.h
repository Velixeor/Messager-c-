#pragma once
#include"Msg.h"
using namespace std;

class MsgTime :public Msg
{
public:

    float GetTime() {
        return time;
    }
    MsgTime(float time)
    {
        temp = AllTime;
        this->time = time;
    }
    ~MsgTime() {

    }
    vector<int>GetRecipient() {
        return  IdRecipient;
    }
    States GetState(void) {
        return temp;
    };

private:
    float time;
};