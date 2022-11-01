/*
 * CustomTreeWidgetItem.cpp
 *
 *  Created on: Nov 1, 2022
 *      Author: kk
 */

#include "CustomTreeWidgetItem.h"

CustomTreeWidgetItem::CustomTreeWidgetItem(bool watched, const QString& text): isBeingWatched(watched), QTreeWidgetItem({text}) {
	// TODO Auto-generated constructor stub

}

CustomTreeWidgetItem::~CustomTreeWidgetItem() {
	// TODO Auto-generated destructor stub
}

