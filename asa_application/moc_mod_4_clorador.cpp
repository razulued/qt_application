/****************************************************************************
** Meta object code from reading C++ file 'mod_4_clorador.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mod_4_clorador.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mod_4_clorador.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mod_4_clorador_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mod_4_clorador_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mod_4_clorador_t qt_meta_stringdata_mod_4_clorador = {
    {
QT_MOC_LITERAL(0, 0, 14), // "mod_4_clorador"
QT_MOC_LITERAL(1, 15, 13), // "update_window"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "mod_4_clorador\0update_window\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mod_4_clorador[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void mod_4_clorador::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mod_4_clorador *_t = static_cast<mod_4_clorador *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_window(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mod_4_clorador::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mod_4_clorador::update_window)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject mod_4_clorador::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mod_4_clorador.data,
      qt_meta_data_mod_4_clorador,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mod_4_clorador::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mod_4_clorador::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mod_4_clorador.stringdata0))
        return static_cast<void*>(const_cast< mod_4_clorador*>(this));
    return QWidget::qt_metacast(_clname);
}

int mod_4_clorador::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void mod_4_clorador::update_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
