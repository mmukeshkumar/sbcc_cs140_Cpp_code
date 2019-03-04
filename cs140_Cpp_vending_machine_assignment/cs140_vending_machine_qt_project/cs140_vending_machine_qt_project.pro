HEADERS     = \ 
    vendingmachinewidget.h \
    user.h \
    customer.h \
    product.h \
    admin.h \
    vendingmachine.h \
    basevendingmachine.h
SOURCES	    = main.cpp \
    my_vending_machine_widget.cpp \
    product.cpp \
    sbcc_cs140_vending_machine.cpp \
    admin.cpp \
    customer.cpp
FORMS       = \
    vendingmachine.ui

# install
target.path = cs140_vending_machine_qt_project
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources

