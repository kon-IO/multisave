/*
 * CustomListWidgetItem.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#ifndef CUSTOMLISTWIDGETITEM_H_
#define CUSTOMLISTWIDGETITEM_H_

#include <QtWidgets/QListWidgetItem>

#include <cstdint>

class CustomListWidgetItem: public QListWidgetItem {
public:
	CustomListWidgetItem(const QString&);
	virtual ~CustomListWidgetItem();
	uint32_t getId() const;
private:
	static uint32_t id_counter;
	uint32_t id;
};

#endif /* CUSTOMLISTWIDGETITEM_H_ */
