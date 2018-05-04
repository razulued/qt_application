/****************************************************************************
** Meta object code from reading C++ file 'simulation_input.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/simulation_input.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulation_input.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_simulation_input_t {
    QByteArrayData data[11];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simulation_input_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simulation_input_t qt_meta_stringdata_simulation_input = {
    {
QT_MOC_LITERAL(0, 0, 16), // "simulation_input"
QT_MOC_LITERAL(1, 17, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 38), // "on_horizontalScrollBar_action..."
QT_MOC_LITERAL(4, 77, 6), // "action"
QT_MOC_LITERAL(5, 84, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(6, 112, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(7, 134, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(8, 156, 40), // "on_horizontalScrollBar_2_acti..."
QT_MOC_LITERAL(9, 197, 40), // "on_horizontalScrollBar_3_acti..."
QT_MOC_LITERAL(10, 238, 40) // "on_horizontalScrollBar_4_acti..."

    },
    "simulation_input\0on_checkBox_clicked\0"
    "\0on_horizontalScrollBar_actionTriggered\0"
    "action\0on_lineEdit_editingFinished\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked\0"
    "on_horizontalScrollBar_2_actionTriggered\0"
    "on_horizontalScrollBar_3_actionTriggered\0"
    "on_horizontalScrollBar_4_actionTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simulation_input[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void simulation_input::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        simulation_input *_t = static_cast<simulation_input *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkBox_clicked(); break;
        case 1: _t->on_horizontalScrollBar_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_editingFinished(); break;
        case 3: _t->on_checkBox_2_clicked(); break;
        case 4: _t->on_checkBox_3_clicked(); break;
        case 5: _t->on_horizontalScrollBar_2_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_horizontalScrollBar_3_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_horizontalScrollBar_4_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject simulation_input::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_simulation_input.data,
      qt_meta_data_simulation_input,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *simulation_input::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simulation_input::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_simulation_input.stringdata0))
        return static_cast<void*>(const_cast< simulation_input*>(this));
    return QDialog::qt_metacast(_clname);
}

int simulation_input::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
