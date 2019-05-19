#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

#include "inferenceEngine.h"

static QString _KB;
static QString _query;

static bool readFile(QString fileName);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //get the arguments
    QStringList args = a.arguments();

    if(args.count() != 3) {
        qDebug() << "Incorrect number of arguments";
    }
    else {
        //split the arguments
        QString method = args[1];
        QString fileName = args[2];

        if(readFile(fileName)) {
            inferenceEngine *IE = new inferenceEngine(_KB, _query);
            IE->solve(method);
        }
    }

    return a.exec();
}

static bool readFile(QString fileName) {
    QString KB;
    QString query;

    //open the file
    QFile inFile(fileName);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "file not found";
        inFile.close();
        return false;
    }

    //read the lines
    int i = 0;
    while(!inFile.atEnd()) {
        QString line = inFile.readLine();
        if(i == 1) {
            KB = line;
        }
        else if (i == 3) {
            query = line;
        }
        i++;
    }

    //check if both values filled
    if(!((KB == "") && (KB.isNull()) && (query == "") && (query.isNull()))) {
        qDebug() << "values filled";
        _KB = KB;
        _query = query;
        inFile.close();
        return true;
    } else {
        qDebug() << "values not filled";
        inFile.close();
        return false;
    }
}
