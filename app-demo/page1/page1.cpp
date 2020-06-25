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


// This is the simplest widget definition

#include "page1.h"      // for the functions defined here
#include "ui_page1.h"   // for Qt Designer stuff

struct Page1Private{
    // put your variables here
    // these will be accessible thru d->variable
};

Page1::Page1(QWidget* parent) :
  QWidget(parent), ui(new Ui::Page1) {
    // set up window
    ui->setupUi(this);
    d = new Page1Private();
}

Page1::~Page1() {
    // on destroy
    delete d;
    delete ui;
}

/***** functions *****/

// mainwindow.cpp uses these to control each page's text

void Page1::setHeading(QString text){
    ui->heading->setText(text);
}

void Page1::setBody(QString text){
    ui->contents->setText(text);
}
