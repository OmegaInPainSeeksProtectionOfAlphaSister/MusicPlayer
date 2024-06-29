#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    playMode=0;
    ui->setupUi(this);
    //如何播放音乐 先加载模块multimedia
    //先new一个output对象
    audioOutput = new QAudioOutput(this);
    //再来一个媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);

    //给播放器设置音乐
    // mediaPlayer->setSource(
    //     QUrl::fromLocalFile("F:\\music\\仙瑶.mp3"));
    // //播放
    //mediaPlayer->play();

    // 获取当前媒体的时长，通过信号关联获取
    connect(mediaPlayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration)
    {
        ui->totalLabel->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
        ui->playCourseSlider->setRange(0,duration);
    });
    // 获取当前播放时长
    connect(mediaPlayer,&QMediaPlayer::positionChanged,this,[=](qint64 pos)
    {
        ui->curLabel->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0')).arg(pos/1000%60,2,10,QChar('0')));
        ui->playCourseSlider->setValue(pos);
    });
    //拖动滑块，让音乐播放的进度改变
    connect(ui->playCourseSlider,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);
    //
    // audioOutput->setVolume(0.5);
    connect(mediaPlayer,SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)),this,SLOT(playNext()));

    ui->horizontalSlider->setRange(0,100);
    ui->horizontalSlider->setValue(37);
    int val = ui->horizontalSlider->value();
    ui->label->setText(QString::number(val));

    // 数据库搭建
    // 1、连接数据库，如果不存在则创建
    if (QSqlDatabase::contains("Songs")) // 检查是否存在名为"song"的数据库连接
    {
        db = QSqlDatabase::database("Songs"); // 如果存在，则获取该数据库连接
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE"); // 如果不存在，则添加一个SQLite数据库连接
        db.setDatabaseName("Songs.db"); // 设置数据库文件名为"song.db"
    }

    // 2、打开数据库，读取数据表
    if (!db.open()) // 尝试打开数据库
    {
        // 打开数据库失败，显示错误信息
        QMessageBox::critical(nullptr, "错误", db.lastError().text());
    }
    else
    {
        // 3、定义查询对象，执行数据库操作

        QSqlQuery query; // 定义数据库查询对象
        // query.exec("DROP TABLE songlist;");
        // query.exec("DROP TABLE songhistory;");

        QString qstl; // 创建歌曲列表表格的SQL语句
        int ret;

       //  // 创建歌曲记录表格
        qstl = "create table if not exists songhistory(id integer primary key autoincrement, fileName text , musicPath text);";
        ret = query.exec(qstl);
        if (!ret)
        {
            QMessageBox::critical(nullptr, "create table songhistory", db.lastError().text());
        }

       // // 查询歌曲历史记录表中的数据并显示
        qstl = "select * from songhistory";
        QStringList musicList;
        if (!query.exec(qstl)) // 执行查询操作
        {
            // 查询失败，显示错误信息
            QMessageBox::critical(nullptr, "错误", db.lastError().text());
        }
        while (query.next()) // 遍历查询结果
        {
            QString fileName = query.value(1).toString();
            QString musicPath = query.value(2).toString();
            musicList.append(fileName);
            playList.append(QUrl::fromLocalFile(musicPath));
            randomList.append(playList.size()-1);
            if(randomList.size()!=1)
            {
                int randomId=rand()%(randomList.size()-1);
                int tmp=randomList[randomId];
                randomList[randomId]=randomList[randomList.size()-1];
                randomList[randomList.size()-1]=tmp;
            }
        }
        ui->listWidget->addItems(musicList);
        if(playList.size()!=0)
            ui->listWidget->setCurrentRow(0);
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql;

    QStringList musicList;
    QStringList musicPathList = QFileDialog::getOpenFileNames(this, tr("选择音频文件"), tr("F:\\music"), tr("Music(*.mp3 *.wav)"));
    for (int i = 0; i < musicPathList.size(); i++)
    {
        QString musicPath = musicPathList[i];
        QFileInfo file = QFileInfo(musicPath);
        QString fileName = file.fileName();
        musicList.append(fileName);
        qInfo()<<musicPath;
        qInfo()<<fileName;

        sql = QString("select musicPath from songhistory where musicPath = '%1';").arg(musicPath);
        if(!query.exec(sql))
        {
            QMessageBox::critical(nullptr,"select hash from songhistory where musicPath =",db.lastError().text());
        }
        if(query.next()==NULL)
        {
            ui->listWidget->addItem(fileName);
            sql = QString("insert into songhistory values(NULL,'%1','%2')").arg(fileName).arg(musicPath);
            if(!query.exec(sql))
            {
                QMessageBox::critical(nullptr,"insert error",db.lastError().text());
            }
            playList.append(QUrl::fromLocalFile(musicPath));
            randomList.append(playList.size()-1);
            if(randomList.size()!=1)
            {
                int randomId=rand()%(randomList.size()-1);
                int tmp=randomList[randomId];
                randomList[randomId]=randomList[randomList.size()-1];
                randomList[randomList.size()-1]=tmp;
            }
        }
    }
    // 默认选中第一个音乐
    // ui->listWidget->setCurrentRow(0);
    // 把音乐的完整路径保存起来
    // for(auto file:musicPathList)
    // {
    //     playList.append(QUrl::fromLocalFile(file));
    //     randomList.append(playList.size()-1);
    //     if(randomList.size()!=1)
    //     {
    //         int randomId=rand()%(randomList.size()-1);
    //         int tmp=randomList[randomId];
    //         randomList[randomId]=randomList[randomList.size()-1];
    //         randomList[randomList.size()-1]=tmp;
    //     }
    // }

}


void Widget::on_pushButton_4_clicked()
{
    if(playList.empty())
    {
        return;
    }

    switch(mediaPlayer->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState: //停止状态
    {
        // 播放当前选中的音乐
        //1、获取选中的行号
        curPlayIndex = ui->listWidget->currentRow();
        //2、播放对应下标的音乐
        mediaPlayer->setSource(playList[curPlayIndex]);
        mediaPlayer->play();
        this->ui->pushButton_4->setStyleSheet("icon:url(:/Play.png)");
        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState://播放状态
    {
        // 如果现在正在播放，暂停播放
        mediaPlayer->pause();
        this->ui->pushButton_4->setStyleSheet("icon:url(:/Pause.png)");
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState://暂停状态
    {
        //如果现在是暂停的,继续播放音乐
        mediaPlayer->play();
        this->ui->pushButton_4->setStyleSheet("icon:url(:/Play.png)");
        break;
    }
    }
}

//上一曲
void Widget::on_pushButton_3_clicked()
{
    if(playList.empty())
    {
        return;
    }
    if(curPlayIndex == 0)
        curPlayIndex = playList.size() - 1;
    else
        curPlayIndex = (curPlayIndex - 1) % playList.size();
    this->ui->pushButton_4->setStyleSheet("icon:url(:/Play.png)");
    playMode-=3;
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//下一曲
void Widget::on_pushButton_5_clicked()
{
    if(playList.empty())
    {
        return;
    }
    // curPlayIndex++;
    // if(curPlayIndex >= playList.size())
    // {
    //     curPlayIndex = 0;
    // }
    curPlayIndex = (curPlayIndex + 1) % playList.size();
    playMode-=3;
    this->ui->pushButton_4->setStyleSheet("icon:url(:/Play.png)");
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}


void Widget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    this->ui->pushButton_4->setStyleSheet("icon:url(:/Play.png)");
    playMode-=3;
    curPlayIndex = index.row();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}


void Widget::on_pushButton_2_clicked()
{
    if(playMode==1)
    {
        playMode=0;
        this->ui->pushButton_2->setStyleSheet("border:none;icon:url(:/Cycle.png)");
    } else
    {
        playMode=1;
        this->ui->pushButton_2->setStyleSheet("border:1px solid rgb(128,128,128);icon:url(:/Cycle.png)");
        this->ui->pushButton_6->setStyleSheet("border:none;icon:url(:/Random.png)");
    }

}


void Widget::on_pushButton_6_clicked()
{
    if(playMode==2)
    {
        playMode=0;
        this->ui->pushButton_6->setStyleSheet("border:none;icon:url(:/Random.png)");
    } else
    {
        playMode=2;
        this->ui->pushButton_6->setStyleSheet("border:1px solid rgb(128,128,128);icon:url(:/Random.png)");
        this->ui->pushButton_2->setStyleSheet("border:none;icon:url(:/Cycle.png)");
    }
}
void Widget::playNext()
{
    if(playMode<0)
    {
        playMode+=3;
        return;
    }
    if(mediaPlayer->playbackState()!=QMediaPlayer::PlaybackState::StoppedState)
    {
        return;
    }
    if(playMode!=1)
    {
        curPlayIndex = (curPlayIndex + 1) % playList.size();
    }
    if(playMode==2&&curPlayIndex%2==0)
    {
        int id1=rand()%randomList.size();
        int id2=rand()%randomList.size();
        int tmp=randomList[id1];
        randomList[id1]=randomList[id2];
        randomList[id2]=tmp;
    }
    if(playMode==2)
    {
        ui->listWidget->setCurrentRow(randomList[curPlayIndex]);
        mediaPlayer->setSource(playList[randomList[curPlayIndex]]);
    } else
    {
        ui->listWidget->setCurrentRow(curPlayIndex);
        mediaPlayer->setSource(playList[curPlayIndex]);
    }
    mediaPlayer->play();
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
     audioOutput->setVolume((float)value/100+0.005);
    ui->label->setText(QString::number(value));
}

