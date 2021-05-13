/****************************************************************************
** Meta object code from reading C++ file 'DicomViewerDemo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DicomViewerDemo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DicomViewerDemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DicomViewerDemo_t {
    QByteArrayData data[21];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DicomViewerDemo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DicomViewerDemo_t qt_meta_stringdata_DicomViewerDemo = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DicomViewerDemo"
QT_MOC_LITERAL(1, 16, 5), // "openB"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "openBT"
QT_MOC_LITERAL(4, 30, 4), // "open"
QT_MOC_LITERAL(5, 35, 5), // "openG"
QT_MOC_LITERAL(6, 41, 5), // "openS"
QT_MOC_LITERAL(7, 47, 5), // "openC"
QT_MOC_LITERAL(8, 53, 5), // "openE"
QT_MOC_LITERAL(9, 59, 8), // "openRGBE"
QT_MOC_LITERAL(10, 68, 6), // "openGP"
QT_MOC_LITERAL(11, 75, 6), // "openSH"
QT_MOC_LITERAL(12, 82, 5), // "open2"
QT_MOC_LITERAL(13, 88, 25), // "on_actionQuit_2_triggered"
QT_MOC_LITERAL(14, 114, 4), // "save"
QT_MOC_LITERAL(15, 119, 5), // "openI"
QT_MOC_LITERAL(16, 125, 8), // "openblur"
QT_MOC_LITERAL(17, 134, 11), // "openprewitt"
QT_MOC_LITERAL(18, 146, 15), // "openHSIequation"
QT_MOC_LITERAL(19, 162, 15), // "openHSVequation"
QT_MOC_LITERAL(20, 178, 20) // "opendoubletchreshold"

    },
    "DicomViewerDemo\0openB\0\0openBT\0open\0"
    "openG\0openS\0openC\0openE\0openRGBE\0"
    "openGP\0openSH\0open2\0on_actionQuit_2_triggered\0"
    "save\0openI\0openblur\0openprewitt\0"
    "openHSIequation\0openHSVequation\0"
    "opendoubletchreshold"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DicomViewerDemo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DicomViewerDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DicomViewerDemo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openB(); break;
        case 1: _t->openBT(); break;
        case 2: _t->open(); break;
        case 3: _t->openG(); break;
        case 4: _t->openS(); break;
        case 5: _t->openC(); break;
        case 6: _t->openE(); break;
        case 7: _t->openRGBE(); break;
        case 8: _t->openGP(); break;
        case 9: _t->openSH(); break;
        case 10: _t->open2(); break;
        case 11: _t->on_actionQuit_2_triggered(); break;
        case 12: _t->save(); break;
        case 13: _t->openI(); break;
        case 14: _t->openblur(); break;
        case 15: _t->openprewitt(); break;
        case 16: _t->openHSIequation(); break;
        case 17: _t->openHSVequation(); break;
        case 18: _t->opendoubletchreshold(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DicomViewerDemo::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DicomViewerDemo.data,
    qt_meta_data_DicomViewerDemo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DicomViewerDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DicomViewerDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DicomViewerDemo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DicomViewerDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
