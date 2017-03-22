#ifndef FKACCESSGROUP_H
#define FKACCESSGROUP_H

#include <QObject>

#include <QSet>
#include <QQmlListProperty>

class FKAccessGroup : public QObject{
    Q_OBJECT
    Q_PROPERTY(QList<qint32> access READ accessList WRITE setAccessList NOTIFY accessChanged)
    Q_PROPERTY(QQmlListProperty<FKAccessGroup> accessGroups READ accessGroups NOTIFY accessGroupsChanged)
    Q_CLASSINFO("DefaultProperty","accessGroups")
public:
    explicit FKAccessGroup(QObject *parent = 0);
    ~FKAccessGroup();

    QSet<qint32> access()const;
    void setAcceess(const QSet<qint32>& access);

    QSet<qint32> totalAccess()const;

signals:
    void accessChanged();
    void accessGroupsChanged();

protected:
    virtual void addDependentGroup(FKAccessGroup* object);
    virtual void removeDependentGroup(FKAccessGroup* object);

private:
    QList<qint32> accessList()const;
    void setAccessList(const QList<qint32> list);

    QQmlListProperty<FKAccessGroup> accessGroups();
    static FKAccessGroup* getAccessGroup(QQmlListProperty<FKAccessGroup>* property, int index);
    static int countAccessGroups(QQmlListProperty<FKAccessGroup>* property);
    static void addAccessGroup(QQmlListProperty<FKAccessGroup>* property, FKAccessGroup* group);
    static void resetAccessGroups(QQmlListProperty<FKAccessGroup>* property);
    FKAccessGroup* getAccessGroup(const int index)const;
    int countAccessGroups()const;
    void addAccessGroup(FKAccessGroup* group);
    void resetAccessGroups();

    void invalidateCache()const;

    mutable struct{
        QSet<qint32> value;
        bool isValid = false;
    } _totalAccessCache;

    mutable struct{
        QSet<FKAccessGroup*> value;
    } _dependentAccessCache;

    QSet<qint32> _access;
    QList<FKAccessGroup*> _accessGroups;
    QList<FKAccessGroup*> _dependentAccessGroups;
};

#endif // FKACCESSGROUP_H
