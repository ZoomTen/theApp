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

#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

namespace Ui {
    class Page2;
}

class Page2 : public QWidget {
        Q_OBJECT

    public:
        explicit Page2(QWidget* parent = nullptr);
        ~Page2();
        
        void setHeading(QString text);
        void setBody(QString text);
    
    private slots:
        // app actions
        void on_popoverButton_clicked();
        void on_toastButton_clicked();
        void on_errorFlashButton_clicked();
        void on_notificationButton_clicked();
        void on_messageButton_clicked();
        void on_soundButton_clicked();
        
        // radio button actions
        void on_pt_Fade_toggled(bool toggled);
        void on_pt_SlideLeft_toggled(bool toggled);
        void on_pt_SlideUp_toggled(bool toggled);
        
    private:
        Ui::Page2* ui;
    
    signals:
        // this will be sent to MainWindow::applyTransitionSetting
        void setTransitionType(int type);
};

#endif // PAGE2_H