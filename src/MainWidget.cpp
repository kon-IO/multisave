/*
 * MainWidget.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include "MainWidget.h"

#include "CustomListWidgetItem.h"

MainWidget::MainWidget(): QWidget(), layout(), title("My Window"), lwid(), plusButton("+") {
	// TODO Auto-generated constructor stub
	title.setAlignment(Qt::AlignCenter);

	QFont titleFont = title.font();
	titleFont.setPointSize(24);
	title.setFont(titleFont);

	layout.addWidget(&title, 0, 0);

	lwid.addItem(new CustomListWidgetItem("text"));
	layout.addWidget(&lwid, 1, 0);

	connect(&plusButton, &QPushButton::pressed, this, &MainWidget::popupNewEntryWindow);
	plusButton.setFont(titleFont);
	layout.addWidget(&plusButton);

	setLayout(&layout);
}

void MainWidget::popupNewEntryWindow()
{
	CustomListWidgetItem lw("");
	emit entryPopup.popUp(lw);
}

MainWidget::~MainWidget() {
	// TODO Auto-generated destructor stub
}

