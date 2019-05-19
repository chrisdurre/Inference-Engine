#ifndef INFERENCEENGINE_H
#define INFERENCEENGINE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>

#include "truthtable.h"

class inferenceEngine : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QStringList knowledgeBase READ getKnowledgeBase NOTIFY knowledgeBaseChanged)
    Q_PROPERTY(QStringList variables READ getVariables NOTIFY variablesChanged)
    Q_PROPERTY(QString query READ getQuery WRITE setQuery NOTIFY queryChanged)
public:
    inferenceEngine(QString knowledgeBase, QString query);

    QString getFileName() { return this->fileName; }
    void setFileName(QString fileName) { this->fileName = fileName; }

    QStringList getKnowledgeBase() { return this->knowledgeBase; }
    void setKnowledgeBase(QStringList knowledgeBase) { this->knowledgeBase = knowledgeBase; }

    QStringList getVariables() { return this->variables; }
    void setVariables(QStringList variables) { this->variables = variables; }

    QString getQuery() { return this->query; }
    void setQuery(QString query) { this->query = query; }

    void solve(QString method);

private:
    QString fileName;
    QStringList knowledgeBase;
    QStringList variables;
    QString query;

signals:
    void fileNameChanged();
    void knowledgeBaseChanged();
    void variablesChanged();
    void queryChanged();
};

#endif // INFERENCEENGINE_H
