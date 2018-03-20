/****************************************************************************
** Meta object code from reading C++ file 'userlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CarRent2/userlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserLogin_t {
    QByteArrayData data[9];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserLogin_t qt_meta_stringdata_UserLogin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UserLogin"
QT_MOC_LITERAL(1, 10, 4), // "Exit"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 4), // "Rent"
QT_MOC_LITERAL(4, 21, 11), // "FinishOrder"
QT_MOC_LITERAL(5, 33, 11), // "ReviseBasic"
QT_MOC_LITERAL(6, 45, 8), // "AddMoney"
QT_MOC_LITERAL(7, 54, 10), // "ChangePass"
QT_MOC_LITERAL(8, 65, 6) // "select"

    },
    "UserLogin\0Exit\0\0Rent\0FinishOrder\0"
    "ReviseBasic\0AddMoney\0ChangePass\0select"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

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

void UserLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserLogin *_t = static_cast<UserLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Exit(); break;
        case 1: _t->Rent(); break;
        case 2: _t->FinishOrder(); break;
        case 3: _t->ReviseBasic(); break;
        case 4: _t->AddMoney(); break;
        case 5: _t->ChangePass(); break;
        case 6: _t->select(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserLogin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserLogin.data,
      qt_meta_data_UserLogin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserLogin.stringdata0))
        return static_cast<void*>(const_cast< UserLogin*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
