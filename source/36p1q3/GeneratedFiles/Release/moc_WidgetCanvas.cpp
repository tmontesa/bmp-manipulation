/****************************************************************************
** Meta object code from reading C++ file 'WidgetCanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WidgetCanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetCanvas_t {
    QByteArrayData data[12];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetCanvas_t qt_meta_stringdata_WidgetCanvas = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WidgetCanvas"
QT_MOC_LITERAL(1, 13, 14), // "GetPixelstream"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "w"
QT_MOC_LITERAL(4, 31, 1), // "h"
QT_MOC_LITERAL(5, 33, 12), // "SetEffectRGB"
QT_MOC_LITERAL(6, 46, 12), // "SetEffectRed"
QT_MOC_LITERAL(7, 59, 14), // "SetEffectGreen"
QT_MOC_LITERAL(8, 74, 13), // "SetEffectBlue"
QT_MOC_LITERAL(9, 88, 15), // "SetEffectBright"
QT_MOC_LITERAL(10, 104, 18), // "SetEffectGreyscale"
QT_MOC_LITERAL(11, 123, 15) // "SetEffectDither"

    },
    "WidgetCanvas\0GetPixelstream\0\0w\0h\0"
    "SetEffectRGB\0SetEffectRed\0SetEffectGreen\0"
    "SetEffectBlue\0SetEffectBright\0"
    "SetEffectGreyscale\0SetEffectDither"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetCanvas[] = {

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
       1,    3,   54,    2, 0x0a /* Public */,
       5,    0,   61,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    2,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetCanvas *_t = static_cast<WidgetCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetPixelstream((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->SetEffectRGB(); break;
        case 2: _t->SetEffectRed(); break;
        case 3: _t->SetEffectGreen(); break;
        case 4: _t->SetEffectBlue(); break;
        case 5: _t->SetEffectBright(); break;
        case 6: _t->SetEffectGreyscale(); break;
        case 7: _t->SetEffectDither(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetCanvas.data,
      qt_meta_data_WidgetCanvas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetCanvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
