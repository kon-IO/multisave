/*
 * CustomListWidgetItem.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include "CustomTreeWidgetItem.h"

#include "CustomTreeWidgetItem.h.meta"

#include <iostream>

uint32_t CustomTreeWidgetItem::id_counter = 0;

CustomTreeWidgetItem::CustomTreeWidgetItem(const QString &text) :
		QTreeWidgetItem(QStringList(text)), id(id_counter++) {
	// TODO Auto-generated constructor stub
	QObject::connect(&fsw, &QFileSystemWatcher::fileChanged, this, &CustomTreeWidgetItem::fileChanged);
}

void CustomTreeWidgetItem::fileChanged(const QString& path)
{
	std::cout << "File " << path.toStdString() << " changed" << std::endl;
}

uint32_t CustomTreeWidgetItem::getId() const {
	return id;
}

CustomTreeWidgetItem::~CustomTreeWidgetItem() {
	// TODO Auto-generated destructor stub
}

