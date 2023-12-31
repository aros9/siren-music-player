#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonPlay_clicked();

    void on_buttonPause_clicked();

    void on_musicVolumeSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
};
#endif // MAINWINDOW_H
