/*
 * NewEntryPopup.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#ifndef NEWENTRYPOPUP_H_
#define NEWENTRYPOPUP_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

#include "CustomListWidgetItem.h"

class NewEntryPopup: public QWidget {
	Q_OBJECT
public:
	NewEntryPopup();
	virtual ~NewEntryPopup();
public slots:
	void popUp(CustomListWidgetItem*);
private slots:
	void openFileDialog();
	void closePopup();
signals:
	void closed(CustomListWidgetItem*);
private:

	CustomListWidgetItem* lwi;
	QGridLayout layout;
	QLabel title;
	QLabel pathLabel;
	QPushButton openDialog;
	QPushButton done;
	QLineEdit path;
};

#endif /* NEWENTRYPOPUP_H_ */
