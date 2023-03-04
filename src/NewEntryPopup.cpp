/*
 * NewEntryPopup.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtGui/QKeyEvent>
#include <iostream>

#include "NewEntryPopup.h"

#ifdef ECLIPSE_BUILD
#include "NewEntryPopup.h.meta"
#endif

NewEntryPopup::NewEntryPopup(QWidget *parent_): QWidget(parent_), lwi(nullptr), title(tr("Add file path")), pathLabel(tr("Path")), openDialog(tr("Open dialog")), done(tr("Done")), cancel(tr("Cancel"))
{
	// TODO Auto-generated constructor stub
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint);
	setWindowModality(Qt::ApplicationModal);
	setWindowTitle("MultiSave");
	path.setPlaceholderText(tr("File path..."));

	connect(&openDialog, &QPushButton::clicked, this, &NewEntryPopup::openFileDialog);
	connect(&done, &QPushButton::clicked, this, &NewEntryPopup::closePopup);
	connect(&cancel, &QPushButton::clicked, this, &NewEntryPopup::cancelPopup);

	title.setAlignment(Qt::AlignCenter);
	QFont font = title.font();
	font.setPointSize(20);
	title.setFont(font);

	layout.addWidget(&title, 0, 0, 1, 3);
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
	QString fname;
	if (lwi->isBeingWatched)
		fname = QFileDialog::getOpenFileName(this, tr("Watch file"), "");
	else
		fname = QFileDialog::getSaveFileName(this, tr("Save watched file as"), "");
	path.setText(fname);
}

void NewEntryPopup::popUp(CustomTreeWidgetItem* item)
{
	lwi = item;
	path.setText(item->text(0));
	show();
}

void NewEntryPopup::closePopup()
{
	const QString str = QDir::toNativeSeparators(path.text());
	if (!checkFile(str)) {
		QMessageBox::warning(this, tr("Error"), QString(tr("File ")).append(str).append(tr(" could not be opened")));
		return;
	}
	lwi->setText(0, str);
//	setWindowModality(Qt::NonModal);
	emit closed(lwi);
}

void NewEntryPopup::cancelPopup()
{
	emit closed(lwi);
}

bool NewEntryPopup::checkFile(const QString& fname) const
{
	if (lwi->isBeingWatched)
		return QFile::exists(fname) && QFileInfo(fname).isFile();
	bool res;
	QFile file(fname);
	if (file.open(QIODevice::WriteOnly)) {
		res = true;
	} else {
		res = false;
	}
	file.close();
	return res;
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

NewEntryPopup::~NewEntryPopup()
{
	// TODO Auto-generated destructor stubString
}

