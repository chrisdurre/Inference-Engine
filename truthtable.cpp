#include "truthtable.h"

TruthTable::TruthTable()
{
}

TruthTable::TruthTable(QStringList knowledgeBase, QStringList variables, QString query) {
    setKnowledgeBase(knowledgeBase);
    setVariables(variables);
    setQuery(query);
}

void TruthTable::initialize() {
    //get the required number of rows - number of varibles squared
    //get the initial number of columns - 1 for each variable
    int rowCount = qPow(2, variables.count());
    qDebug() << "variables:" << variables.count();
    qDebug() << "Row Count:" << rowCount;

    table = QVector<QVector<int>>(rowCount, QVector<int>(variables.count()));

    // loop down each row
    for(int i = 0; i < rowCount; i++){
        std::string fullBitset = std::bitset<64>(i).to_string();
        QString strippedBitset = QString::fromUtf8(fullBitset.c_str()).right(variables.count());
        qDebug() << strippedBitset;

        //loop across each column
        for(int j = 0; j < variables.count(); j++) {
            QChar toInsert = strippedBitset.at(j);
            table[i][j] = toInsert.unicode();
        }
    }
}

void TruthTable::solve() {
    int finalCount = 0;
    bool rowResult;
    bool kbEntailsAlpha = true;

    //loop through each row in table
    for(int i = 0; i < table.size(); i++) {
        rowResult = true;

        //loop through each clause in knowledge base
        for(int j = 0; j < knowledgeBase.size(); j++) {
            //split on implication if it exists
            QStringList parts = knowledgeBase[j].split("=>");
            //if there is an implication
            if(parts.size() > 1) {

            }
        }
    }

}
