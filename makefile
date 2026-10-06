CXX = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCLUDES = -I../UNIX_Exercice1 -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I/usr/lib64/qt5/mkspecs/linux-g++
LIBS = /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread

TARGET = CLINUX_Exercice2
OBJS = main.o mywindow.o moc_mywindow.o FichierUtilisateur.o

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o main.o main.cpp

mywindow.o: mywindow.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o mywindow.o mywindow.cpp

moc_mywindow.o: moc_mywindow.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o moc_mywindow.o moc_mywindow.cpp

FichierUtilisateur.o: FichierUtilisateur.cpp
	$(CXX) -c FichierUtilisateur.cpp

clean:
	rm -f $(OBJS) $(TARGET)
