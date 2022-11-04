/*
 * FileEntry.cpp
 *
 *  Created on: Nov 1, 2022
 *      Author: kon-io
 */

#include "FileEntry.h"

#ifdef ECLIPSE_BUILD
#include "FileEntry.h.meta"
#endif

#include <QtCore/QFile>
#include <QtGui/QKeyEvent>

#include <iostream>

FileEntry::FileEntry(const QString& fname): CustomTreeWidgetItem(false, fname), filename(fname) {
	// TODO Auto-generated constructor stub
}

FileEntry::~FileEntry() {
	// TODO Auto-generated destructor stub
}

