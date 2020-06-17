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

#include "page2_popover.h"
#include "ui_page2_popover.h"

Page2Popover::Page2Popover(QWidget* parent) :
  QWidget(parent), ui(new Ui::Page2Popover) {
    // setup widget
    ui->setupUi(this);

    // d = new Page1PopoverPrivate();
    ui->titleLabel->setBackButtonShown(true); // enable back button
}

Page2Popover::~Page2Popover() {
    // on delete
    delete ui;
}

void Page2Popover::on_titleLabel_backButtonClicked() {
    // pressed the back button
    emit done();
}
