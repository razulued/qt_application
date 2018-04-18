/****************************************************************************
** Meta object code from reading C++ file 'login_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/login_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_login_dialog_t {
    QByteArrayData data[13];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_login_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_login_dialog_t qt_meta_stringdata_login_dialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "login_dialog"
QT_MOC_LITERAL(1, 13, 16), // "on_key_0_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "on_key_1_clicked"
QT_MOC_LITERAL(4, 48, 16), // "on_key_2_clicked"
QT_MOC_LITERAL(5, 65, 16), // "on_key_3_clicked"
QT_MOC_LITERAL(6, 82, 16), // "on_key_4_clicked"
QT_MOC_LITERAL(7, 99, 16), // "on_key_5_clicked"
QT_MOC_LITERAL(8, 116, 16), // "on_key_6_clicked"
QT_MOC_LITERAL(9, 133, 16), // "on_key_7_clicked"
QT_MOC_LITERAL(10, 150, 16), // "on_key_8_clicked"
QT_MOC_LITERAL(11, 167, 16), // "on_key_9_clicked"
QT_MOC_LITERAL(12, 184, 20) // "on_key_enter_clicked"

    },
    "login_dialog\0on_key_0_clicked\0\0"
    "on_key_1_clicked\0on_key_2_clicked\0"
    "on_key_3_clicked\0on_key_4_clicked\0"
    "on_key_5_clicked\0on_key_6_clicked\0"
    "on_key_7_clicked\0on_key_8_clicked\0"
    "on_key_9_clicked\0on_key_enter_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_login_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void login_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        login_dialog *_t = static_cast<login_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_key_0_clicked(); break;
        case 1: _t->on_key_1_clicked(); break;
        case 2: _t->on_key_2_clicked(); break;
        case 3: _t->on_key_3_clicked(); break;
        case 4: _t->on_key_4_clicked(); break;
        case 5: _t->on_key_5_clicked(); break;
        case 6: _t->on_key_6_clicked(); break;
        case 7: _t->on_key_7_clicked(); break;
        case 8: _t->on_key_8_clicked(); break;
        case 9: _t->on_key_9_clicked(); break;
        case 10: _t->on_key_enter_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject login_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_login_dialog.data,
      qt_meta_data_login_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *login_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *login_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_login_dialog.stringdata0))
        return static_cast<void*>(const_cast< login_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int login_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
