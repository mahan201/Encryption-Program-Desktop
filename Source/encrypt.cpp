#include "encrypt.h"
#include <QDebug>

QString encrypt(QString oldstr, int key)
{
    QString newstr;
    int len = oldstr.length();


    for (int i = 0; i<len; i++)
    {
        QChar chr = oldstr.at(i);
        if (chr == "\n")
        {
            newstr.append("\n");
            continue;
        }
        int oldascii = chr.toLatin1();
        int newascii;
        int check = oldascii + key;
        while (true)
        {
            if (check > 122)
            {
                newascii = check - 90;
                check = newascii;
                continue;
            }

            else if (check <= 122)
            {
                newascii = check;
                break;
            }
        }
        QChar nchr = ((short)newascii);
        newstr.append(nchr);
    }
    return newstr;
}


QString decrypt(QString oldstr, int key)
{
    QString newstr;
    int len = oldstr.length();

    for (int i=0; i<len; i++)
    {
        QChar chr = oldstr.at(i);
        if (chr == "\n")
        {
            newstr.append("\n");
            continue;
        }
        int oldascii = chr.toLatin1();
        int newascii;
        int check = oldascii - key;

        while (true)
        {
            if (check < 32)
            {
                newascii = check + 90;
                check = newascii;
                continue;
            }

            else if (check >= 32)
            {
                newascii = check;
                break;
            }
         }
         QChar nchr = ((short)newascii);
         newstr.append(nchr);
    }
    return newstr;

}
