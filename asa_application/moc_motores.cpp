/****************************************************************************
** Meta object code from reading C++ file 'motores.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "motores.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'motores.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_motores_t {
    QByteArrayData data[16];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_motores_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_motores_t qt_meta_stringdata_motores = {
    {
QT_MOC_LITERAL(0, 0, 7), // "motores"
QT_MOC_LITERAL(1, 8, 12), // "release_lock"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 19), // "on_asa_logo_clicked"
QT_MOC_LITERAL(4, 42, 24), // "out_checkBoxStateChanged"
QT_MOC_LITERAL(5, 67, 18), // "background_clicked"
QT_MOC_LITERAL(6, 86, 13), // "checkActivity"
QT_MOC_LITERAL(7, 100, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 122, 9), // "checkStop"
QT_MOC_LITERAL(9, 132, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(10, 154, 22), // "on_pushButton_released"
QT_MOC_LITERAL(11, 177, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(12, 209, 5), // "index"
QT_MOC_LITERAL(13, 215, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(14, 249, 33), // "on_comboBox_3_currentIndexCha..."
QT_MOC_LITERAL(15, 283, 33) // "on_comboBox_4_currentIndexCha..."

    },
    "motores\0release_lock\0\0on_asa_logo_clicked\0"
    "out_checkBoxStateChanged\0background_clicked\0"
    "checkActivity\0on_pushButton_clicked\0"
    "checkStop\0on_pushButton_pressed\0"
    "on_pushButton_released\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_comboBox_3_currentIndexChanged\0"
    "on_comboBox_4_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_motores[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void motores::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        motores *_t = static_cast<motores *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->release_lock(); break;
        case 1: _t->on_asa_logo_clicked(); break;
        case 2: _t->out_checkBoxStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->background_clicked(); break;
        case 4: _t->checkActivity(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->checkStop(); break;
        case 7: _t->on_pushButton_pressed(); break;
        case 8: _t->on_pushButton_released(); break;
        case 9: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_4_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (motores::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&motores::release_lock)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject motores::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_motores.data,
      qt_meta_data_motores,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *motores::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *motores::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_motores.stringdata0))
        return static_cast<void*>(const_cast< motores*>(this));
    return QDialog::qt_metacast(_clname);
}

int motores::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void motores::release_lock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
