/*
 * CustomListWidgetItem.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#include "CustomToplevelTreeItem.h"

#include "CustomToplevelTreeItem.h.meta"

#include <iostream>

uint32_t CustomToplevelTreeItem::id_counter = 0;

CustomToplevelTreeItem::CustomToplevelTreeItem(const QString &text) :
		CustomTreeWidgetItem(true, text), id(id_counter++) {
	// TODO Auto-generated constructor stub
	QObject::connect(&fsw, &QFileSystemWatcher::fileChanged, this, &CustomToplevelTreeItem::fileChanged);
}

void CustomToplevelTreeItem::fileChanged(const QString& path)
{
	std::cout << "File " << path.toStdString() << " changed" << std::endl;
}

uint32_t CustomToplevelTreeItem::getId() const {
	return id;
}

CustomToplevelTreeItem::~CustomToplevelTreeItem() {
	// TODO Auto-generated destructor stub
}

