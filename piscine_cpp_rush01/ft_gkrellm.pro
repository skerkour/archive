#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T12:04:34
#
#-------------------------------------------------

QT  += core gui
QT  += charts
QT  += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

mac {
  CONFIG -= app_bundle
}

TARGET = ft_gkrellm
TEMPLATE = app

SOURCES +=	ADisplay.cpp \
			CliDisplay.cpp \
			CpuModule.cpp \
			GuiDisplay.cpp \
			HostModule.cpp \
			MainWindow.cpp \
			Monitor.cpp \
			NetModule.cpp \
			PonyModule.cpp \
			RamModule.cpp \
			main.cpp

HEADERS +=	ADisplay.hpp \
			CliDisplay.hpp \
			CpuModule.hpp \
			GuiDisplay.hpp \
			HostModule.hpp \
			IMonitorDisplay.hpp \
			IMonitorModule.hpp \
			MainWindow.hpp \
			Monitor.hpp \
			NetModule.hpp \
			PonyModule.hpp \
			RamModule.hpp

QMAKE_CXXFLAGS += -Wall -Wextra -Werror -O3

LIBS += -lncurses

# --------------------------- make rules
fclean.depends = clean
fclean.commands = rm -rf $(TARGET)
QMAKE_EXTRA_TARGETS += fclean

re.depends = fclean all
QMAKE_EXTRA_TARGETS += re
