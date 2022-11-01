/*
 * CustomListWidgetItem.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kk
 */

#ifndef CUSTOMTREEWIDGETITEM_H_
#define CUSTOMTREEWIDGETITEM_H_

#include <QtWidgets/QTreeWidgetItem>
#include <QtCore/QFileSystemWatcher>
#include <QtCore/QFile>

#include <cstdint>

class CustomTreeWidgetItem: public QObject, public QTreeWidgetItem {
	Q_OBJECT
public:
	CustomTreeWidgetItem(const QString&);
	virtual ~CustomTreeWidgetItem();
	uint32_t getId() const;
private slots:
	void fileChanged(const QString&);
private:
	static uint32_t id_counter;
	QFileSystemWatcher fsw;
	uint32_t id;
};

#endif /* CUSTOMTREEWIDGETITEM_H_ */
