/*
 * FileEntry.cpp
 *
 *  Created on: Nov 1, 2022
 *      Author: kk
 */

#include "FileEntry.h"
#include "FileEntry.h.meta"

#include <QtCore/QFile>
#include <QtGui/QKeyEvent>

#include <iostream>

FileEntry::FileEntry(const QString& fname): CustomTreeWidgetItem(false, fname), filename(fname) {
	// TODO Auto-generated constructor stub
}

FileEntry::~FileEntry() {
	// TODO Auto-generated destructor stub
}

