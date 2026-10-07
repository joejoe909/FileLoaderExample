#include "filenotificationdialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>

FileNotificationDialog::FileNotificationDialog(const QString &message,
                                               int autoCloseMs,
                                               QWidget *parent)
    : QDialog(parent)
    , m_label(new QLabel(message, this))
    , m_progressBar(new QProgressBar(this))
    , m_timer(new QTimer(this))
    , m_closeTimer(new QTimer(this))
    , m_remainingMs(autoCloseMs)
    , m_totalMs(autoCloseMs)
{
    setWindowTitle("Loading...");
    setModal(true);
    setFixedSize(420, 140);

    // Remove the "?" help button from the title bar
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    m_label->setAlignment(Qt::AlignCenter);
    m_label->setStyleSheet("font-size: 13px; font-weight: bold;");
    m_label->setWordWrap(true);

    m_progressBar->setRange(0, m_totalMs);
    m_progressBar->setValue(m_totalMs);
    m_progressBar->setTextVisible(false);
    m_progressBar->setFixedHeight(14);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_progressBar);

    // Progress tick: update every 100 ms for a smooth bar
    m_timer->setInterval(100);
    connect(m_timer, &QTimer::timeout, this, &FileNotificationDialog::onTick);
    m_timer->start();

    // Single-shot: close the dialog after autoCloseMs
    m_closeTimer->setSingleShot(true);
    m_closeTimer->setInterval(autoCloseMs);
    connect(m_closeTimer, &QTimer::timeout, this, &QDialog::accept);
    m_closeTimer->start();
}

FileNotificationDialog::~FileNotificationDialog() = default;

void FileNotificationDialog::onTick()
{
    m_remainingMs -= 100;
    if (m_remainingMs < 0)
        m_remainingMs = 0;

    m_progressBar->setValue(m_remainingMs);

    double secondsLeft = m_remainingMs / 1000.0;
    m_label->setText(m_label->text().section('\n', 0, 0) +
                     QString("\nClosing in %1 s...").arg(secondsLeft, 0, 'f', 1));
}
