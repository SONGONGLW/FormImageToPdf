#ifndef FORMIMAGETOPDF_H
#define FORMIMAGETOPDF_H

#include <QWidget>

class FormImageToPdf : public QWidget
{
    Q_OBJECT

public:
    FormImageToPdf(const QString &image_path, QWidget *parent = nullptr);
    ~FormImageToPdf();

private:


};
#endif // FORMIMAGETOPDF_H
