/****************************************************************************
** Meta object code from reading C++ file 'contacto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/contacto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contacto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_contacto_t {
    QByteArrayData data[11];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_contacto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_contacto_t qt_meta_stringdata_contacto = {
    {
QT_MOC_LITERAL(0, 0, 8), // "contacto"
QT_MOC_LITERAL(1, 9, 9), // "close_app"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "release_lock"
QT_MOC_LITERAL(4, 33, 18), // "background_clicked"
QT_MOC_LITERAL(5, 52, 24), // "on_push_cancelar_clicked"
QT_MOC_LITERAL(6, 77, 26), // "on_push_cancelar_2_clicked"
QT_MOC_LITERAL(7, 104, 26), // "on_push_cancelar_3_clicked"
QT_MOC_LITERAL(8, 131, 26), // "on_push_cancelar_4_clicked"
QT_MOC_LITERAL(9, 158, 16), // "on_close_clicked"
QT_MOC_LITERAL(10, 175, 21) // "on_top_menu_5_clicked"

    },
    "contacto\0close_app\0\0release_lock\0"
    "background_clicked\0on_push_cancelar_clicked\0"
    "on_push_cancelar_2_clicked\0"
    "on_push_cancelar_3_clicked\0"
    "on_push_cancelar_4_clicked\0on_close_clicked\0"
    "on_top_menu_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_contacto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void contacto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        contacto *_t = static_cast<contacto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->close_app(); break;
        case 1: _t->release_lock(); break;
        case 2: _t->background_clicked(); break;
        case 3: _t->on_push_cancelar_clicked(); break;
        case 4: _t->on_push_cancelar_2_clicked(); break;
        case 5: _t->on_push_cancelar_3_clicked(); break;
        case 6: _t->on_push_cancelar_4_clicked(); break;
        case 7: _t->on_close_clicked(); break;
        case 8: _t->on_top_menu_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (contacto::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&contacto::close_app)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (contacto::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&contacto::release_lock)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject contacto::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_contacto.data,
      qt_meta_data_contacto,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *contacto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *contacto::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_contacto.stringdata0))
        return static_cast<void*>(const_cast< contacto*>(this));
    return QDialog::qt_metacast(_clname);
}

int contacto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void contacto::close_app()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void contacto::release_lock()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
