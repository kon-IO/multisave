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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

#include <QtWidgets/QWidget>

#include "NewEntryPopup.h"

class MainWidget: public QWidget {
public:
	MainWidget();
	virtual ~MainWidget();
public slots:
	void popupNewEntryWindow();
private:
	QGridLayout layout;
	QLabel title;
	QListWidget lwid;
	QPushButton plusButton;

	NewEntryPopup entryPopup;
};

#endif /* MAINWIDGET_H_ */
