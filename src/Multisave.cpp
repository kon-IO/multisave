//============================================================================
// Name        : Multisave.cpp
// Author      : kon-io
// Version     :
// Copyright   : Copyright (c) 2022 Konstantinos Koliopoulos
// Description : Entry point of Multisave
//============================================================================

#include <iostream>
#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>
#include <QtWidgets/QMainWindow>

#include "MainWidget.h"

int main() {
	int argc = 0;
	QTranslator translator;
	translator.load(QLocale("el_GR"), QLatin1String("multisave"), QLatin1String("_"));

	QApplication app(argc, {});
	app.installTranslator(&translator);

	MainWidget main;
	main.show();

	return app.exec();
}
