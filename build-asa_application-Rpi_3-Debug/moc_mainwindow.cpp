/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../asa_application/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "handleMenuButton"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 32), // "handleParametrosElectricosButton"
QT_MOC_LITERAL(4, 62, 29), // "handleParametrosFisicosButton"
QT_MOC_LITERAL(5, 92, 30), // "handleParametrosQuimicosButton"
QT_MOC_LITERAL(6, 123, 20), // "handleDetailedView_1"
QT_MOC_LITERAL(7, 144, 20), // "handleDetailedView_2"
QT_MOC_LITERAL(8, 165, 20), // "handleDetailedView_3"
QT_MOC_LITERAL(9, 186, 20), // "handleDetailedView_4"
QT_MOC_LITERAL(10, 207, 20), // "handleDetailedView_5"
QT_MOC_LITERAL(11, 228, 20), // "handleDetailedView_6"
QT_MOC_LITERAL(12, 249, 19), // "on_asa_logo_clicked"
QT_MOC_LITERAL(13, 269, 13) // "dataTimerSlot"

    },
    "MainWindow\0handleMenuButton\0\0"
    "handleParametrosElectricosButton\0"
    "handleParametrosFisicosButton\0"
    "handleParametrosQuimicosButton\0"
    "handleDetailedView_1\0handleDetailedView_2\0"
    "handleDetailedView_3\0handleDetailedView_4\0"
    "handleDetailedView_5\0handleDetailedView_6\0"
    "on_asa_logo_clicked\0dataTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleMenuButton(); break;
        case 1: _t->handleParametrosElectricosButton(); break;
        case 2: _t->handleParametrosFisicosButton(); break;
        case 3: _t->handleParametrosQuimicosButton(); break;
        case 4: _t->handleDetailedView_1(); break;
        case 5: _t->handleDetailedView_2(); break;
        case 6: _t->handleDetailedView_3(); break;
        case 7: _t->handleDetailedView_4(); break;
        case 8: _t->handleDetailedView_5(); break;
        case 9: _t->handleDetailedView_6(); break;
        case 10: _t->on_asa_logo_clicked(); break;
        case 11: _t->dataTimerSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
QT_END_MOC_NAMESPACE
