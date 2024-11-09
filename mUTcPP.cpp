#include "mUTcPP.h"

mUTcPP::mUTcPP(vector<testingFunction> parsedVector)
{
    functionsToTest_ = parsedVector;
}

void mUTcPP::setTerminal(int colour)
{
    cout << "\033[" << colour << "m";
}

void mUTcPP::writeMessage(messageType messageT, string message)
{
    setTerminal(messageT);
    cout << message;
    setTerminal(messageType::message);
}