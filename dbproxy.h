#ifndef DBPROXY_H
#define DBPROXY_H

#include <mutex>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

// thread-safe singleton
class DbProxy
{
public:
    static DbProxy *getProxy();
    bool getConnectionStatus();
    QPair<QString, QString> getTermHintPair(const QString&, const unsigned int&);

    DbProxy(DbProxy& copy) = delete;
    void operator=(const DbProxy&) = delete;

private:
    DbProxy(); // hide the constructor/destructor
    ~DbProxy();

    static mutex _mutex;
    static DbProxy *_dbProxy; // proxy instance
    QSqlDatabase _dbTerms; // db instance
};

#endif // DBPROXY_H
