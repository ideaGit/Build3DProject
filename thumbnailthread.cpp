#include <QDebug>
#include "thumbnailthread.h"

const int TN_WIDTH=160;
const int TN_HEIGHT=120;

ThumbnailThread::ThumbnailThread(const QString filename, int n)
{
	pmfilename = filename;
	bigpm = QImage(filename);
	number = n;
}

void ThumbnailThread::run()
{
	if( bigpm.isNull())
	{
		emit thumbnailFailed(pmfilename);
	}
	else
	{
		qWarning() << "thread start..." << number;
		sleep(number);
		smallpm = bigpm.scaled(TN_WIDTH, TN_HEIGHT, Qt::KeepAspectRatio);
		emit thumbnailFinished(smallpm);
	}
}

