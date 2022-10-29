/*
 * MainWidget.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include <iostream>

#include "MainWidget.h"

#include "CustomListWidgetItem.h"
#include "MainWidget.h.meta"

MainWidget::MainWidget(): QWidget(), layout(), title("My Window"), lwid(), plusButton("+") {
	// TODO Auto-generated constructor stub
	title.setAlignment(Qt::AlignCenter);

	QFont titleFont = title.font();
	titleFont.setPointSize(24);
	title.setFont(titleFont);

	layout.addWidget(&title, 0, 0);

	layout.addWidget(&lwid, 1, 0);

	connect(&plusButton, &QPushButton::pressed, this, &MainWidget::popupNewEntryWindow);
	connect(&entryPopup, &NewEntryPopup::closed, this, &MainWidget::unpopupNewEntryWindow);

	plusButton.setFont(titleFont);
	layout.addWidget(&plusButton);

	setLayout(&layout);
}

void MainWidget::popupNewEntryWindow()
{
	CustomListWidgetItem* lw = new CustomListWidgetItem("");
	lwid.addItem(lw);
	emit entryPopup.popUp(lw);
}

void MainWidget::unpopupNewEntryWindow(CustomListWidgetItem* lwi)
{
	entryPopup.hide();
	std::cerr << lwi->text();
	if (lwi->text().isEmpty()) {
		lwid.removeItemWidget(lwi);
		delete lwi;
	}
//	lwid.addItem(new CustomListWidgetItem(str));
}

MainWidget::~MainWidget() {
	// TODO Auto-generated destructor stub
}

