/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[362];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "send_date_hour"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "date_time"
QT_MOC_LITERAL(4, 37, 19), // "send_num_activities"
QT_MOC_LITERAL(5, 57, 3), // "act"
QT_MOC_LITERAL(6, 61, 16), // "handleMenuButton"
QT_MOC_LITERAL(7, 78, 32), // "handleParametrosElectricosButton"
QT_MOC_LITERAL(8, 111, 29), // "handleParametrosFisicosButton"
QT_MOC_LITERAL(9, 141, 30), // "handleParametrosQuimicosButton"
QT_MOC_LITERAL(10, 172, 20), // "handleDetailedView_9"
QT_MOC_LITERAL(11, 193, 11), // "update_this"
QT_MOC_LITERAL(12, 205, 19), // "on_asa_logo_clicked"
QT_MOC_LITERAL(13, 225, 13), // "dataTimerSlot"
QT_MOC_LITERAL(14, 239, 12), // "new_spi_data"
QT_MOC_LITERAL(15, 252, 19), // "on_prof_pic_clicked"
QT_MOC_LITERAL(16, 272, 12), // "update_title"
QT_MOC_LITERAL(17, 285, 4), // "text"
QT_MOC_LITERAL(18, 290, 22), // "on_label_title_clicked"
QT_MOC_LITERAL(19, 313, 17), // "check_title_click"
QT_MOC_LITERAL(20, 331, 13), // "window_closed"
QT_MOC_LITERAL(21, 345, 16) // "update_demo_mode"

    },
    "MainWindow\0send_date_hour\0\0date_time\0"
    "send_num_activities\0act\0handleMenuButton\0"
    "handleParametrosElectricosButton\0"
    "handleParametrosFisicosButton\0"
    "handleParametrosQuimicosButton\0"
    "handleDetailedView_9\0update_this\0"
    "on_asa_logo_clicked\0dataTimerSlot\0"
    "new_spi_data\0on_prof_pic_clicked\0"
    "update_title\0text\0on_label_title_clicked\0"
    "check_title_click\0window_closed\0"
    "update_demo_mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  105,    2, 0x0a /* Public */,
       7,    0,  106,    2, 0x0a /* Public */,
       8,    0,  107,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    0,  110,    2, 0x0a /* Public */,
      12,    0,  111,    2, 0x08 /* Private */,
      13,    0,  112,    2, 0x08 /* Private */,
      14,    0,  113,    2, 0x08 /* Private */,
      15,    0,  114,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime,    3,
    QMetaType::Void, QMetaType::UInt,    5,

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
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_date_hour((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->send_num_activities((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->handleMenuButton(); break;
        case 3: _t->handleParametrosElectricosButton(); break;
        case 4: _t->handleParametrosFisicosButton(); break;
        case 5: _t->handleParametrosQuimicosButton(); break;
        case 6: _t->handleDetailedView_9(); break;
        case 7: _t->update_this(); break;
        case 8: _t->on_asa_logo_clicked(); break;
        case 9: _t->dataTimerSlot(); break;
        case 10: _t->new_spi_data(); break;
        case 11: _t->on_prof_pic_clicked(); break;
        case 12: _t->update_title((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->on_label_title_clicked(); break;
        case 14: _t->check_title_click(); break;
        case 15: _t->window_closed(); break;
        case 16: _t->update_demo_mode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::send_date_hour)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::send_num_activities)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_date_hour(QDateTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::send_num_activities(uint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
