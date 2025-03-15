#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int keyboardChoice = ui->KeyboardLayout->currentIndex();
    QString  layout;
    switch(keyboardChoice){
        case 0:
            layout = "cs_CZ_102";
            break;
        case 1:
            layout = "da_DK_102";
            break;
        case 2:
            layout = "de_CH_102";
            break;
        case 3:
            layout = "en_CA_101";
            break;
        case 4:
            layout = "en_CA_101_dvorak";
            break;
        case 5:
            layout = "en_GB_102";
            break;
        case 6:
            layout = "en_US_101";
            break;
        case 7:
            layout = "en_US_101_dvorak";
            break;
        case 8:
            layout = "es_ES_102";
            break;
        case 9:
            layout = "fr_BE_102";
            break;
        case 10:
            layout = "fr_CA_102";
            break;
        case  11:
            layout = "fr_CH_102";
            break;
        case 12:
            layout = "fr_FR_102";
            break;
        case 13:
            layout = "hr_HR_102";
            break;
        case  14:
            layout = "it_IT_102";
            break;
        case 15:
            layout = "ja_JP_106";
            break;
        case 16:
            layout = "nl_NL_102";
            break;
        case 17:
            layout = "no_NO_102";
            break;
        case 18:
            layout = "pl_PL_102";
            break;
        case 19:
            layout = "pt_PT_102";
            break;
        case 20:
            layout = "se_SE_102";
            break;
        default:
            layout = "sk_SK_102";
    }
    QString resolution = ui->Resolution->currentText();
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    bool camera = true;
    if(ui->Hardware->isChecked()){
        camera = true;
    }else if(ui->Simulated->isChecked()){
        camera = false;
    }

    qInfo() << layout;
}

