#include "cbuiltindlg.h"
#include <QtWidgets>

cbuiltindlg::cbuiltindlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt的標準對話盒"));
    colorPushBth = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBth = new QPushButton(QStringLiteral("錯誤對話盒"));
    filePushBth = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBth = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBth = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBth = new QPushButton(QStringLiteral("頁面設計對話盒"));
    progressPushBth = new QPushButton(QStringLiteral("進度對話盒"));
    printPushBth = new QPushButton(QStringLiteral("列印對話盒"));
    testPushBth = new QPushButton(QStringLiteral("前景對話盒"));

    gridLayout->addWidget(colorPushBth,0,0,1,1);
    gridLayout->addWidget(errorPushBth,0,1,1,1);
    gridLayout->addWidget(filePushBth,0,2,1,1);
    gridLayout->addWidget(fontPushBth,1,0,1,1);
    gridLayout->addWidget(inputPushBth,1,1,1,1);
    gridLayout->addWidget(pagePushBth,1,2,1,1);
    gridLayout->addWidget(progressPushBth,2,0,1,1);
    gridLayout->addWidget(printPushBth,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);
    gridLayout->addWidget(testPushBth,2,2,1,1);

    setLayout(gridLayout);
    setWindowTitle(tr("內建對話盒展示"));
    resize(400,300);
    connect(colorPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(filePushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
}
cbuiltindlg::~cbuiltindlg()
{
}
void cbuiltindlg :: doPushBth()
{
    QPushButton* bth = qobject_cast<QPushButton*>(sender());
    if(bth == colorPushBth)
    {
        //qDebug()<< "hello";
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
        QColorDialog::getColor(palette.color (QPalette:: Base),this, tr("設定背景顏色"));
        if (color.isValid())
            palette.setColor(QPalette:: Base, color); displayTextEdit->setPalette (palette);
    }
    if(bth == filePushBth)
    {
        QString fileName = QFileDialog::getOpenFileName(this,tr("開啟檔案"),".",
                                                        tr("任何檔案(*.*)"
                                                           ";;文字檔(*.txt)"
                                                           ";;XML檔(*.xml)"));
    }
}

