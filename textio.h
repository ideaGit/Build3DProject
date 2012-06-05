#ifndef TEXTIO_H
#define TEXTIO_H

#include <QTextEdit>
#include <QDockWidget>
#include "colorswatch.h"

class TextIO : public ColorSwatch
{
	Q_OBJECT

public slots:

public:
	TextIO(const QString &colorName, QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~TextIO();

private:
	QTextEdit *		m_pTextEdit;
};

#endif // TEXTIO_H
