#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "datatemplate.h"

#include <QSqlDatabase>

class databaseManager
{
public:

    static bool editData(QSqlDatabase db, datatemplate olddata, datatemplate newdata);
    static bool removeData(QSqlDatabase db, datatemplate data);
    static bool insertData(QSqlDatabase db, datatemplate data);
    static QList<datatemplate> getsData(QSqlDatabase db);
    static datatemplate getData(QSqlDatabase db, datatemplate data);
    static bool resetDatabase(QSqlDatabase db);
    static bool initDatabase(QSqlDatabase db);
    static bool close(QSqlDatabase db);
    static QSqlDatabase open();
};

#endif // DATABASEMANAGER_H
