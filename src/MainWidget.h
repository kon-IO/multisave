/*
 * MainWidget.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#ifndef MAINWIDGET_H_
#define MAINWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QPushButton>

#include <QtWidgets/QWidget>

#include "NewEntryPopup.h"

class MainWidget: public QWidget {
	Q_OBJECT
public:
	MainWidget();
	virtual ~MainWidget();
public slots:
	void popupNewEntryWindow();
	void unpopupNewEntryWindow(CustomTreeWidgetItem*);
private:
	QGridLayout layout;
	QLabel title;
	QTreeWidget trwid;
	QPushButton plusButton;

	NewEntryPopup entryPopup;
};

#endif /* MAINWIDGET_H_ */
