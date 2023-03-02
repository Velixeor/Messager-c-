#pragma once
#include"Msg.h"
using namespace std;

class EmptyMsg :public Msg
{
public:
   
    EmptyMsg()
    {
       temp = Empty;

    };
    ~EmptyMsg() {

    }
    vector<int> GetRecipient() {
        return  IdRecipient;
    }
    States GetState(void) {
        return temp;
    };
};