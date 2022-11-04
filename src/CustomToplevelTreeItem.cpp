/*
 * CustomListWidgetItem.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: kon-io
 */

#include "CustomToplevelTreeItem.h"

#ifdef ECLIPSE_BUILD
#include "CustomToplevelTreeItem.h.meta"
#endif

#include <iostream>
#include <QtCore/QFile>

uint32_t CustomToplevelTreeItem::id_counter = 0;

CustomToplevelTreeItem::CustomToplevelTreeItem(const QString &text) :
		CustomTreeWidgetItem(true, text), filename(text), id(id_counter++)
{
	// TODO Auto-generated constructor stub
	QObject::connect(&fsw, &QFileSystemWatcher::fileChanged, this, &CustomToplevelTreeItem::fileChanged);
}

void CustomToplevelTreeItem::fileChanged(const QString& path)
{
//	QFile file(path);
//	file.open(QIODevice::ReadOnly);
//	QByteArray arr = file.readAll();
//	file.close();

	int count = childCount();
	for (int i = 0; i < count; i++) {
		QString fname = child(i)->text(0);
//		QFile f(child(i)->text(0));
//		f.open(QIODevice::WriteOnly);
//		f.write(arr);
//		f.close();
		QFile::remove(fname);
		QFile::copy(path, fname);
		std::cout << child(i)->text(0).toStdString() << std::endl;
	}
	fsw.removePath(filename);
	fsw.addPath(filename);
	std::cout << "File " << path.toStdString() << " changed" << std::endl;
}

void CustomToplevelTreeItem::updatePath(const QString& text)
{
	filename = text;
	fsw.addPath(text);
}

uint32_t CustomToplevelTreeItem::getId() const
{
	return id;
}

CustomToplevelTreeItem::~CustomToplevelTreeItem()
{
	// TODO Auto-generated destructor stub
}

