#include "cbuiltindlg.h"
#include <QGridLayout>

cbuiltindlg::cbuiltindlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gredLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt的標準對話盒"));
    colorPushBth = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBth = new QPushButton(QStringLiteral("錯誤對話盒"));
    filePushBth = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBth = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBth = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBth = new QPushButton(QStringLiteral("頁面設計對話盒"));
    progressPushBth = new QPushButton(QStringLiteral("進度對話盒"));
    printPushBth = new QPushButton(QStringLiteral("列印對話盒"));
}
cbuiltindlg::~cbuiltindlg()
{
}
