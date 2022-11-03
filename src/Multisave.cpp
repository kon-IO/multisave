//============================================================================
// Name        : Multisave.cpp
// Author      : kon-io
// Version     :
// Copyright   : Copyright (c) 2022 Konstantinos Koliopoulos
// Description : Entry point of Multisave
//============================================================================

#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "MainWidget.h"

int main() {
	int argc = 0;
	QApplication app(argc, {});
	MainWidget main;
	main.show();
	return app.exec();
}
