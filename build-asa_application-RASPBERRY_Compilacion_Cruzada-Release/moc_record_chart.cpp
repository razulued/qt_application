/****************************************************************************
** Meta object code from reading C++ file 'record_chart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/record_chart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'record_chart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_record_chart_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_record_chart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_record_chart_t qt_meta_stringdata_record_chart = {
    {
QT_MOC_LITERAL(0, 0, 12), // "record_chart"
QT_MOC_LITERAL(1, 13, 18), // "background_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "on_filtro_fecha_clicked"
QT_MOC_LITERAL(4, 57, 21), // "filtro_fecha_received"
QT_MOC_LITERAL(5, 79, 3), // "ini"
QT_MOC_LITERAL(6, 83, 3), // "end"
QT_MOC_LITERAL(7, 87, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(8, 110, 7) // "checked"

    },
    "record_chart\0background_clicked\0\0"
    "on_filtro_fecha_clicked\0filtro_fecha_received\0"
    "ini\0end\0on_radioButton_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_record_chart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    2,   36,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void record_chart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        record_chart *_t = static_cast<record_chart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->background_clicked(); break;
        case 1: _t->on_filtro_fecha_clicked(); break;
        case 2: _t->filtro_fecha_received((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->on_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject record_chart::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_record_chart.data,
      qt_meta_data_record_chart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *record_chart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *record_chart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_record_chart.stringdata0))
        return static_cast<void*>(const_cast< record_chart*>(this));
    return QDialog::qt_metacast(_clname);
}

int record_chart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
