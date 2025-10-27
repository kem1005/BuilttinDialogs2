#include "cbuiltindlg.h"
#include <QtWidgets>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/qpagesetupdialog.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>

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
    connect(errorPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(fontPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(inputPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(pagePushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(progressPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(printPushBth,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(displayTextEdit,SIGNAL(clicked()),this,SLOT(doPushBth()));
    connect(testPushBth,SIGNAL(clicked()),this,SLOT(dotextcolor()));

}
cbuiltindlg::~cbuiltindlg(){}

void cbuiltindlg :: dotextcolor()
{
    QPushButton* bth = qobject_cast<QPushButton*>(sender());
    if(bth == testPushBth)
    {
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color (QPalette:: ToolTipBase),this, tr("設定前景顏色"));
        if (color.isValid())
            palette.setColor(QPalette:: Text, color); displayTextEdit->setPalette (palette);
    }
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

    if (bth == errorPushBth)
    {
        QErrorMessage box(this);
        box.setWindowTitle (QStringLiteral("錯誤訊息盒"));
        box.showMessage (QStringLiteral("錯誤訊息盒實例xx。"));
        box.exec();
        box.showMessage (QStringLiteral("錯誤訊息盒實例yy。"));
        box.exec();
        box.showMessage (QStringLiteral("錯誤訊息盒實例zz:"));
        box.exec();
    }

    if(bth == filePushBth)
    {
        QString fileName = QFileDialog::getOpenFileName(this,tr("開啟檔案"),".",
                                                        tr("任何檔案(*.*)"
                                                           ";;文字檔(*.txt)"
                                                           ";;XML檔(*.xml)"));
    displayTextEdit->setText(fileName);
    }


    if (bth == fontPushBth)
    {   bool o;
        const QFont& font = QFontDialog::getFont(& o ,
                                             displayTextEdit->font(),
                                           this,
                                           tr("字體對話盒"));
    if (o) displayTextEdit->setFont(font);
    }
    if (bth == inputPushBth){
        bool ok;
    QString text = QInputDialog::getText(this,
                                         QStringLiteral("輸入對話盒"),
                                         QStringLiteral("輸入文字"),
                                         QLineEdit:: Normal,
                                         QDir::home().dirName(), &ok
                                         );
    if (ok && !text.isEmpty()) displayTextEdit->setText(text);
    }
    if (bth == pagePushBth){
        QPrinter printer (QPrinter:: HighResolution);
        QPageSetupDialog *dlg = new QPageSetupDialog (&printer, this);
        dlg->setWindowTitle (tr("頁面設定話方塊"));
        if (dlg->exec()== QDialog:: Accepted)
        {

        }
    }
    if (bth == progressPushBth){

        QProgressDialog progress (QStringLiteral("正在複製檔案..."),
                                 QStringLiteral("取消"),0,10000,this);
        progress.setWindowTitle (QStringLiteral("進度對話方塊"));
        progress.show();
        for (int i = 0 ; i < 10000 ; i++){
            progress.setValue(i);
        qApp->processEvents();
        if (progress.wasCanceled())
            break;
        qDebug() << i;
    }
    progress.setValue (10000);
    }
    if (bth == printPushBth)
    {
        QPrinter printer (QPrinter:: HighResolution);
        QPrintDialog dialog(&printer, this);
        if (dialog.exec() != QDialog:: Accepted)
            return;
    }
}

