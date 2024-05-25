/****************************************************************************
** Meta object code from reading C++ file 'customdic.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../projectdemo/customdic.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customdic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASScustomdicENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASScustomdicENDCLASS = QtMocHelpers::stringData(
    "customdic",
    "on_new_2_clicked",
    "",
    "on_entername_textChanged",
    "on_change_clicked",
    "on_enterid_textChanged",
    "on_delete_2_clicked",
    "on_pushButton_clicked",
    "on_save_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScustomdicENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[18];
    char stringdata5[23];
    char stringdata6[20];
    char stringdata7[22];
    char stringdata8[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScustomdicENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScustomdicENDCLASS_t qt_meta_stringdata_CLASScustomdicENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "customdic"
        QT_MOC_LITERAL(10, 16),  // "on_new_2_clicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 24),  // "on_entername_textChanged"
        QT_MOC_LITERAL(53, 17),  // "on_change_clicked"
        QT_MOC_LITERAL(71, 22),  // "on_enterid_textChanged"
        QT_MOC_LITERAL(94, 19),  // "on_delete_2_clicked"
        QT_MOC_LITERAL(114, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(136, 15)   // "on_save_clicked"
    },
    "customdic",
    "on_new_2_clicked",
    "",
    "on_entername_textChanged",
    "on_change_clicked",
    "on_enterid_textChanged",
    "on_delete_2_clicked",
    "on_pushButton_clicked",
    "on_save_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScustomdicENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

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

Q_CONSTINIT const QMetaObject customdic::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScustomdicENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScustomdicENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScustomdicENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<customdic, std::true_type>,
        // method 'on_new_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_entername_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_change_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enterid_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delete_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void customdic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<customdic *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_new_2_clicked(); break;
        case 1: _t->on_entername_textChanged(); break;
        case 2: _t->on_change_clicked(); break;
        case 3: _t->on_enterid_textChanged(); break;
        case 4: _t->on_delete_2_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_save_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *customdic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customdic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScustomdicENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int customdic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
