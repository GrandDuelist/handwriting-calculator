/****************************************************************************
** Meta object code from reading C++ file 'back.h'
**
** Created: Fri Jun 28 13:27:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/back.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'back.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Back[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      28,    5,    5,    5, 0x08,
      54,    5,    5,    5, 0x08,
      78,    5,    5,    5, 0x08,
     104,    5,    5,    5, 0x08,
     130,    5,    5,    5, 0x08,
     156,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Back[] = {
    "Back\0\0on_Okbutton_clicked()\0"
    "on_cancelbutton_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
};

void Back::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Back *_t = static_cast<Back *>(_o);
        switch (_id) {
        case 0: _t->on_Okbutton_clicked(); break;
        case 1: _t->on_cancelbutton_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Back::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Back::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Back,
      qt_meta_data_Back, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Back::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Back::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Back::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Back))
        return static_cast<void*>(const_cast< Back*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Back::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
