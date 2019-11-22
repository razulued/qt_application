/****************************************************************************
** Meta object code from reading C++ file 'calendario_filtro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendario_filtro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendario_filtro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calendario_filtro_t {
    QByteArrayData data[14];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calendario_filtro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calendario_filtro_t qt_meta_stringdata_calendario_filtro = {
    {
QT_MOC_LITERAL(0, 0, 17), // "calendario_filtro"
QT_MOC_LITERAL(1, 18, 11), // "send_fechas"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "ini"
QT_MOC_LITERAL(4, 35, 3), // "end"
QT_MOC_LITERAL(5, 39, 16), // "on_close_clicked"
QT_MOC_LITERAL(6, 56, 18), // "background_clicked"
QT_MOC_LITERAL(7, 75, 27), // "on_fecha_inicio_btn_clicked"
QT_MOC_LITERAL(8, 103, 24), // "on_fecha_fin_btn_clicked"
QT_MOC_LITERAL(9, 128, 26), // "registros_filter_init_date"
QT_MOC_LITERAL(10, 155, 4), // "hora"
QT_MOC_LITERAL(11, 160, 4), // "date"
QT_MOC_LITERAL(12, 165, 25), // "registros_filter_end_date"
QT_MOC_LITERAL(13, 191, 20) // "on_ok_button_clicked"

    },
    "calendario_filtro\0send_fechas\0\0ini\0"
    "end\0on_close_clicked\0background_clicked\0"
    "on_fecha_inicio_btn_clicked\0"
    "on_fecha_fin_btn_clicked\0"
    "registros_filter_init_date\0hora\0date\0"
    "registros_filter_end_date\0"
    "on_ok_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendario_filtro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    2,   63,    2, 0x08 /* Private */,
      12,    2,   68,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::QDate,   10,   11,
    QMetaType::Void, QMetaType::UInt, QMetaType::QDate,   10,   11,
    QMetaType::Void,

       0        // eod
};

void calendario_filtro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendario_filtro *_t = static_cast<calendario_filtro *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_fechas((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->on_close_clicked(); break;
        case 2: _t->background_clicked(); break;
        case 3: _t->on_fecha_inicio_btn_clicked(); break;
        case 4: _t->on_fecha_fin_btn_clicked(); break;
        case 5: _t->registros_filter_init_date((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 6: _t->registros_filter_end_date((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 7: _t->on_ok_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendario_filtro::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendario_filtro::send_fechas)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject calendario_filtro::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calendario_filtro.data,
      qt_meta_data_calendario_filtro,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calendario_filtro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendario_filtro::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calendario_filtro.stringdata0))
        return static_cast<void*>(const_cast< calendario_filtro*>(this));
    return QDialog::qt_metacast(_clname);
}

int calendario_filtro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void calendario_filtro::send_fechas(uint _t1, uint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
