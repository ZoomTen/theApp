/****************************************
 *
 *   theApp - Example 3rd-party application for theShell
 *   Copyright (C) 2020 Zumi Daxuya
 *
 *   Based on the24 (C) 2020 Victor Tran
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * *************************************/

// A widget gallery

#include "page2.h"
#include "ui_page2.h"

// the-libs
#include <the-libs_global.h>

// display pop-over
#include <tpopover.h>
#include "popover/page2_popover.h"

// display toast
#include <ttoast.h>

// display notifications
#include <tnotification.h>

// element flashing
#include <terrorflash.h>

// message box
#include <tmessagebox.h>

// system sounds
#include <tsystemsound.h>

struct Page2Private{
    // put your variables here
    // these will be accessible thru d->variable
};

Page2::Page2(QWidget* parent) :
  QWidget(parent), ui(new Ui::Page2) {
    // set up window
    ui->setupUi(this);
    d = new Page2Private();
}

Page2::~Page2() {
    // on destroy
    delete d;
    delete ui;
}
/***** actions *****/

// click "popover" button
void Page2::on_popoverButton_clicked() {
    // generate popover
    // by instantiating a widget and then using it as the popover object
    Page2Popover* pwidget = new Page2Popover(this);
    tPopover* popover = new tPopover(pwidget);
    
    // set popover width
    // 80% of the widget width
    popover->setPopoverWidth(this->width() * 0.8);
    
    // set click event
    connect(pwidget, &Page2Popover::done, popover, &tPopover::dismiss);
    
    // delete popover after it has been shown
    // delete popover object
    connect(popover, &tPopover::dismissed, popover, &tPopover::deleteLater);
    // delete popover widget
    connect(popover, &tPopover::dismissed, pwidget, &Page2Popover::deleteLater);
    
    // show popover
    // this popover only covers the currently displayed page, not the entire app
    popover->show(this);
}


// click "toast" button
// toast = a simple, in-app notification
void Page2::on_toastButton_clicked() {
    // generate toast
    tToast* toast = new tToast(this);
    
    // set toast contents
    toast->setTitle(tr("You know what they say..."));
    toast->setText(tr("All toasters toast toast :p"));
    
    // set duration
    toast->setTimeout(3000); // 3 seconds
    
    // delete toast after it has been shown
    connect(toast, &tToast::dismissed, toast, &tToast::deleteLater);
    
    // show toast
    // this toast only covers the currently displayed page, not the entire app
    toast->show(this);
//    toast->show(this->window()); // if you want the toast to be applied to the entire app
}


// click "flash" button
void Page2::on_errorFlashButton_clicked() {
    // make the clicked button flash red
    // apparently it only works on some widget themes
    tErrorFlash::flashError(ui->errorFlashButton);
}


// click "notification" button
void Page2::on_notificationButton_clicked() {
    // set up notification
    tNotification* notification = new tNotification();
    
    // fill in the details
    notification->setAppName("theApp");
    notification->setSummary(tr("This is a notification"));
    notification->setText(tr("May I have your attention, please?"));
    notification->setCategory("x-thesuite-contrib.theapp.test-notification");
    
    // add action
    notification->insertAction("confirm", tr("I'm awake"));
    
    // make the action do something in the app
    connect(notification, &tNotification::actionClicked,
            this,         [ = ](QString action){
            // do something
            if(action == "confirm"){
                on_toastButton_clicked(); // call the toast function
            }
        }
    );

    // run the notification
    notification->post(true);
}


// click "message" button
void Page2::on_messageButton_clicked() {
    // set up message box
    tMessageBox* msg = new tMessageBox(this);
    
    // fill in the details
    msg->setWindowTitle(tr("I'm a robot"));
    msg->setText(tr("Beep boop"));
    msg->setIcon(tMessageBox::Warning);
    msg->setWindowFlags(Qt::Sheet);
    
    // add actions
    msg->setStandardButtons(tMessageBox::Ok | tMessageBox::Cancel);
    msg->setDefaultButton(tMessageBox::Cancel);
    
    // run
    int selection = msg->exec();
    
    // process selection
    if (selection == tMessageBox::Ok){
        on_toastButton_clicked(); // call the toast function if user clicked ok
    }
    
    msg->deleteLater();
}


// click "sound" button
void Page2::on_soundButton_clicked() {
    // play bell sound
    tSystemSound::play("bell");
}


// set page transition type
void Page2::on_pt_Fade_toggled(bool toggled) {
    if (toggled){
        emit setTransitionType(1);
    }
}
void Page2::on_pt_SlideLeft_toggled(bool toggled) {
    if (toggled){
        emit setTransitionType(2);
    }
}
void Page2::on_pt_SlideUp_toggled(bool toggled) {
    if (toggled){
        emit setTransitionType(3);
    }
}


/***** functions *****/

// MainWindow uses these to control each page's text

void Page2::setHeading(QString text){
    ui->heading->setText(text);
}

void Page2::setBody(QString text){
    ui->contents->setText(text);
}
