/*
 * MainWidget.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#include <iostream>
#include <QtWidgets/QMessageBox>

#include "MainWidget.h"

#ifdef ECLIPSE_BUILD
#include "MainWidget.h.meta"
#endif

#include "CustomToplevelTreeItem.h"
#include "CustomTreeWidgetItem.h"

MainWidget::MainWidget(): QWidget(), popupForToplevelEntry(true), selectedItem(nullptr), layout(), title("Multisave"), trwid(), plusButton("+"), entryPlusButton(""), entryPopup(this)
{
	// TODO Auto-generated constructor stub
	setWindowModality(Qt::NonModal);
	title.setAlignment(Qt::AlignCenter);
	trwid.setColumnCount(1);
	trwid.setHeaderLabels({tr("Path")});

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
	removeEntryButtons();

	layout.addWidget(&plusButton);
	layout.addWidget(&entryPlusButton);
	layout.addWidget(&entryMinusButton);

	setLayout(&layout);
}

void MainWidget::popupNewEntryWindow()
{
	CustomTreeWidgetItem *lw;
	if (popupForToplevelEntry) {
		lw = new CustomToplevelTreeItem("");
		trwid.addTopLevelItem(lw);
	} else {
		lw = new CustomTreeWidgetItem(false, "");
		selectedItem->addChild(lw);
	}
	emit entryPopup.popUp(lw);
}

void MainWidget::unpopupNewEntryWindow(CustomTreeWidgetItem* lwi)
{
	resize(sizeHint());
	entryPopup.hide();
	std::cout << lwi->text(0).toStdString() << std::endl;
	if (lwi->text(0).isEmpty()) {
		trwid.removeItemWidget(lwi, 0);
		delete lwi;
	} else if (popupForToplevelEntry) {
		static_cast<CustomToplevelTreeItem*>(lwi)->updatePath(lwi->text(0));
	}
	popupForToplevelEntry = true;
//	lwid.addItem(new CustomListWidgetItem(str));
}

void MainWidget::itemClicked(QTreeWidgetItem* item)
{
	CustomTreeWidgetItem *it = static_cast<CustomTreeWidgetItem*>(item);
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
	removeEntryButtons();
}

inline void MainWidget::removeEntryButtons()
{
	entryPlusButton.setVisible(false);
	entryMinusButton.setVisible(false);
}

inline void MainWidget::removeSelected()
{
	trwid.removeItemWidget(selectedItem, 0);
	delete selectedItem;
	selectedItem = nullptr;
}

MainWidget::~MainWidget()
{
	// TODO Auto-generated destructor stub
}
