#ifndef DATA_H
#define DATA_H
#include "QString"
#include "QByteArray"
const int MAX_MEMORY_SIZE = 16;
class Data
{
public:
    Data();
    Data(const QString &label, const QString &dataType, const QByteArray &dataValue);
    const QString &label() const;
    void setLabel(const QString &newLabel);
    const QString &dataType() const;
    void setDataType(const QString &newDataType);


    const QByteArray &dataValue() const;
    void setDataValue(const QByteArray &newDataValue);
    QString toString();

private:
    QString _label;
    QString _dataType;
    /*!Содержит значение, кодируемое как 2 шестнадцатеричного символа - байт*/
    QByteArray _dataValue;
};

#endif // DATA_H
