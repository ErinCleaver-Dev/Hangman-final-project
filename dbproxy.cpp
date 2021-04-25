#include "dbproxy.h"

mutex DbProxy::_mutex;
DbProxy* DbProxy::_dbProxy {nullptr};

// constructor
DbProxy::DbProxy()
{
    _dbTerms = QSqlDatabase::addDatabase("QSQLITE");
    _dbTerms.setDatabaseName("terms.db"); // I am (g)root!
}

DbProxy::~DbProxy()
{
    _dbTerms.close(); // terminate connection
}

// create object, otherwise return instance
DbProxy *DbProxy::getProxy()
{
    lock_guard<mutex> lock(_mutex);
    if (_dbProxy == nullptr)
        _dbProxy = new DbProxy();

    return _dbProxy;
}

bool DbProxy::getConnectionStatus()
{
    return _dbTerms.open();
}

// returns a term and accompanying hint given a table and key.
QPair<QString, QString> DbProxy::getTermHintPair(const QString& table, const unsigned int& key)
{
    QPair<QString, QString> termHintPair;

    if (!_dbTerms.open())
        qDebug() << "Unable to make a database connection!";
    else
    {
        qDebug() << "Connected to database.";
        QString queryString("SELECT * FROM " + table + " WHERE ID = " + QString::number(key));
        QSqlQuery query(queryString);
        while (query.next())
        {
            termHintPair.first = query.value(1).toString();
            termHintPair.second = query.value(2).toString();
        }
    }
    return termHintPair;
}
