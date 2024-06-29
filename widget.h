#ifndef WIDGET_H
#define WIDGET_H

#include "qlistwidget.h"
#include <QWidget>
#include<QUrl>
#include<QMediaPlayer>
#include<QAudioOutput>

#include<QFileDialog>
#include<QFileInfo>
#include<QDir>
#include<QJsonArray>    // 封装JSON数组
#include<QJsonObject>   // 封装JSON对象
#include<QJsonDocument>

#include<QSqlDatabase>  // 数据库相关
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlError>

#include<QMessageBox>
#include<QTime>
#include<math.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
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

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();
    void playNext();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
    QList<QUrl>playList;  // 播放列表
    QList<int> randomList;
    int curPlayIndex=0;
    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;
    int playMode;
    QSqlDatabase db;
};
#endif // WIDGET_H
