#ifndef REGISTER_H
#define REGISTER_H
#include "QString"

class Register
{
public:
    Register();
    char getByte();
    short getHalfWord();
    int getWord();
    long long getDoubleWord();
    void setByte(char value);
    void setHalfWord(short value);
    void setWord(int value);
    void setDoubleWord(long long value);
    QString toString();
private:
    long long _registerValue;
};

#endif // REGISTER_H
