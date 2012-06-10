/****************************************************************************
** Meta object code from reading C++ file 'thumbnailthread.h'
**
** Created: Sun Jun 10 10:29:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../thumbnailthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thumbnailthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThumbnailThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      52,   43,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThumbnailThread[] = {
    "ThumbnailThread\0\0thumbnailFinished(QImage)\0"
    "filename\0thumbnailFailed(QString)\0"
};

void ThumbnailThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThumbnailThread *_t = static_cast<ThumbnailThread *>(_o);
        switch (_id) {
        case 0: _t->thumbnailFinished((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->thumbnailFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThumbnailThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThumbnailThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThumbnailThread,
      qt_meta_data_ThumbnailThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThumbnailThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThumbnailThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThumbnailThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThumbnailThread))
        return static_cast<void*>(const_cast< ThumbnailThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ThumbnailThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThumbnailThread::thumbnailFinished(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThumbnailThread::thumbnailFailed(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
