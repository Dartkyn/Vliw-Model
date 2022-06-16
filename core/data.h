#ifndef DATA_H
#define DATA_H
#include "QString"
#include "QByteArray"
const int MAX_MEMORY_SIZE = 16;
class Data
{
public:
    Data();
    Data(const QString &label, const QString &dataType, const long long &dataValue);
    const QString &label() const;
    void setLabel(const QString &newLabel);
    const QString &dataType() const;
    void setDataType(const QString &newDataType);


    const long long &dataValue() const;
    void setDataValue(const long long &newDataValue);
    QString toString();

private:
    QString _label;
    QString _dataType;
    long long _dataValue;
};

#endif // DATA_H
