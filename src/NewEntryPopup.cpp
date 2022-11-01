/*
 * NewEntryPopup.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtGui/QKeyEvent>
#include <iostream>

#include "NewEntryPopup.h"
#include "NewEntryPopup.h.meta"

NewEntryPopup::NewEntryPopup(): QWidget(), lwi(nullptr), title("Add file path"), pathLabel("Path"), openDialog("Open dialog"), done("Done"), cancel("Cancel") {
	// TODO Auto-generated constructor stub
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint);
	setWindowTitle("MultiSave");
	path.setPlaceholderText("File path...");

	connect(&openDialog, &QPushButton::clicked, this, &NewEntryPopup::openFileDialog);
	connect(&done, &QPushButton::clicked, this, &NewEntryPopup::closePopup);
	connect(&cancel, &QPushButton::clicked, this, &NewEntryPopup::cancelPopup);

	layout.addWidget(&title, 0, 0, 1, 2);
	layout.addWidget(&pathLabel, 1, 0);
	layout.addWidget(&path, 1, 1);
	layout.addWidget(&openDialog, 1, 2);
	layout.addWidget(&cancel, 2, 0);
	layout.addWidget(&done, 2, 1, 1, 2);

	setLayout(&layout);
	setFixedSize(sizeHint());
}

void NewEntryPopup::openFileDialog()
{
	const QString fname = QFileDialog::getOpenFileName(this, "Track file", "${HOME_ENV}");
	path.setText(fname);
}

void NewEntryPopup::popUp(CustomTreeWidgetItem* item)
{
	lwi = item;
	path.setText(item->text(0));
	show();
}

void NewEntryPopup::closePopup(void)
{
	const QString str = QDir::toNativeSeparators(path.text());
	if (!checkFile(str)) {
		QMessageBox::warning(this, "Error", QString("File ").append(str).append(" could not be opened"));
		return;
	}
	lwi->setText(0, str);
	emit closed(lwi);
}

void NewEntryPopup::cancelPopup()
{
	emit closed(lwi);
}

inline bool NewEntryPopup::checkFile(const QString& fname) const
{
	return QFile::exists(fname) && QFileInfo(fname).isFile();
}

void NewEntryPopup::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Return:
		closePopup();
		break;
	case Qt::Key_Escape:
		cancelPopup();
		break;
	default:
		break;
	}
}

NewEntryPopup::~NewEntryPopup() {
	// TODO Auto-generated destructor stubString
}

