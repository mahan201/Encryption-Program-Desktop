#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encrypt.h"
#include <QColorDialog>
#include <QDebug>
#include <QPixmap>
#include <QStandardPaths>
#include <QMouseEvent>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wind = this;
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    ui->textEdit_Encryption->setPlaceholderText("Enter or generate a key before typing");
    ui->textEdit_Decryption->setPlaceholderText("Enter your key before typing");
    ui->textBrowser_Encryption->setPlaceholderText("Encrypted Text Here");
    ui->textBrowser_Decryption->setPlaceholderText("Decrypted Text Here");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionminimize_triggered()
{
    wind->QWidget::setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_actionmaximize_triggered()
{
    if (wind->windowState().testFlag(Qt::WindowMaximized) == true)
    {
        wind->QWidget::setWindowState(Qt::WindowNoState);
    }
    else
    {
        wind->QWidget::setWindowState(Qt::WindowMaximized);
    }

}



void MainWindow::on_actionEncrypt_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionDecrypt_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_textEdit_Encryption_textChanged()
{
    if (ui->lineEdit_Encrypt->text() == NULL)
    {
        QString K = Key();
        ui->lineEdit_Encrypt->setText(K);
    }

    QString newstr = encrypt(ui->textEdit_Encryption->toPlainText(),ui->lineEdit_Encrypt->text());
    ui->textBrowser_Encryption->setText(newstr);
}

void MainWindow::on_textEdit_Decryption_textChanged()
{
    if (ui->lineEdit_Decrypt->text() == NULL)
    {
        QMessageBox::warning(this,"MISSING KEY", "MISSING KET. Please enter your Key");
    }
    else
    {
        QString newstr = decrypt(ui->textEdit_Decryption->toPlainText(),ui->lineEdit_Decrypt->text());
        ui->textBrowser_Decryption->setText(newstr);
    }

}


void MainWindow::on_Browse_Encrypt_Input_clicked()
{
    old_encrypt_loc = QFileDialog::getOpenFileName(this,"Open your text file.",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),tr("Text (*.txt)"));
    ui->Encrypt_Input->setText(old_encrypt_loc);

}

void MainWindow::on_Browse_Output_En_clicked()
{
    new_encrypt_loc = QFileDialog::getExistingDirectory(this,"Select output folder",
                                                        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    ui->OutputLocation_En->setText(new_encrypt_loc);
}

void MainWindow::on_pushButton_encrypt_clicked()
{

    old_encrypt_loc = ui->Encrypt_Input->text();
    new_encrypt_name = ui->NewNameText_En->text();
    new_encrypt_loc = ui->OutputLocation_En->text();


    if (old_encrypt_loc == NULL || new_encrypt_loc == NULL || new_encrypt_name == NULL)
    {
        QMessageBox::warning(this,"MISSING PARAMETERS", "Please fill all required info");
    }

    else if (old_encrypt_loc != NULL && new_encrypt_loc != NULL && new_encrypt_name != NULL)
    {
        QFile filein(old_encrypt_loc);
        if (!filein.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"BAD FILE","File not selected/curropted!");
        }
        QTextStream in(&filein);
        QString oldstr = in.readAll();
        QString key = Key();
        QString newstr = encrypt(oldstr,key);
        QString newloc = new_encrypt_loc + "/" + new_encrypt_name + ".txt";



        QFile fileout(newloc);
        if (!fileout.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"BAD FILE","File not selected/curropted!");
        }

        QTextStream out(&fileout);
        int int_len = key.length();
        QChar char_len = ((char)int_len);
        out << char_len;
        out << newstr;
        out << key;
        old_encrypt_loc = "";
        new_encrypt_name = "";
        new_encrypt_loc = "";

        fileout.flush();
        filein.flush();
        fileout.close();
        filein.close();


        QMessageBox::information(this,"Encryption Done!","Your Encrypted file is saved at: \n" + newloc);
    }


}


void MainWindow::on_Browse_Decrypt_Input_clicked()
{
    old_decrypt_loc = QFileDialog::getOpenFileName(this,"Open your text file.",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),tr("Text (*.txt)"));

    ui->Input_decrypt->setText(old_decrypt_loc);

}

void MainWindow::on_Browse_Output_De_clicked()
{
    new_decrypt_loc = QFileDialog::getExistingDirectory(this,"Select output folder",
                                                        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    ui->OutputLocation_De->setText(new_decrypt_loc);
}


void MainWindow::on_pushButton_decrypt_clicked()
{

    old_decrypt_loc = ui->Input_decrypt->text();
    new_decrypt_name = ui->NewNameText_De->text();
    new_decrypt_loc = ui->OutputLocation_De->text();


    if (old_decrypt_loc == NULL || new_decrypt_loc == NULL || new_decrypt_name == NULL)
    {
        QMessageBox::warning(this,"MISSING PARAMETERS", "Please fill all required info");
    }

    else if (old_decrypt_loc != NULL && new_decrypt_loc != NULL && new_decrypt_name != NULL)
    {
        QFile filein(old_decrypt_loc);
        if (!filein.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"BAD FILE","File not selected/curropted!");
        }

        QTextStream in(&filein);
        QString oldstr = in.readAll();
        QString key;
        QChar len_c = oldstr.at(0);
        int len = (len_c.toLatin1());
        for(int i = (oldstr.length() - len); i<oldstr.length(); i++)
        {
            QChar Letter = oldstr.at(i);
            key.append(Letter);
        }
        QString newstr = file_decrypt(oldstr,key);
        QString newloc = new_decrypt_loc + "/" + new_decrypt_name + ".txt";

        QFile fileout(newloc);
        if (!fileout.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"BAD FILE","File not selected/curropted!");
        }

        QTextStream out(&fileout);
        out << newstr;

        old_decrypt_loc = "";
        new_decrypt_name = "";
        new_decrypt_loc = "";


        fileout.flush();
        filein.flush();
        fileout.close();
        filein.close();

        QMessageBox::information(this,"Decryption Done!","Your Decrypted file is saved at: \n" + newloc);
    }
}





void MainWindow::on_actionAbout_triggered()
{
    QString about = "Encryption Program\nDeveloped by Mahan Noorbahr";
    QMessageBox::information(this,"ABOUT",about);
}

void MainWindow::on_Random_Key_Button_clicked()
{
    QString K = Key();
    ui->lineEdit_Encrypt->setText(K);
    QString newstr = encrypt(ui->textEdit_Encryption->toPlainText(),ui->lineEdit_Encrypt->text());
    ui->textBrowser_Encryption->setText(newstr);
}

void MainWindow::on_lineEdit_Decrypt_textChanged(const QString &arg1)
{
    if (ui->lineEdit_Decrypt->text() != NULL)
    {
        QString newstr = decrypt(ui->textEdit_Decryption->toPlainText(),ui->lineEdit_Decrypt->text());
        ui->textBrowser_Decryption->setText(newstr);
    }

}

void MainWindow::on_lineEdit_Encrypt_textChanged(const QString &arg1)
{
    if(ui->lineEdit_Encrypt->text() != NULL)
    {
        QString newstr = encrypt(ui->textEdit_Encryption->toPlainText(),ui->lineEdit_Encrypt->text());
        ui->textBrowser_Encryption->setText(newstr);
    }

}
