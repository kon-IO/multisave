/*
 * CustomTreeWidgetItem.cpp
 *
 *  Created on: Nov 1, 2022
 *      Author: kon-io
 */

#include "CustomTreeWidgetItem.h"

CustomTreeWidgetItem::CustomTreeWidgetItem(bool watched, const QString& text): QTreeWidgetItem({text}), isBeingWatched(watched) {
	// TODO Auto-generated constructor stub

}

CustomTreeWidgetItem::~CustomTreeWidgetItem() {
	// TODO Auto-generated destructor stub
}

