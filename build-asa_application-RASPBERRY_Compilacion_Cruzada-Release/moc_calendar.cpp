/****************************************************************************
** Meta object code from reading C++ file 'calendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/calendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calendar_t {
    QByteArrayData data[11];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calendar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calendar_t qt_meta_stringdata_calendar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "calendar"
QT_MOC_LITERAL(1, 9, 18), // "send_calendar_date"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "hour"
QT_MOC_LITERAL(4, 34, 4), // "date"
QT_MOC_LITERAL(5, 39, 8), // "datetime"
QT_MOC_LITERAL(6, 48, 22), // "send_calendar_datetime"
QT_MOC_LITERAL(7, 71, 18), // "background_clicked"
QT_MOC_LITERAL(8, 90, 23), // "on_push_aceptar_clicked"
QT_MOC_LITERAL(9, 114, 24), // "on_push_cancelar_clicked"
QT_MOC_LITERAL(10, 139, 22) // "on_closeButton_clicked"

    },
    "calendar\0send_calendar_date\0\0hour\0"
    "date\0datetime\0send_calendar_datetime\0"
    "background_clicked\0on_push_aceptar_clicked\0"
    "on_push_cancelar_clicked\0"
    "on_closeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QDate, QMetaType::QDateTime,    3,    4,    5,
    QMetaType::Void, QMetaType::QDateTime,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendar *_t = static_cast<calendar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_calendar_date((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 1: _t->send_calendar_datetime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->background_clicked(); break;
        case 3: _t->on_push_aceptar_clicked(); break;
        case 4: _t->on_push_cancelar_clicked(); break;
        case 5: _t->on_closeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendar::*_t)(uint , QDate , QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendar::send_calendar_date)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (calendar::*_t)(QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendar::send_calendar_datetime)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject calendar::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calendar.data,
      qt_meta_data_calendar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calendar.stringdata0))
        return static_cast<void*>(const_cast< calendar*>(this));
    return QDialog::qt_metacast(_clname);
}

int calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void calendar::send_calendar_date(uint _t1, QDate _t2, QDateTime _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void calendar::send_calendar_datetime(QDateTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
