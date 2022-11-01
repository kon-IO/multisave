/*
 * FileEntry.h
 *
 *  Created on: Nov 1, 2022
 *      Author: kk
 */

#ifndef FILEENTRY_H_
#define FILEENTRY_H_

#include <QtCore/QFileSystemWatcher>
#include <QtWidgets/QTreeWidget>

class FileEntry: public QTreeWidgetItem {
public:
	FileEntry(const QString&);
	virtual ~FileEntry();
private:
	const QString filename;
};

#endif /* FILEENTRY_H_ */
