#include "data.h"

Data::Data()
{
    _dataValue.fill('0', MAX_MEMORY_SIZE);
}


Data::Data(const QString &label, const QString &dataType, const QByteArray &dataValue) : _label(label),
    _dataType(dataType),
    _dataValue(dataValue)
{}

const QString &Data::label() const
{
    return _label;
}

void Data::setLabel(const QString &newLabel)
{
    _label = newLabel;
}

const QString &Data::dataType() const
{
    return _dataType;
}

void Data::setDataType(const QString &newDataType)
{
    _dataType = newDataType;
}

const QByteArray &Data::dataValue() const
{
    return _dataValue;
}

void Data::setDataValue(const QByteArray &newDataValue)
{
    _dataValue = newDataValue;
}

QString Data::toString()
{
    QString str = _label + "//";
    str = str + _dataType + "//";
    str = str + _dataType;
    return str;
}



