/****************************************************************************
** Meta object code from reading C++ file 'sockettest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client-QT-GUI/sockettest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sockettest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketTest_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketTest_t qt_meta_stringdata_SocketTest = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SocketTest"
QT_MOC_LITERAL(1, 11, 14), // "signalUpdateUI"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "signalUpdateStatus"
QT_MOC_LITERAL(4, 46, 11), // "sendMessage"
QT_MOC_LITERAL(5, 58, 11), // "const char*"
QT_MOC_LITERAL(6, 70, 4), // "data"
QT_MOC_LITERAL(7, 75, 9), // "connected"
QT_MOC_LITERAL(8, 85, 12), // "disconnected"
QT_MOC_LITERAL(9, 98, 12), // "bytesWritten"
QT_MOC_LITERAL(10, 111, 5), // "bytes"
QT_MOC_LITERAL(11, 117, 9) // "readyRead"

    },
    "SocketTest\0signalUpdateUI\0\0"
    "signalUpdateStatus\0sendMessage\0"
    "const char*\0data\0connected\0disconnected\0"
    "bytesWritten\0bytes\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,

       0        // eod
};

void SocketTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketTest *_t = static_cast<SocketTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdateUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalUpdateStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendMessage((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketTest::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketTest::signalUpdateUI)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SocketTest::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketTest::signalUpdateStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SocketTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketTest.data,
      qt_meta_data_SocketTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SocketTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SocketTest.stringdata0))
        return static_cast<void*>(const_cast< SocketTest*>(this));
    return QObject::qt_metacast(_clname);
}

int SocketTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SocketTest::signalUpdateUI(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketTest::signalUpdateStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
