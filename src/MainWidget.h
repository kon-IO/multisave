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

#include "CustomTreeWidget.h"

class MainWidget: public QWidget {
	Q_OBJECT
public:
	MainWidget();
	virtual ~MainWidget();
public slots:
	void popupNewEntryWindow();
	void unpopupNewEntryWindow(CustomTreeWidgetItem*);
	void itemClicked(QTreeWidgetItem*);
private:
	QGridLayout layout;
	QLabel title;
	CustomTreeWidget trwid;
	QPushButton plusButton;
	QPushButton entryPlusButton;

	NewEntryPopup entryPopup;
};

#endif /* MAINWIDGET_H_ */
