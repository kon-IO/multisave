/*
 * NewEntryPopup.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include "NewEntryPopup.h"

NewEntryPopup::NewEntryPopup(): QWidget(), title("Add file path"), pathLabel("Path") {
	// TODO Auto-generated constructor stub
	path.setPlaceholderText("File path...");
	layout.addWidget(&title, 0, 0, 1, 2);
	layout.addWidget(&pathLabel, 1, 0);
	layout.addWidget(&path, 1, 1);
	setLayout(&layout);
}

void NewEntryPopup::popUp(CustomListWidgetItem& item)
{
	path.setText(item.text());
	show();
}

NewEntryPopup::~NewEntryPopup() {
	// TODO Auto-generated destructor stub
}

