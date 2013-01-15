/*
 * FileViewer.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"

#ifndef FILEVIEWER_H_
#define FILEVIEWER_H_

#include "Viewer.h"

class FileViewer {
	/**
	 * Where to save file with spectrum
	 */
    std::string name;
public:
	FileViewer();
	virtual ~FileViewer();
    FileViewer(const std::string na);

    virtual void save(const std::string na)const=0;
};

#endif /* FILEVIEWER_H_ */
