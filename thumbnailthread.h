
/*
	Author: shiroki@www.cuteqt.com
	License: GPLv2
*/

#ifndef TNTHREAD_H 
#define TNTHREAD_H
#include <QThread>
#include <QImage>
#include <QString>

class ThumbnailThread: public QThread
{
Q_OBJECT
public:
	ThumbnailThread(const QString filename, int n = 1);
	int waitseconds(){return number;};

private:
	void run();
	QImage bigpm, smallpm;
	QString pmfilename;
	int number;

signals:
	void thumbnailFinished(QImage);
	void thumbnailFailed(const QString filename);
};
#endif 

