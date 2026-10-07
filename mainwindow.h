#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

QT_BEGIN_NAMESPACE
class QTextEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGenerateFilesClicked();
    void onLoadFilesClicked();

private:
    bool generateRandomDatFiles(const QString &dir, int count = 3, int linesPerFile = 20);
    void appendSeparator(const QString &title);

    QTextEdit *m_textEdit;
    QPushButton *m_generateButton;
    QPushButton *m_loadButton;
    QLabel *m_statusLabel;
    QStringList m_generatedFiles;
};

#endif // MAINWINDOW_H
