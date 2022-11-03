/*
 * MainWidget.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#include <iostream>

#include "MainWidget.h"

#include "CustomToplevelTreeItem.h"
#include "MainWidget.h.meta"

MainWidget::MainWidget(): QWidget(), popupForToplevelEntry(true), selectedItem(nullptr), layout(), title("Multisave"), trwid(), plusButton("+"), entryPlusButton("") {
	// TODO Auto-generated constructor stub
	setWindowModality(Qt::NonModal);
	title.setAlignment(Qt::AlignCenter);
	trwid.setColumnCount(1);
	trwid.setHeaderLabels({"Path"});

	QFont titleFont = title.font();
	titleFont.setPointSize(24);
	title.setFont(titleFont);

	layout.addWidget(&title, 0, 0);

	layout.addWidget(&trwid, 1, 0);

	connect(&plusButton, &QPushButton::clicked, this, &MainWidget::popupNewEntryWindow);
	connect(&entryPlusButton, &QPushButton::clicked, this, &MainWidget::addItem);
	connect(&entryMinusButton, &QPushButton::clicked, this, &MainWidget::removeItem);
	connect(&entryPopup, &NewEntryPopup::closed, this, &MainWidget::unpopupNewEntryWindow);

	connect(&trwid, &CustomTreeWidget::itemClicked, this, &MainWidget::itemClicked);

	plusButton.setFont(titleFont);
	entryMinusButton.setVisible(false);
	entryPlusButton.setVisible(false);

	layout.addWidget(&plusButton);
	layout.addWidget(&entryPlusButton);
	layout.addWidget(&entryMinusButton);

	setLayout(&layout);
}

void MainWidget::popupNewEntryWindow()
{
	CustomToplevelTreeItem *lw = new CustomToplevelTreeItem("");
	if (popupForToplevelEntry) {
		trwid.addTopLevelItem(lw);
	} else {
		selectedItem->addChild(lw);
	}
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
	popupForToplevelEntry = true;
//	lwid.addItem(new CustomListWidgetItem(str));
}

void MainWidget::itemClicked(QTreeWidgetItem* item)
{
	CustomToplevelTreeItem *it = static_cast<CustomToplevelTreeItem*>(item);
	selectedItem = it;
	entryMinusButton.setText(QString("- ").append(it->text(0)));
	entryMinusButton.setVisible(true);
	if (it->isBeingWatched) {
		entryPlusButton.setText(QString("+ ").append(it->text(0)));
		entryPlusButton.setVisible(true);
	} else {
		entryPlusButton.setVisible(false);
	}
}

void MainWidget::addItem()
{
	if (selectedItem == nullptr)
		return;

	popupForToplevelEntry = false;
	popupNewEntryWindow();
}

void MainWidget::removeItem()
{
	if (selectedItem == nullptr)
		return;
	removeSelected();
}

inline void MainWidget::removeSelected()
{
	trwid.removeItemWidget(selectedItem, 0);
	delete selectedItem;
	selectedItem = nullptr;
}

MainWidget::~MainWidget() {
	// TODO Auto-generated destructor stub
}

