/*
This file is part of QtOME (Qt Ogre Material Editor)
For the latest info, see https://github.com/ironsteel/QtOME
Copyright (C) 2010-2011 Rangel Ivanov & Nayden Dochev

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

Contacts:
Rangel Ivanov -
Nayden Dochev - nayyden at gmail dot com

*/

#ifndef NEWMATERIALDIALOG_H
#define NEWMATERIALDIALOG_H

#include <QDialog>

namespace Ui {
    class NewMaterialDialog;
}

class NewMaterialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMaterialDialog(QWidget *parent = 0);
    void processDialog();

    ~NewMaterialDialog();
public slots:
    void accept();
    void activateOkButton(QString text);
    void activateVertex(bool enabled);
    void activateFragmet(bool enabled);
private:
    Ui::NewMaterialDialog *ui;
    QString materialName;
    QString vertexShaderName;
    QString fragmentShaderName;
};

#endif // NEWMATERIALDIALOG_H
