#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    //login(username, password);
    updateSettings();
}
void MainWindow::login(QString username, QString password){
    bool successful;
    QMessageBox result;
    if(successful == true){
        updateSettings();
        result.setText("Logged In");
        result.exec();
    }else{
        result.setText("Incorrect Credentials");
        result.exec();
    }
}
void MainWindow::updateSettings(){
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
    bool camera = true;
    if(ui->Hardware->isChecked()){
        camera = true;
    }else if(ui->Simulated->isChecked()){
        camera = false;
    }

    //Implementation of Keyboard Layout and Video Resolution Change in graphics-rpi4.conf
    const string graphicsconf = "graphics-rpi4.conf";
    ofstream outs(graphicsconf);
    const string graphics1 = "graphics1.txt";
    ifstream ins1(graphics1);
    string line;
    while (getline(ins1, line)){
        outs << line << "\n";
    }
    ins1.close();
    string lo =layout.toStdString();
    string vr =resolution.toStdString();
    string changes = "keymap = /system/share/keyboard/" + lo + "\n end globals" +"\n begin display 1" + "\n video-mode = " + vr +" @ 60\n";
    outs << changes;
    const string graphics2 = "graphics2.txt";
    ifstream ins2(graphics2);
    while (getline(ins2, line)){
        outs << line << "\n";
    }
    ins2.close();
    outs.close();

    //Implementation of Camera switch
    const string config = "qnx_config.txt";
    ofstream cameraouts(config);
    string cameraconf;
    if(camera){
        cameraconf = "HOSTNAME=qnxpi \n USE_DEMO_SENSOR=true";
    }
    else{
        cameraconf = "HOSTNAME=qnxpi \n USE_DEMO_SENSOR=false";
    }
    cameraouts << cameraconf;
    cameraouts.close();
}
