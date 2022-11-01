/*
 * MainWidget.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include <iostream>

#include "MainWidget.h"

#include "CustomToplevelTreeItem.h"
#include "MainWidget.h.meta"

MainWidget::MainWidget(): QWidget(), layout(), title("My Window"), trwid(), plusButton("+"), entryPlusButton("") {
	// TODO Auto-generated constructor stub
	title.setAlignment(Qt::AlignCenter);
	trwid.setColumnCount(1);
	trwid.setHeaderLabels({"Path"});

	QFont titleFont = title.font();
	titleFont.setPointSize(24);
	title.setFont(titleFont);

	layout.addWidget(&title, 0, 0);

	layout.addWidget(&trwid, 1, 0);

	connect(&plusButton, &QPushButton::pressed, this, &MainWidget::popupNewEntryWindow);
	connect(&entryPopup, &NewEntryPopup::closed, this, &MainWidget::unpopupNewEntryWindow);

	connect(&trwid, &CustomTreeWidget::itemClicked, this, &MainWidget::itemClicked);

	plusButton.setFont(titleFont);
	layout.addWidget(&plusButton);
	layout.addWidget(&entryPlusButton);

	setLayout(&layout);
}

void MainWidget::popupNewEntryWindow()
{
	CustomToplevelTreeItem *lw = new CustomToplevelTreeItem("");
	trwid.addTopLevelItem(lw);
	emit entryPopup.popUp(lw);
}

void MainWidget::unpopupNewEntryWindow(CustomToplevelTreeItem* lwi)
{
	resize(sizeHint());
	entryPopup.hide();
	std::cout << lwi->text(0).toStdString() << std::endl;
	if (lwi->text(0).isEmpty()) {
		trwid.removeItemWidget(lwi, 0);
		delete lwi;
	}
//	lwid.addItem(new CustomListWidgetItem(str));
}

void MainWidget::itemClicked(QTreeWidgetItem* item)
{
	CustomToplevelTreeItem *it = static_cast<CustomToplevelTreeItem*>(item);
	if (item->childCount() == 0) {
		entryPlusButton.setText(QString("- ").append(item->text(0)));
		return;
	}
	entryPlusButton.setText(QString("+ ").append(item->text(0)));
}

MainWidget::~MainWidget() {
	// TODO Auto-generated destructor stub
}

