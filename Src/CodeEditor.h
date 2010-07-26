/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include "Highlighter.h"
#include <QTextEdit>
#include <QCompleter>
#include <QFile>
/**************************** Line Number Widget ***************************************
*
*                    Taken from Lumina's source: sourceedit.h
*                    http://lumina.sourceforge.net/
*
****************************************************************************************/


class LineNumberWidget : public QWidget{
        Q_OBJECT
public:
        LineNumberWidget(QTextEdit *editor, QWidget *parent = 0);
protected:
        virtual void paintEvent(QPaintEvent *);

private:
        QTextEdit *editor;
};
//---------------------------------------------------------------------------------------


//! [0]
class CodeEditor : public QTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = 0);
    ~CodeEditor();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;
    QStringList wordindexFromFile(const QString& fileName);
    void setupCurrentCompleter(const QString& wordListFile);
    void openFile(const QString& filename);
    void saveFile();

protected:
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);

private slots:
    void insertCompletion(const QString &completion);
    void codeIdentation();

private:
    QString textUnderCursor() const;
    void setupHighlighter();



private:
    Highlighter *highlighter; // Syntax highlighter
    QCompleter *c;
    QCompleter *currentCompleter;// Auto completer
    QAbstractItemModel *wordList; // wordlist for the autocompleter
    QString matScriptFilename;
};
//! [0]

#endif // CODEEDITOR_H

