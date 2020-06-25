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

#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>

// Qt Designer object
namespace Ui {
    class Page1;
}

struct Page1Private;
class Page1 : public QWidget {
        Q_OBJECT

    public:
        explicit Page1(QWidget* parent = nullptr); // called on create
        ~Page1();                                  // called on delete
        
        // custom functions
        void setHeading(QString text);
        void setBody(QString text);
        
    private:
        Ui::Page1* ui;      // Qt Designer object
        Page1Private* d;    // variables that we wish to use in the class
};

#endif // PAGE1_H
