/****************************************************************************
** Meta object code from reading C++ file 'toolbar.h'
**
** Created: Tue May 15 19:29:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../toolbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToolBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      17,    8,    8,    8, 0x08,
      29,    8,    8,    8, 0x08,
      42,    8,    8,    8, 0x08,
      66,   58,    8,    8, 0x08,
      88,   86,    8,    8, 0x08,
     104,   86,    8,    8, 0x08,
     121,   86,    8,    8, 0x08,
     136,   86,    8,    8, 0x08,
     156,  154,    8,    8, 0x08,
     172,  154,    8,    8, 0x08,
     189,  154,    8,    8, 0x08,
     204,  154,    8,    8, 0x08,
     222,    8,    8,    8, 0x08,
     235,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ToolBar[] = {
    "ToolBar\0\0order()\0randomize()\0addSpinBox()\0"
    "removeSpinBox()\0movable\0changeMovable(bool)\0"
    "a\0allowLeft(bool)\0allowRight(bool)\0"
    "allowTop(bool)\0allowBottom(bool)\0p\0"
    "placeLeft(bool)\0placeRight(bool)\0"
    "placeTop(bool)\0placeBottom(bool)\0"
    "updateMenu()\0insertToolBarBreak()\0"
};

void ToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolBar *_t = static_cast<ToolBar *>(_o);
        switch (_id) {
        case 0: _t->order(); break;
        case 1: _t->randomize(); break;
        case 2: _t->addSpinBox(); break;
        case 3: _t->removeSpinBox(); break;
        case 4: _t->changeMovable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->allowLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->allowRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->allowTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->allowBottom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->placeLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->placeRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->placeTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->placeBottom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->updateMenu(); break;
        case 14: _t->insertToolBarBreak(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ToolBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_ToolBar,
      qt_meta_data_ToolBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ToolBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBar))
        return static_cast<void*>(const_cast< ToolBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int ToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
