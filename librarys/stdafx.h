/**
 *  stdafx.h：预编译头文件
 *  提前编译常用的头文件
**/

#ifndef __ATC_STDAFX_H__
#define __ATC_STDAFX_H__

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

using namespace std;

// 标准库
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>

// qt库
#include <QtCore>
#include <QtGui>
#include <QtXml>
#include <QtQml>
#include <qglobal.h>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets/QWidget>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/QTableView.h>
#include <QtWidgets/qaction.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qdialog.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qgroupbox.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qscrollbar.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qprogressbar.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qtextedit.h>
#include <QtWidgets/qtreewidget.h>
#include <QtWidgets/qprogressbar.h>
#include <QtWidgets/qlistview.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qbuttongroup.h>
#include <QtWidgets/qdatetimeedit.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qdatetimeedit.h>
#include <QtWidgets/qtooltip.h>
#include <QtWidgets/qwidget.h>
#endif

// boost库
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>

#endif
