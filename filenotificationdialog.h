#ifndef FILENOTIFICATIONDIALOG_H
#define FILENOTIFICATIONDIALOG_H

#include <QDialog>
#include <QTimer>

class QLabel;
class QProgressBar;

class FileNotificationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileNotificationDialog(const QString &message,
                                    int autoCloseMs = 8000,
                                    QWidget *parent = nullptr);
    ~FileNotificationDialog();

private slots:
    void onTick();

private:
    QLabel *m_label;
    QProgressBar *m_progressBar;
    QTimer *m_timer;
    QTimer *m_closeTimer;
    int m_remainingMs;
    int m_totalMs;
};

#endif // FILENOTIFICATIONDIALOG_H
