#include "data.h"

Data::Data()
{
    _dataValue = 0;
}


Data::Data(const QString &label, const QString &dataType, const long long &dataValue) : _label(label),
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

const long long &Data::dataValue() const
{
    return _dataValue;
}

void Data::setDataValue(const long long &newDataValue)
{
    _dataValue = newDataValue;
}

QString Data::toString()
{
    QString str;
    str =(_label.length() > 0) ? _label + "//" : "";
    str = str + _dataType + "//";
    str = str + QString::number(_dataValue,16);
    return str;
}



