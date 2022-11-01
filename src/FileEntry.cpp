/*
 * FileEntry.cpp
 *
 *  Created on: Nov 1, 2022
 *      Author: kk
 */

#include "FileEntry.h"
#include "FileEntry.h.meta"

#include <QtCore/QFile>

FileEntry::FileEntry(const QString& parent_, const QString fname): filename(fname) {
	// TODO Auto-generated constructor stub
	setText(0, fname);
}

FileEntry::~FileEntry() {
	// TODO Auto-generated destructor stub
}

