#include "PreDefs.h"
#include "textio.h"
#include <iostream>
#include <QtGui>

extern QColor bgColorForName(const QString &name);

TextIO::TextIO(const QString &colorName, QWidget *parent, Qt::WindowFlags flags)
	: ColorSwatch(colorName, parent, flags)
{
	m_pTextEdit = new QTextEdit;
	m_pTextEdit->setMaximumWidth(parent->width());
	m_pTextEdit->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	setWidget(m_pTextEdit);
	
	//
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(12);
	m_pTextEdit->setFont(font);
	QPalette palette;
	palette.setColor(QPalette::Base, QColor(bgColorForName("Blue")));
	m_pTextEdit->setPalette(palette);

	m_pTextEdit->append(">> 3D building reconstruction");
}

TextIO::~TextIO()
{

}
