/*
 * FileEntry.h
 *
 *  Created on: Nov 1, 2022
 *      Author: kon-io
 */

#ifndef FILEENTRY_H_
#define FILEENTRY_H_

#include <QtCore/QFileSystemWatcher>
#include "CustomTreeWidgetItem.h"

class FileEntry: public CustomTreeWidgetItem {
public:
	FileEntry(const QString&);
	virtual ~FileEntry();
private:
	const QString filename;
};

#endif /* FILEENTRY_H_ */
