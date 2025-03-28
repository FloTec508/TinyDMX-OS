#include "commandLine.h"
#include "fixturemanager.h"
#include "qdebug.h"

#include <QRegularExpression>

CommandLineEdit::CommandLineEdit(QWidget *parent)
    : QLineEdit(parent)
{


}

void CommandLineEdit::processCommand(QString input){

    if (input.isEmpty())
        return; // Ignore empty input

    QStringList parts = input.split(QRegularExpression("\\s+")); //split by spaces

    QList<int> fixtureIDs;
    QList<int> groupIDs;


    int source = 0; // 0 = fixture, 1 = group
   // int mask;
    int command = 0;//0 = select 1 = delete 2 = record
    //int dest;

    //bool deleteCommand = false;

    int lastindx = 0;

    if(parts[0].toInt()){
        source = 0;
    }else if(parts[0].toLower() == "group"){
        source = 1;
    }else{
        return;
    }

    int size = parts.size();
    QString msg = "Size: " + QString::number(size);

    qInfo() << msg;

    if(source == 0){

        fixtureIDs.append(parts[0].trimmed().toInt());
        lastindx = 0;

        if(size >= 3 && parts[1].toLower() == ">" ){

            bool x = false;
            parts[2].toInt(&x);
            if(x){
                fixtureIDs.append(parts[2].trimmed().toInt());
                lastindx = 2;

            }else{
                return;
            }
        }else{

            fixtureIDs.append(parts[0].trimmed().toInt());

        }
    }else if(source == 1){
        groupIDs.append(parts[1].trimmed().toInt());
        lastindx = 1;
        if(size >= 4 && parts[2].toLower() == ">"){
            bool x = false;
            parts[3].toInt(&x);
            if(x){
                groupIDs.append(parts[3].trimmed().toInt());
                lastindx = 3;
            }else{
                return;
            }
        }else{
            groupIDs.append(parts[1].trimmed().toInt());
        }
    }else{
        return;
    }

    if(parts.size() == lastindx + 1){
        command = 0;
    }else if(parts[lastindx + 1].toLower() == "delete"){
        command = 1;
    }else{
        return;
    }

    FixtureManager *manager = FixtureManager::instance();

    switch(command){
    case 0:
        if(source == 0){
        manager->selectFixture(fixtureIDs[0],fixtureIDs[1]);
        } else if(source == 1){
        manager->selectGroup(groupIDs[0], groupIDs[1]);
        }
        break;
    case 1:
        msg = "deleting " + QString::number(fixtureIDs[0]) + " thru " + QString::number(fixtureIDs[1]);
        qInfo() << msg;
        manager->selectFixture(fixtureIDs[0],fixtureIDs[1]);
        manager->removeFixture();
        break;
    default:
        return;
        break;

    }





}




