#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    QString File_Size(qint64 bytes);

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
