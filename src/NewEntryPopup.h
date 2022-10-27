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

#include "CustomListWidgetItem.h"

class NewEntryPopup: public QWidget {
public:
	NewEntryPopup();
	virtual ~NewEntryPopup();
public slots:
	void popUp(CustomListWidgetItem&);
private:
	QGridLayout layout;
	QLabel title;
	QLabel pathLabel;
	QLineEdit path;
};

#endif /* NEWENTRYPOPUP_H_ */