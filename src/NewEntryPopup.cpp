/*
 * NewEntryPopup.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include <QtWidgets/QFileDialog>
#include <iostream>

#include "NewEntryPopup.h"

NewEntryPopup::NewEntryPopup(): QWidget(), title("Add file path"), pathLabel("Path"), openDialog("Open dialog"), done("Done") {
	// TODO Auto-generated constructor stub
	path.setPlaceholderText("File path...");

	connect(&openDialog, &QPushButton::clicked, this, &NewEntryPopup::openFileDialog);
	connect(&done, &QPushButton::clicked, this, &NewEntryPopup::closePopup);

	layout.addWidget(&title, 0, 0, 1, 2);
	layout.addWidget(&pathLabel, 1, 0);
	layout.addWidget(&path, 1, 1);
	layout.addWidget(&openDialog, 1, 2);
	layout.addWidget(&done, 2, 0, 1, 3);

	setLayout(&layout);
}

void NewEntryPopup::openFileDialog()
{
	const QString fname = QFileDialog::getOpenFileName(0, "Track file", "${HOME_ENV}");
	path.setText(fname);
}

void NewEntryPopup::popUp(CustomListWidgetItem& item)
{
	path.setText(item.text());
	show();
}

void NewEntryPopup::closePopup(void)
{
	emit closed(path.text());
}

//void NewEntryPopup::closed(QString text) const
//{
//
//}

NewEntryPopup::~NewEntryPopup() {
	// TODO Auto-generated destructor stubString
}

