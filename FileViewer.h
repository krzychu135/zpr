/*
 * FileViewer.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */

#ifndef FILEVIEWER_H_
#define FILEVIEWER_H_

#include "Viewer.h"

class FileViewer: public Viewer {
	/**
	 * Where to save file with spectrum
	 */
	std::string name_;
public:
	FileViewer();
	virtual ~FileViewer();
	FileViewer(std::string name);

	virtual void Show();
};

#endif /* FILEVIEWER_H_ */
