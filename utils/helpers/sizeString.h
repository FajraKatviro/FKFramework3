#ifndef SIZESTRING_H
#define SIZESTRING_H

#include <QSize>
#include <QString>
#include <QStringList>

namespace FKUtility{

    //use this function to convert string to size object
    QSize stringToSize(const QString& str){
        QStringList parseStr=str.split("x");
        if(parseStr.size()==2){
            return QSize(parseStr.at(0).toInt(),parseStr.at(1).toInt());
        }
        return QSize();
    }

    //use this function to convert size object to string representation
    QString sizeToString(const QSize& size){
        return QString("%1x%2").arg(size.width()).arg(size.height());
    }
}

#endif // SIZESTRING_H
