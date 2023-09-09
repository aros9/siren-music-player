#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create media and audio player objects
    mediaPlayer = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    // Change buttons icons
    ui->buttonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->buttonPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    // Set audioPlayer for mediaPlayer
    mediaPlayer->setAudioOutput(audioOutput);
    // connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(play()));

    // Set source for mediaPlayer (TEMPORARY ONLY ONE FILE FROM MUSIC FILES!!)
    mediaPlayer->setSource(QUrl::fromLocalFile("music/imagine_dragons_bones.mp3"));

    // Set starting volume as the one from slider
    audioOutput->setVolume(ui->musicVolumeSlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mediaPlayer;
    delete audioOutput;
}

void MainWindow::on_buttonPlay_clicked()
{
    mediaPlayer->play();
}


void MainWindow::on_buttonPause_clicked()
{
    mediaPlayer->stop();
}


void MainWindow::on_musicVolumeSlider_valueChanged(int value)
{
    audioOutput->setVolume(value);
}

