
#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <QFile>
#include <QBoxLayout>
#include <QLineEdit>

class CommandLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    /** creates a new CommandLine object*/
    explicit CommandLineEdit(QWidget *parent = nullptr);

    /** processes the input command from the commandLine */
    void processCommand(QString input);

};
#endif
