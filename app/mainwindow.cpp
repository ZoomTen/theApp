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

// window
#include "mainwindow.h"
#include "ui_mainWindow.h"

// menu items
#include <QMenu>

// opening URLs
#include <QDesktopServices>
#include <QUrl>

// about dialog
#include <taboutdialog.h>

// the-libs CSD
#include <tcsdtools.h>

struct MainWindowPrivate {
    tCsdTools csd;
};

MainWindow::MainWindow(QWidget* parent):
  QMainWindow(parent), ui(new Ui::MainWindow) {
    // setup window
    ui->setupUi(this);
    d = new MainWindowPrivate();
    
    // register CSD actions
    d->csd.installMoveAction(ui->topWidget);
    d->csd.installResizeAction(this);
    
    // CSD layout
    /*ui->rightCsdLayout->addWidget(d->csd.csdBoxForWidget(this));
    
    if (tCsdGlobal::windowControlsEdge() == tCsdGlobal::Left) {
        // left window controls
        ui->topWidget->setLayoutDirection(Qt::RightToLeft);
	ui->leftCsdLayout->setDirection(QBoxLayout::RightToLeft);
        ui->bodyWidget->setLayoutDirection(Qt::RightToLeft);
    } else {
        // right window controls
        ui->topWidget->setLayoutDirection(Qt::LeftToRight);
        ui->bodyWidget->setLayoutDirection(Qt::LeftToRight);
    }*/
    
    if (tCsdGlobal::windowControlsEdge() == tCsdGlobal::Left) {
        ui->leftCsdLayout->insertWidget(0,d->csd.csdBoxForWidget(this));
    } else {
        ui->rightCsdLayout->addWidget(d->csd.csdBoxForWidget(this));
    }

    // icon menu
    QMenu* menu = new QMenu(this);

    QMenu* fileMenu = new QMenu(this);
    fileMenu->setTitle(tr("File"));
    fileMenu->addAction(ui->actionNew);  // New
    fileMenu->addAction(ui->actionOpen); // Open
    fileMenu->addSeparator();
    fileMenu->addAction(ui->actionSave);  // Save
    fileMenu->addAction(ui->actionSave_As); // Save As...
    menu->addMenu(fileMenu);                // add File submenu (non-functional)
    
    QMenu* helpMenu = new QMenu(this);
    helpMenu->setTitle(tr("Help"));
    helpMenu->addAction(ui->actionFileBug); // File a bug
    helpMenu->addAction(ui->actionSources); // Source code link
    helpMenu->addSeparator();
    helpMenu->addAction(ui->actionAbout);   // call About page
    menu->addMenu(helpMenu);                // add Help submenu
    
    menu->addAction(ui->actionExit);        // Exit item

    ui->menuButton->setIconSize(SC_DPI_T(QSize(24, 24), QSize));
    ui->menuButton->setFixedSize(SC_DPI(42), QWIDGETSIZE_MAX);
    ui->menuButton->setMenu(menu);
    
    // page animation
    ui->stackedWidget->setCurrentAnimation(tStackedWidget::Fade);
    
    // page 1 contents
    ui->page1->setHeading(tr("Hello World!"));
    ui->page1->setBody(tr("This is a sample custom third-party app that uses theSuite library. This page is the simplest widget here.\n\n\"Where's the menu?\" I hear you say. \"Why, click on the question mark logo at the top,\" I reply."));
    
    // page 2 contents
    ui->page2->setHeading(tr("Widget Gallery"));
    ui->page2->setBody(tr("A testing playground, for all your testing needs."));
    
    // apply the transition type functionality
    connect(ui->page2, &Page2::setTransitionType, this, &MainWindow::applyTransitionSetting);
}

MainWindow::~MainWindow() {
    // upon unload
    delete d;
    delete ui;
}

/***** actions *****/

// exit
void MainWindow::on_actionExit_triggered() {
    QApplication::exit();
}

// help actions
void MainWindow::on_actionSources_triggered() {
    // open source code page
    QDesktopServices::openUrl(QUrl("http://github.com/ZoomTen/theApp"));
}

void MainWindow::on_actionFileBug_triggered() {
    // open issue tracker
    QDesktopServices::openUrl(QUrl("http://github.com/ZoomTen/theApp/issues"));
}

void MainWindow::on_actionAbout_triggered() {
    // open the library-provided about dialog
    tAboutDialog d;
    d.exec();
}

// application actions
void MainWindow::on_pageList_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}

// resize action
void MainWindow::resizeEvent(QResizeEvent *event) {
    // Automatically adjust sidebar size
    if (this->width() < SC_DPI(800)) {
        // collapse sidebar
        ui->pageList->setMaximumSize(SC_DPI(42), QWIDGETSIZE_MAX);
    } else {
        // expand sidebar
        ui->pageList->setMaximumSize(SC_DPI(180), QWIDGETSIZE_MAX);
    }
}

/***** custom slots *****/

// apply transition setting which is set from Page2::setTransitionType
void MainWindow::applyTransitionSetting(int type){
    switch(type){
        case 1:
            ui->stackedWidget->setCurrentAnimation(tStackedWidget::Fade);
            break;
        case 2:
            ui->stackedWidget->setCurrentAnimation(tStackedWidget::SlideHorizontal);
            break;
        case 3:
            ui->stackedWidget->setCurrentAnimation(tStackedWidget::Lift);
            break;
        default:
            break;
    }
}
