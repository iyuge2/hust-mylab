/****************************************************************************
** Meta object code from reading C++ file 'syslogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CarRent2/syslogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'syslogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SysLogin_t {
    QByteArrayData data[16];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysLogin_t qt_meta_stringdata_SysLogin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SysLogin"
QT_MOC_LITERAL(1, 9, 4), // "Exit"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 6), // "select"
QT_MOC_LITERAL(4, 22, 6), // "AddCar"
QT_MOC_LITERAL(5, 29, 6), // "DelCar"
QT_MOC_LITERAL(6, 36, 6), // "RevCar"
QT_MOC_LITERAL(7, 43, 9), // "AddWorker"
QT_MOC_LITERAL(8, 53, 9), // "DelWorker"
QT_MOC_LITERAL(9, 63, 7), // "DelUser"
QT_MOC_LITERAL(10, 71, 9), // "QueryRent"
QT_MOC_LITERAL(11, 81, 11), // "ChangeBasic"
QT_MOC_LITERAL(12, 93, 10), // "ChangePass"
QT_MOC_LITERAL(13, 104, 7), // "AddWage"
QT_MOC_LITERAL(14, 112, 9), // "GivePrize"
QT_MOC_LITERAL(15, 122, 10) // "QueryMoney"

    },
    "SysLogin\0Exit\0\0select\0AddCar\0DelCar\0"
    "RevCar\0AddWorker\0DelWorker\0DelUser\0"
    "QueryRent\0ChangeBasic\0ChangePass\0"
    "AddWage\0GivePrize\0QueryMoney"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

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

       0        // eod
};

void SysLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SysLogin *_t = static_cast<SysLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Exit(); break;
        case 1: _t->select(); break;
        case 2: _t->AddCar(); break;
        case 3: _t->DelCar(); break;
        case 4: _t->RevCar(); break;
        case 5: _t->AddWorker(); break;
        case 6: _t->DelWorker(); break;
        case 7: _t->DelUser(); break;
        case 8: _t->QueryRent(); break;
        case 9: _t->ChangeBasic(); break;
        case 10: _t->ChangePass(); break;
        case 11: _t->AddWage(); break;
        case 12: _t->GivePrize(); break;
        case 13: _t->QueryMoney(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SysLogin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SysLogin.data,
      qt_meta_data_SysLogin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SysLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SysLogin.stringdata0))
        return static_cast<void*>(const_cast< SysLogin*>(this));
    return QDialog::qt_metacast(_clname);
}

int SysLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
