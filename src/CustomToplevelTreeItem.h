/*
 * CustomListWidgetItem.h
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#ifndef CUSTOMTOPLEVELTREEITEM_H_
#define CUSTOMTOPLEVELTREEITEM_H_

#include <QtWidgets/QTreeWidgetItem>
#include <QtCore/QFileSystemWatcher>
#include <QtCore/QFile>

#include "CustomTreeWidgetItem.h"

#include <cstdint>

class CustomToplevelTreeItem: public QObject, public CustomTreeWidgetItem {
	Q_OBJECT
public:
	CustomToplevelTreeItem(const QString&);
	virtual ~CustomToplevelTreeItem();
	void updatePath(const QString&);
	uint32_t getId() const;
private slots:
	void fileChanged(const QString&);
private:
	static uint32_t id_counter;
	QString filename;
	QFileSystemWatcher fsw;
	uint32_t id;
};

#endif /* CUSTOMTOPLEVELTREEITEM_H_ */
