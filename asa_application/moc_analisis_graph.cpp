/****************************************************************************
** Meta object code from reading C++ file 'analisis_graph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "analisis_graph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analisis_graph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_analisis_graph_t {
    QByteArrayData data[18];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_analisis_graph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_analisis_graph_t qt_meta_stringdata_analisis_graph = {
    {
QT_MOC_LITERAL(0, 0, 14), // "analisis_graph"
QT_MOC_LITERAL(1, 15, 13), // "send_datetime"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "datetime"
QT_MOC_LITERAL(4, 39, 21), // "on_start_test_clicked"
QT_MOC_LITERAL(5, 61, 11), // "analysis_sm"
QT_MOC_LITERAL(6, 73, 23), // "on_graph_button_clicked"
QT_MOC_LITERAL(7, 97, 11), // "update_time"
QT_MOC_LITERAL(8, 109, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(9, 141, 5), // "index"
QT_MOC_LITERAL(10, 147, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(11, 181, 33), // "on_comboBox_3_currentIndexCha..."
QT_MOC_LITERAL(12, 215, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(13, 235, 7), // "checked"
QT_MOC_LITERAL(14, 243, 22), // "on_start_test_released"
QT_MOC_LITERAL(15, 266, 29), // "on_full_graph_button_released"
QT_MOC_LITERAL(16, 296, 22), // "on_xscale_valueChanged"
QT_MOC_LITERAL(17, 319, 4) // "arg1"

    },
    "analisis_graph\0send_datetime\0\0datetime\0"
    "on_start_test_clicked\0analysis_sm\0"
    "on_graph_button_clicked\0update_time\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_comboBox_3_currentIndexChanged\0"
    "on_checkBox_toggled\0checked\0"
    "on_start_test_released\0"
    "on_full_graph_button_released\0"
    "on_xscale_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_analisis_graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      10,    1,   86,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    3,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void analisis_graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        analisis_graph *_t = static_cast<analisis_graph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_datetime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->on_start_test_clicked(); break;
        case 2: _t->analysis_sm(); break;
        case 3: _t->on_graph_button_clicked(); break;
        case 4: _t->update_time((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_start_test_released(); break;
        case 10: _t->on_full_graph_button_released(); break;
        case 11: _t->on_xscale_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (analisis_graph::*_t)(QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_graph::send_datetime)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject analisis_graph::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_analisis_graph.data,
      qt_meta_data_analisis_graph,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *analisis_graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *analisis_graph::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_analisis_graph.stringdata0))
        return static_cast<void*>(const_cast< analisis_graph*>(this));
    return QDialog::qt_metacast(_clname);
}

int analisis_graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void analisis_graph::send_datetime(QDateTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
