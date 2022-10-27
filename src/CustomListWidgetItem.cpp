/*
 * CustomListWidgetItem.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#include "CustomListWidgetItem.h"

uint32_t CustomListWidgetItem::id_counter = 0;

CustomListWidgetItem::CustomListWidgetItem(const QString& text): QListWidgetItem(text), id(id_counter++) {
	// TODO Auto-generated constructor stub
}

uint32_t CustomListWidgetItem::getId() const
{
	return id;
}

CustomListWidgetItem::~CustomListWidgetItem() {
	// TODO Auto-generated destructor stub
}

