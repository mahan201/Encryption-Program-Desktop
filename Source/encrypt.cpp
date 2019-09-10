#include "encrypt.h"
#include <QDebug>


QString Key()
{
    int length = qrand() % 7 + 5;
    QString key;
    for (int i = 0; i<length; i++)
    {
        int ASCII = qrand() % 74 + 48;
        QChar character = (char)ASCII;
        key.append(character);
    }
    return key;
}


QString encrypt(QString oldstr, QString Key)
{
    QString newstr;
    int len = oldstr.length();
    int Key_Loop = 0;


    for (int i = 0; i<len; i++)
    {
        QChar chr = oldstr.at(i);
        if (chr == "\n")
        {
            newstr.append("\n");
            continue;
        }
        int oldascii = chr.toLatin1();
        QChar Key_Char = Key.at(Key_Loop);
        int Key_ASCII = Key_Char.toLatin1();
        int newascii;
        int check = oldascii + Key_ASCII;
        while (true)
        {
            if (check > 122)
            {
                newascii = check - 91;
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
        Key_Loop = Key_Loop + 1;
        if (Key_Loop == Key.length())
        {
            Key_Loop = 0;
        }
    }
    return newstr;
}

QString decrypt(QString oldstr, QString Key )
{
    QString newstr;
    int len = oldstr.length();
    int Key_Loop = 0;

    for (int i=0; i<len; i++)
    {
        QChar chr = oldstr.at(i);
        if (chr == "\n")
        {
            newstr.append("\n");
            continue;
        }
        QChar Key_Char = Key.at(Key_Loop);
        int Key_ASCII = Key_Char.toLatin1();
        int oldascii = chr.toLatin1();
        int newascii;
        int check = oldascii - Key_ASCII;

        while (true)
        {
            if (check < 32)
            {
                newascii = check + 91;
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
         Key_Loop = Key_Loop + 1;
         if (Key_Loop == Key.length())
         {
             Key_Loop = 0;
         }
    }
    return newstr;

}

QString file_decrypt(QString oldstr, QString Key )
{
    QString newstr;
    int len = oldstr.length();
    int Key_Loop = 0;

    for (int i=1; i<(len-Key.length()); i++)
    {
        QChar chr = oldstr.at(i);
        if (chr == "\n")
        {
            newstr.append("\n");
            continue;
        }
        QChar Key_Char = Key.at(Key_Loop);
        int Key_ASCII = Key_Char.toLatin1();
        int oldascii = chr.toLatin1();
        int newascii;
        int check = oldascii - Key_ASCII;

        while (true)
        {
            if (check < 32)
            {
                newascii = check + 91;
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
         Key_Loop = Key_Loop + 1;
         if (Key_Loop == Key.length())
         {
             Key_Loop = 0;
         }
    }
    return newstr;

}
