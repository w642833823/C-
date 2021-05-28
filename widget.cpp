#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <iostream>
#include <QDebug>
#include <QFileDialog>
#include "dialog.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    //获取当前路径
    QString appDirPath = QCoreApplication::applicationDirPath();
    qDebug()<<"当前路径>>>>>>>"<<appDirPath;
    //转换成对应系统路径
    QString  appDirPaths = QDir::toNativeSeparators(appDirPath);
    qDebug()<<"转换成对应系统路径>>>>>>>"<<appDirPaths;

    qDebug()<<std::system("cat /home/w642833823/安装常用工具.sh");

    //std::system("sh /home/w642833823/安装常用工具.sh");


}

void Widget::on_pushButton_4_clicked()
{
   //QString srcDirPath = QFileDialog::getExistingDirectory( this, "choose src Directory", "/home");
 QString  srcDirPath = QFileDialog::getOpenFileName(this);

        if (srcDirPath.isEmpty())
        {
            return;
        }
            srcDirPath += "/";
            QString  file_name, file_path;
            QFileInfo fi;
            fi = QFileInfo(srcDirPath);
            file_name = fi.fileName();

            file_path = fi.absolutePath();
            long  int size = 0;
                QFile myFile(file_path);
                if (myFile.open(QIODevice::ReadOnly))
                {
                    size  = myFile.size();  //when file does open.
                    myFile.close();
                }

        qDebug()<<"路径》》"<<file_path<<"文件名》》"<<file_name<<"大小》》"<<File_Size(size);

         ui->textBrowser->setPlainText(file_path);

         Dialog* dialog=new Dialog(this);
         dialog->show();
/*

    QString  str;
    str.append(" git clone ");
    str.append(ui->lineEdit->text());
    str.append(" /home/w642833823/");
    char*  ch;
    QByteArray ba = str.toLatin1(); // must
    ch=ba.data();
QStringList tts;
    qDebug()<<std::system(ch);
    tts.append(QString("%1").arg(std::system(ch)));
    foreach (QString ts, tts) {
            ui->textBrowser->setPlainText(ts);
    }
*/

}

// 字节转KB、MB、GB
QString Widget::File_Size(qint64 bytes)
{
    QString strUnit;
    double dSize = bytes * 1.0;
    if (dSize <= 0)
    {
        dSize = 0.0;
    }
    else if (dSize < 1024)
    {
        strUnit = "Bytes";
    }
    else if (dSize < 1024 * 1024)
    {
        dSize /= 1024;
        strUnit = "KB";
    }
    else if (dSize < 1024 * 1024 * 1024)
    {
        dSize /= (1024 * 1024);
        strUnit = "MB";
    }
    else
    {
        dSize /= (1024 * 1024 * 1024);
        strUnit = "GB";
    }
    return QString("%1 %2").arg(QString::number(dSize, 'f', 2)).arg(strUnit);
}
