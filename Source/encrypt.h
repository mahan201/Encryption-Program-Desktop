#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QString>

QString Key();
QString encrypt(QString oldstr, QString Key);

QString decrypt(QString oldstr, QString Key);
QString file_decrypt(QString oldstr, QString Key );


#endif // ENCRYPT_H
