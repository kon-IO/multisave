/*
 * CustomTreeWidgetItem.h
 *
 *  Created on: Nov 1, 2022
 *      Author: kon-io
 */

#ifndef CUSTOMTREEWIDGETITEM_H_
#define CUSTOMTREEWIDGETITEM_H_

#include <QtWidgets/QTreeWidgetItem>

class CustomTreeWidgetItem: public QTreeWidgetItem {
public:
	CustomTreeWidgetItem(bool, const QString&);
	virtual ~CustomTreeWidgetItem();
	bool isBeingWatched;
};

#endif /* CUSTOMTREEWIDGETITEM_H_ */
