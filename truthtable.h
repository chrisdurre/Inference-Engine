#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

#include <QObject>
#include <QVector>
#include <QtMath>
#include <QDebug>
#include <bitset>
#include <type_traits>

class TruthTable : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList knowledgeBase READ getKnowledgeBase NOTIFY knowledgeBaseChanged)
    Q_PROPERTY(QStringList variables READ getVariables NOTIFY variablesChanged)
    Q_PROPERTY(QString query READ getQuery WRITE setQuery NOTIFY queryChanged)

public:
    TruthTable();
    TruthTable(QStringList knowledgeBase, QStringList variables, QString query);

    QStringList getKnowledgeBase() { return this->knowledgeBase; }
    void setKnowledgeBase(QStringList knowledgeBase) { this->knowledgeBase = knowledgeBase; }

    QStringList getVariables() { return this->variables; }
    void setVariables(QStringList variables) { this->variables = variables; }

    QString getQuery() { return this->query; }
    void setQuery(QString query) { this->query = query; }

    void initialize();

private:
    QStringList knowledgeBase;
    QStringList variables;
    QString query;
    QVector<QVector<int>> table;

signals:
    void knowledgeBaseChanged();
    void variablesChanged();
    void queryChanged();
};

#endif // TRUTHTABLE_H
