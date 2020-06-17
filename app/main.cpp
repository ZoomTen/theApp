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

#define APP_VERSION "0.01"

// UI includes
#include "mainwindow.h"

// Qt includes
#include <QDir>
#include <QStandardPaths>

// the-libs includes
#include <tsettings.h>
#include <tapplication.h>

// settings
#include <tsettings.h>


int main(int argc, char* argv[]) {
    tApplication a(argc, argv);
    
    // application name
#ifdef T_BLUEPRINT_BUILD
    a.setApplicationName("theApp-Blueprint");
    a.setDesktopFileName("com.zumid.theApp");
#else
    a.setApplicationName("theApp");
    a.setDesktopFileName("com.zumid.theApp");
#endif
    
    // version
    a.setApplicationVersion("0.01");
    
    // app icons
    a.setApplicationIcon(QIcon::fromTheme("theApp", QIcon(":/icons/theApp.svg")));
    
    // splash screen graphic
    a.setAboutDialogSplashGraphic(a.aboutDialogSplashGraphicFromSvg(":/icons/theApp-aboutside.svg"));
    
    // generic name
    a.setGenericName(QApplication::tr("Basic application"));
    
    // license
    a.setApplicationLicense(tApplication::Gpl3OrLater);

    // copyright
    a.setCopyrightHolder("Zumi Daxuya");
    a.setCopyrightYear("2020");

    // suite name
    a.setOrganizationName("theSuite Contrib");

    // set share path
    QString sharePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (QDir(sharePath).exists()) {
        a.setShareDir(sharePath); // use local share dir.
    } else {
        a.setShareDir("/usr/share/theApp/"); // use global system dir (LINUX)
    }
    
    // set defaults file
    QString defaultsPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    defaultsPath += "/defaults.conf";
    tSettings::registerDefaults(defaultsPath);   // use local config dir
    tSettings::registerDefaults("/etc/theApp/defaults.conf"); // use global conifg dir (LINUX)
    
    // setup i18n
    a.installTranslators();
    
    // run app
    MainWindow w;
    w.show();

    return a.exec();
}
