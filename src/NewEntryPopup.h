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

enum class FileStatus {
	OK,
	NO_PERMS,
	OTHER_FAIL
};

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
	void cancelPopup();
signals:
	void closed(CustomListWidgetItem*);
private:
	inline bool checkFile(const QString&) const;

	CustomListWidgetItem* lwi;
	QGridLayout layout;
	QLabel title;
	QLabel pathLabel;
	QPushButton openDialog;
	QPushButton done;
	QPushButton cancel;
	QLineEdit path;
};

#endif /* NEWENTRYPOPUP_H_ */
