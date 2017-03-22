#ifndef FKROOMOBJECTCOMPONENT_H
#define FKROOMOBJECTCOMPONENT_H

#include "FKAccessGroup.h"

#include <QQmlListProperty>

class FKRoomObjectComponent : public FKAccessGroup{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> children READ roomObjectComponentChildren NOTIFY childrenChanged)
    Q_CLASSINFO("DefaultProperty","children")

public:
    explicit FKRoomObjectComponent(QObject* parent = nullptr);
    ~FKRoomObjectComponent();

    void setIndex(const qint32 index);
    void resetIndex();

signals:
    void childrenChanged();

protected:
    qint32 index()const;

private:
    QQmlListProperty<QObject> roomObjectComponentChildren();
    static void addRoomObjectComponentChild(QQmlListProperty<QObject>* property, QObject* child);
    static int countRoomObjectComponentChildren(QQmlListProperty<QObject>* property);
    static QObject* getRoomObjectComponentChild(QQmlListProperty<QObject>* property, int index);
    static void resetRoomObjectComponentChildren(QQmlListProperty<QObject>* property);

    QList<QObject*> _roomObjectChildren;
    qint32 _index = -1;
};

#endif // FKROOMOBJECTCOMPONENT_H
