/****************************************************************************
** Meta object code from reading C++ file 'custom_tooltip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/custom_tooltip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'custom_tooltip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_custom_tooltip_t {
    QByteArrayData data[6];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_custom_tooltip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_custom_tooltip_t qt_meta_stringdata_custom_tooltip = {
    {
QT_MOC_LITERAL(0, 0, 14), // "custom_tooltip"
QT_MOC_LITERAL(1, 15, 11), // "ListPressed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "generic_event"
QT_MOC_LITERAL(4, 42, 7), // "QEvent*"
QT_MOC_LITERAL(5, 50, 1) // "e"

    },
    "custom_tooltip\0ListPressed\0\0generic_event\0"
    "QEvent*\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_custom_tooltip[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void custom_tooltip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        custom_tooltip *_t = static_cast<custom_tooltip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ListPressed(); break;
        case 1: _t->generic_event((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject custom_tooltip::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_custom_tooltip.data,
      qt_meta_data_custom_tooltip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *custom_tooltip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *custom_tooltip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_custom_tooltip.stringdata0))
        return static_cast<void*>(const_cast< custom_tooltip*>(this));
    return QWidget::qt_metacast(_clname);
}

int custom_tooltip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
