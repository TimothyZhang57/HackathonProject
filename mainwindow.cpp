#include "mainwindow.h"
#include "SSHClient.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  // login(username, password);
  updateSettings();
}
void MainWindow::login(QString username, QString password) {
  bool successful;
  QMessageBox result;
  if (successful == true) {
    updateSettings();
    result.setText("Logged In");
    result.exec();
  } else {
    result.setText("Incorrect Credentials");
    result.exec();
  }
}
void MainWindow::updateSettings() {
  int keyboardChoice = ui->KeyboardLayout->currentIndex();
  QString layout;
  switch (keyboardChoice) {
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
  case 11:
    layout = "fr_CH_102";
    break;
  case 12:
    layout = "fr_FR_102";
    break;
  case 13:
    layout = "hr_HR_102";
    break;
  case 14:
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
  if (ui->Hardware->isChecked()) {
    camera = true;
  } else if (ui->Simulated->isChecked()) {
    camera = false;
  }

  // Implementation of Keyboard Layout and Video Resolution Change in
  // graphics-rpi4.conf
  qDebug() << "Keyboard";
  string lo = layout.toStdString();
  string vr = resolution.toStdString();
  string graphicsconf = std::format(
      "begin khronos\n \n begin egl display 1\n egl-dlls = libglapi-mesa.so "
      "libEGL-mesa.so\n "
      "glesv2-dlls = libglapi-mesa.so libGLESv2-mesa.so\n gpu-dlls = "
      "gpu_drm-rpi4.so\n vk-icds = "
      "broadcom_icd.json\n vk-exps = "
      "/usr/lib/graphics/vulkan/VkLayer_khronos_validation.json\n "
      "end egl display\n \n begin wfd device 1\n wfd-dlls = "
      "libwfdcfg-rpi4-generic.so "
      "libWFDrpi4-drm-atomic.so\n \n # Run \"drm-probe-displays\" to list the "
      "available displays "
      "and pipelines,\n # and \"use $GRAPHICS_ROOT/libWFDrpi4-drm.so\" for "
      "more information on\n "
      "# these driver-specific settings.\n \n # Here is displays map for "
      "Raspberry Pi 4:\n # "
      "display 1: HDMI-A\n # display 2: HDMI-A\n \n # Pipeline IDs 1 to 9 are "
      "used for DRM "
      "CRTCs.  One should be assigned\n # to each display that will be used.\n "
      "pipeline1-display "
      "= 1\n # pipeline2-display = 2\n end wfd device\n \n end khronos\n \n "
      "begin winmgr\n \n "
      "begin globals\n default-display = 1\n stack-size = 65536  # in units of "
      "bytes\n "
      "blit-config = rpi4drm\n alloc-config = rpi4drm\n requests-logsize = "
      "65536\n blits-logsize "
      "= 4096\n input = keyboard mouse\n keymap = /system/share/keyboard/{}\n "
      "end globals\n \n "
      "begin display 1\n video-mode = {} @ 60\n stack-size = 65536  # in units "
      "of bytes\n "
      "force-composition = true\n cursor = on # has to be on, otherwise it "
      "takes 10s to "
      "initializen\n end display\n \n #   begin display 2\n #     video-mode = "
      "1920 x 1080 @ "
      "60\n #     stack-size = 65536  # in units of bytes\n #    "
      "force-composition = true\n #   "
      "end display\n \n begin class framebuffer-1\n display = 1\n pipeline = "
      "1\n buffer-count = "
      "3\n format = rgba8888\n usage = gles2blt physical\n #usage = rpi4drm "
      "physical\n end "
      "class\n \n #   begin class framebuffer-2\n #     display = 2\n #     "
      "pipeline = 2\n #     "
      "buffer-count = 3\n #     format = rgba8888\n #     usage = rpi4drm "
      "physical\n #   end "
      "class\n \n end winmgr\n",
      lo, vr);
  qDebug() << graphicsconf;
  string cameraconf;
  if (camera) {
    cameraconf = std::format("HOSTNAME=qnxpi \n USE_DEMO_SENSOR={}", "true");
  } else {
    cameraconf = std::format("HOSTNAME=qnxpi \n USE_DEMO_SENSOR={}", "false");
  }

  QString username = ui->Username->text();
  QString password = ui->Password->text();
  QString address = ui->Address->text();
  string u = username.toStdString();
  string p = password.toStdString();
  string a = address.toStdString();
  qDebug() << p;
  SSHClient rpi(u, p, a);
  rpi.connect();
  rpi.sendCommand(std::format(
      "echo \"{}\" > /system/lib/graphics/rpi4-drm/graphics-rpi4.conf",
      graphicsconf));
  rpi.sendCommand(
      std::format("echo \"{}\" > /boot/qnx_config.txt", cameraconf));
  QMessageBox msgBox;
  msgBox.setText("Settings Updated");
  msgBox.exec();
}
