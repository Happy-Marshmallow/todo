#include "databasemanager.h"
#include "datatemplate.h"

#include <QList>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>


QSqlDatabase databaseManager::open()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.sqlite");
    db.open();
    return db;
}

bool databaseManager::close(QSqlDatabase db)
{
    db = open();
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
    return true;
}

bool databaseManager::initDatabase(QSqlDatabase db)
{
    db = open();
    db.exec("CREATE TABLE todo (id INTEGER, name varchar(255))");
    close(db);
    return true;
}

bool databaseManager::resetDatabase(QSqlDatabase db)
{
    db = open();
    db.exec("drop table todo");
    close(db);
    return true;
}

datatemplate databaseManager::getData(QSqlDatabase db, datatemplate data)
{
    db = open();
    datatemplate result;
    QSqlQuery query = db.exec("select * from todo where id == " + data.name);
    close(db);

    query.first();

    result.id = query.value(0).toInt();
    result.name = query.value(1).toString();

    return result;
}

QList<datatemplate> databaseManager::getsData(QSqlDatabase db)
{
    db = open();
    QList<datatemplate> listdata;
    datatemplate temp;
    QSqlQuery query = db.exec("select * from todo");


    while (query.next()) {
        temp.id = query.value(0).toInt();
        temp.name = query.value(1).toString();
        listdata.append(temp);
    }

    close(db);
    return listdata;
}

bool databaseManager::insertData(QSqlDatabase db, datatemplate data)
{
    QString querystring;
    querystring = "insert into todo ( name ) values (";
    querystring += "'";
    querystring += data.name;
    querystring += "'";
    querystring += ")";

    db = open();
    db.exec(querystring);

    close(db);

    return true;
}

bool databaseManager::removeData(QSqlDatabase db, datatemplate data)
{
    QString querystring;
    querystring += "delete from todo where name = ";
    querystring += "\'";
    querystring += data.name;
    querystring += "\'";

    datatemplate result;
    db = open();
    db.exec(querystring);
    close(db);
    return false;
}

bool databaseManager::editData(QSqlDatabase db, datatemplate olddata, datatemplate newdata)
{
    QString querystring;
    querystring = "update todo set name = ";
    querystring += newdata.name;
    querystring += " where id == ";
    querystring += QString::number(olddata.id);
    querystring += ")";

    db = open();
    db.exec(querystring).result();
    close(db);

    return true;
}
