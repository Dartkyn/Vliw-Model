#ifndef REGISTER_H
#define REGISTER_H
#include "QString"

class Register
{
public:
    Register();
    /*! Возвращает \c char - байтовое отображение значения регистра. */
    char getByte();
    /*! Возвращает полуслово значения регистра. */
    short getHalfWord();
    /*! Возвращает слово значения регистра. */
    int getWord();
    /*! Возвращает двойное слово значения регистра. */
    long long getDoubleWord();
    /*! Устанавливает байтовое значение регистра. */
    void setByte(char value);
     /*! Устанавливает полуслово значения регистра. */
    void setHalfWord(short value);
     /*! Устанавливает слово значения регистра. */
    void setWord(int value);
     /*! Устанавливает двойное слово значения регистра. */
    void setDoubleWord(long long value);
    /*! Возвращает \c QString - строковое представление значения регистра */
    QString toString();
private:
    /*! Свойство, хранящее значение, помещенное в регистр */
    long long _registerValue;
};

#endif // REGISTER_H
