#include "FormImageToPdf.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FormImageToPdf w(a.applicationDirPath());

    return 1;
}
