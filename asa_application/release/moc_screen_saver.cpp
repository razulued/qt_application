/****************************************************************************
** Meta object code from reading C++ file 'screen_saver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screen_saver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screen_saver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_screen_saver_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_screen_saver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_screen_saver_t qt_meta_stringdata_screen_saver = {
    {
QT_MOC_LITERAL(0, 0, 12), // "screen_saver"
QT_MOC_LITERAL(1, 13, 9), // "TimerSlot"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "receive_date_hour"
QT_MOC_LITERAL(4, 42, 4), // "time"
QT_MOC_LITERAL(5, 47, 18), // "pending_activities"
QT_MOC_LITERAL(6, 66, 3) // "act"

    },
    "screen_saver\0TimerSlot\0\0receive_date_hour\0"
    "time\0pending_activities\0act"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_screen_saver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    4,
    QMetaType::Void, QMetaType::UInt,    6,

       0        // eod
};

void screen_saver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        screen_saver *_t = static_cast<screen_saver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimerSlot(); break;
        case 1: _t->receive_date_hour((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->pending_activities((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject screen_saver::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_screen_saver.data,
      qt_meta_data_screen_saver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *screen_saver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *screen_saver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_screen_saver.stringdata0))
        return static_cast<void*>(const_cast< screen_saver*>(this));
    return QDialog::qt_metacast(_clname);
}

int screen_saver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
