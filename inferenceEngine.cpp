#include "inferenceEngine.h"

inferenceEngine::inferenceEngine(QString KB, QString query) {
    KB.replace(" ", "");
    qDebug() << KB;
    knowledgeBase = KB.split(";");

    for(int i = 0; i < knowledgeBase.size(); i++) {
        QRegExp seperator("(&|=>|<=>|~|\\||\\)|\\(|\\\n)");
        knowledgeBase[i].replace(seperator, ",");
        QStringList parts = knowledgeBase[i].split(seperator);
        for(int j = 0; j < parts.size(); j++) {
            QStringList subParts = parts[j].split(",");
            for (int k = 0; k < subParts.size(); k++) {
                if(subParts[k].size() > 0 && !variables.contains(subParts[k])) {
                    variables.append(subParts[k]);
                }
            }
        }
    }
    for(int h = 0; h < variables.size(); h++) {
        qDebug() << variables[h];
    }

    setQuery(query);
}

void inferenceEngine::solve(QString method) {
    if(method == "TT") {
        TruthTable* tt = new TruthTable(knowledgeBase, variables, query);
        tt->initialize();
//        tt->solve();
    } else {
        qDebug() << "No Matching Method Found";
    }
}
