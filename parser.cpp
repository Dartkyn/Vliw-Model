#include "parser.h"
#include "QMessageBox"
Parser::Parser()
{

}
//TODO Сделать проверки на количество операндов и использование регистров в команде
int Parser::parseString(QStringList fileStringList)
{
    _stringCounter = 0;
    bool flag = true;
    while(_stringCounter < fileStringList.length())
    {
        if(!fileStringList[_stringCounter].isEmpty())
        {
            if(fileStringList[_stringCounter] == kwData)
            {
                flag = true;
            }
            else
                if(fileStringList[_stringCounter] == kwCode)
                {
                    flag = false;
                }
                else
                    if(flag)
                    {
                        if((parseDataString(fileStringList[_stringCounter])!=0))
                        {
                                printError("Ошибка в  в строке: ", _stringCounter+1);
                                return -1;
                        }
                    }
                    else
                    {
                        if(parseCodeString(fileStringList[_stringCounter]) != 0)
                        {
                            //printError("Ошибка в написании команды в строке: ", _stringCounter+1);
                            return -1;
                        }
                    }
        }
        _stringCounter++;
    }
    return 0;
}

const QList<Data> &Parser::getDataStrings() const
{
    return _dataStrings;
}


const QList<Comand> &Parser::getComandList() const
{
    return _comandList;
}

int Parser::parseDataString(QString currentStr)
{

    while(currentStr[0] == ' ')
    {
        currentStr = currentStr.remove(0,1);
    }
    int indxLabelEnd = currentStr.indexOf(":")+1;

    QString label;
    Data data;
    if(indxLabelEnd != 0)
    {
        label = currentStr.section("", 0, indxLabelEnd-1);
        data.setLabel(label);
    }
    int indxCommentEnd = currentStr.indexOf("#");
    currentStr = currentStr.section("", indxLabelEnd+1, indxCommentEnd-1);
    while(currentStr[0] == ' ')
    {
        currentStr = currentStr.remove(0,1);
    }
    QStringList dataStr = currentStr.split(" ");
    if(dataStr[0]==kwByte.kword||dataStr[0]==kwHalfWord.kword||dataStr[0]==kwDoubleWord.kword||dataStr[0]==kwWord.kword)
    {
        data.setDataType(dataStr[0]);
    }
    else
    {
        return -1;
    }
    QByteArray arr;
    for(int i = 1; i< dataStr.length();i++)
    {
        if(dataStr[i].contains(","))
        {
            QStringList lst = dataStr[i].split(",");
            for(auto str:lst)
            {
                arr.push_front(str.toLocal8Bit());
            }
        }
        else
        {
            arr.append(dataStr[i].toUtf8());
        }
    }
    data.setDataValue(arr.toLongLong(nullptr,16));
    _dataStrings.append(data);
    return 0;
}

int Parser::parseCodeString(QString currentStr)
{
    Comand* comand;
    while(currentStr[0] == ' ')
    {
        currentStr = currentStr.remove(0,1);
    }
    int indxLabelEnd = currentStr.indexOf(":")+1;
    QString label;
    if(indxLabelEnd != 0)
        label = currentStr.section("", 0, indxLabelEnd-1);
    int indxCommentEnd = currentStr.indexOf("#");
    QString comment = currentStr.section("", indxCommentEnd,currentStr.length());
    currentStr = currentStr.section("", indxLabelEnd+1, indxCommentEnd);
    comand = parseComand(currentStr, label);
    if(comand != nullptr)
    {
        _comandList.append(*comand);
        return 0;
    }
    else
        return -1;

}

Comand* Parser::parseComand(QString str, QString label)
{
    while(str[0] == ' ')
    {
        str = str.remove(0,1);
    }
    QStringList instruction_str;
    instruction_str = str.split(";");
    QList<Instruction> instructions;
    for(int i = 0; i < instruction_str.length(); i++)
    {
        auto inst = parseInstructrions(instruction_str[i]);
        if(inst!= nullptr)
        {
            instructions.append(*inst);
        }
        else
        {
            return nullptr;
        }
    }
    int flcounter = 0;
    for(auto inst:instructions)
    {
        int cdNumber = inst.keyword().codeNumber;
        if((cdNumber>= kwJump.codeNumber) && (cdNumber <= kwJ.codeNumber))
        {
            flcounter++;
        }
    }
    if(flcounter>1)
    {
        printError("Ошибка: использование более одной инструкции перехода в команде на строке: ", _stringCounter+1);
        return nullptr;
    }
    Comand* com = new Comand(label, instructions);
    return com;
}

void Parser::printError(QString err, int ukStr)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ошибка");
    msgBox.setText(err + QString::number(ukStr));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

Instruction* Parser::parseInstructrions(QString str)
{
    while(str[0] == ' ')
    {
        str = str.remove(0,1);
    }
    int indxKeyWordEnd = str.indexOf(" ");
    QString keyWord = str.section("", 0, indxKeyWordEnd);
    QStringList parameters;
    if(keyWord != kwNop.kword)
    {
        str = str.section("", indxKeyWordEnd + 1);
        parameters = str.split(",");
        for(int i=0; i< parameters.length();i++)
            parameters[i].remove(" ");
    }
    Instruction* inst = new Instruction(keyWord, parameters);
    if(inst->keyword().codeNumber == kwErr.codeNumber)
    {
        printError("Ошибка в написании инструкции "+ keyWord + " в строке: ", _stringCounter+1);
        return nullptr;
    }
    if(inst->keyword().operCount != inst->parameters().count())
        {
            printError("Ошибка: неверное количество параметров в написании инструкции "+ keyWord + " в строке: ", _stringCounter+1);
            return nullptr;
        }
    return inst;
}




