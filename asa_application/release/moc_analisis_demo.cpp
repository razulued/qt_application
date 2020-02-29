/****************************************************************************
** Meta object code from reading C++ file 'analisis_demo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analisis_demo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analisis_demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_aleta_widget_t {
    QByteArrayData data[4];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_aleta_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_aleta_widget_t qt_meta_stringdata_aleta_widget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "aleta_widget"
QT_MOC_LITERAL(1, 13, 11), // "update_data"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16) // "toogle_hide_show"

    },
    "aleta_widget\0update_data\0\0toogle_hide_show"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aleta_widget[] = {

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
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void aleta_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        aleta_widget *_t = static_cast<aleta_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_data(); break;
        case 1: _t->toogle_hide_show(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject aleta_widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_aleta_widget.data,
      qt_meta_data_aleta_widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *aleta_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aleta_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_aleta_widget.stringdata0))
        return static_cast<void*>(const_cast< aleta_widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int aleta_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_analisis_demo_t {
    QByteArrayData data[20];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_analisis_demo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_analisis_demo_t qt_meta_stringdata_analisis_demo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "analisis_demo"
QT_MOC_LITERAL(1, 14, 14), // "update_donut_1"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 14), // "update_donut_2"
QT_MOC_LITERAL(5, 51, 14), // "update_donut_3"
QT_MOC_LITERAL(6, 66, 14), // "update_donut_4"
QT_MOC_LITERAL(7, 81, 13), // "send_datetime"
QT_MOC_LITERAL(8, 95, 8), // "datetime"
QT_MOC_LITERAL(9, 104, 15), // "update_datetime"
QT_MOC_LITERAL(10, 120, 13), // "PID_main_func"
QT_MOC_LITERAL(11, 134, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 156, 21), // "on_close_menu_clicked"
QT_MOC_LITERAL(13, 178, 20), // "on_show_menu_clicked"
QT_MOC_LITERAL(14, 199, 23), // "on_graph_button_clicked"
QT_MOC_LITERAL(15, 223, 28), // "on_control_A000_valueChanged"
QT_MOC_LITERAL(16, 252, 4), // "arg1"
QT_MOC_LITERAL(17, 257, 24), // "on_radioButton_2_toggled"
QT_MOC_LITERAL(18, 282, 7), // "checked"
QT_MOC_LITERAL(19, 290, 22) // "on_radioButton_toggled"

    },
    "analisis_demo\0update_donut_1\0\0value\0"
    "update_donut_2\0update_donut_3\0"
    "update_donut_4\0send_datetime\0datetime\0"
    "update_datetime\0PID_main_func\0"
    "on_pushButton_clicked\0on_close_menu_clicked\0"
    "on_show_menu_clicked\0on_graph_button_clicked\0"
    "on_control_A000_valueChanged\0arg1\0"
    "on_radioButton_2_toggled\0checked\0"
    "on_radioButton_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_analisis_demo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       7,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   99,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      19,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::QDateTime,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void analisis_demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        analisis_demo *_t = static_cast<analisis_demo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_donut_1((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->update_donut_2((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->update_donut_3((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->update_donut_4((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->send_datetime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 5: _t->update_datetime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 6: _t->PID_main_func(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_close_menu_clicked(); break;
        case 9: _t->on_show_menu_clicked(); break;
        case 10: _t->on_graph_button_clicked(); break;
        case 11: _t->on_control_A000_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_radioButton_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (analisis_demo::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_demo::update_donut_1)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (analisis_demo::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_demo::update_donut_2)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (analisis_demo::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_demo::update_donut_3)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (analisis_demo::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_demo::update_donut_4)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (analisis_demo::*_t)(QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&analisis_demo::send_datetime)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject analisis_demo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_analisis_demo.data,
      qt_meta_data_analisis_demo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *analisis_demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *analisis_demo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_analisis_demo.stringdata0))
        return static_cast<void*>(const_cast< analisis_demo*>(this));
    return QDialog::qt_metacast(_clname);
}

int analisis_demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void analisis_demo::update_donut_1(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void analisis_demo::update_donut_2(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void analisis_demo::update_donut_3(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void analisis_demo::update_donut_4(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void analisis_demo::send_datetime(QDateTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
