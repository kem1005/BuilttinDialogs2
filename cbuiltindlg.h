#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class cbuiltindlg;
}
QT_END_NAMESPACE

class cbuiltindlg : public QDialog
{
    Q_OBJECT

public:
    cbuiltindlg(QWidget *parent = nullptr);
    ~cbuiltindlg();

private:
    QTextEdit    *displayTextEdit;
    QPushButton  *colorPushBth;
    QPushButton  *errorPushBth;
    QPushButton  *filePushBth;
    QPushButton  *fontPushBth;
    QPushButton  *inputPushBth;
    QPushButton  *pagePushBth;
    QPushButton  *progressPushBth;
    QPushButton  *printPushBth;
};
#endif // CBUILTINDLG_H
