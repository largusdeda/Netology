#include <QCoreApplication>
#include <QtSql>
#include <QtNetwork>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QHostAddress my_address;
    my_address.setAddress("95.24.135.161");
    qDebug() << my_address.toString() << Qt::endl;

    QSqlDatabase my_db = QSqlDatabase::database("QPSQL");
    qDebug() << my_db.isValid();
    qDebug() << my_db.isDriverAvailable("QPSQL");
    qDebug() << my_db.isOpen();

    return a.exec();
}
