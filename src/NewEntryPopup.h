/*
 * NewEntryPopup.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#ifndef NEWENTRYPOPUP_H_
#define NEWENTRYPOPUP_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

#include "CustomTreeWidgetItem.h"

class NewEntryPopup: public QWidget {
	Q_OBJECT
public:
	NewEntryPopup(QWidget* parent_);
	virtual ~NewEntryPopup();
public slots:
	void popUp(CustomTreeWidgetItem*);
private slots:
	void openFileDialog();
	void closePopup();
	void cancelPopup();
signals:
	void closed(CustomTreeWidgetItem*);
private:
	inline bool checkFile(const QString&) const;
	void keyPressEvent(QKeyEvent*);

	CustomTreeWidgetItem* lwi;
	QGridLayout layout;
	QLabel title;
	QLabel pathLabel;
	QPushButton openDialog;
	QPushButton done;
	QPushButton cancel;
	QLineEdit path;
};

#endif /* NEWENTRYPOPUP_H_ */
