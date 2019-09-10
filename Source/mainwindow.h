#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <encrypt.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainWindow* wind;
    QString old_encrypt_loc;
    QString new_encrypt_name;
    QString new_encrypt_loc;
    QString old_decrypt_loc;
    QString new_decrypt_name;
    QString new_decrypt_loc;



private slots:

    void on_actionExit_triggered();

    void on_actionminimize_triggered();

    void on_actionmaximize_triggered();

    void on_actionEncrypt_triggered();

    void on_actionDecrypt_triggered();

    void on_textEdit_Encryption_textChanged();

    void on_spinBox_encrypted_valueChanged(int arg1);


    void on_textEdit_Decryption_textChanged();

    void on_Browse_Encrypt_Input_clicked();

    void on_Browse_Output_En_clicked();

    void on_pushButton_encrypt_clicked();


    void on_pushButton_decrypt_clicked();

    void on_Browse_Decrypt_Input_clicked();

    void on_Browse_Output_De_clicked();

    void on_spinBox_decrypted_valueChanged(int arg1);

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
