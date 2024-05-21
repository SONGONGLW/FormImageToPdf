#include "FormImageToPdf.h"

#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QDir>

#pragma execution_character_set("utf-8")

FormImageToPdf::FormImageToPdf(const QString &image_path, QWidget *parent)
    : QWidget(parent)
{
    QPdfWriter pdf(image_path + "/ss.pdf");
    pdf.setTitle("Title");
    pdf.setCreator("Creator");
    pdf.setPdfVersion(QPdfWriter::PdfVersion_1_4);
    pdf.setPageSize(QPdfWriter::A4);
    pdf.setMargins({0, 0, 0, 0});
    pdf.setResolution(300);

    QDir dir(image_path);
    QFileInfoList fileinfos = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    //pdf类没提供删除页接口，故先筛选出所有图片确定图片数量
    QStringList images;
    for(auto &it : fileinfos)
    {
        QStringList imageExtensions = {"png", "jpg", "jpeg", "bmp", "tiff"};
        if(imageExtensions.contains(it.suffix().toLower()))
        {
            qDebug() << it.filePath();
            images << it.filePath();
        }
    }

    QPainter painter(&pdf);
    for (auto it = images.begin(); it != images.end(); ++it)
    {
        QImage image(*it);
        QRect rect = painter.viewport();
        image = image.scaled(rect.size(), Qt::KeepAspectRatio); //将图片等比例缩放
        int x = 0;
        int y = 0;
        if(image.width() == rect.width())
        {
            y = (rect.height() - image.height()) / 2;
        }
        else
        {
            x = (rect.width() - image.width()) / 2;
        }
        painter.drawImage(x, y, image);

        if(it + 1 == images.end())
        {
            break;
        }
        pdf.newPage();
    }
}

FormImageToPdf::~FormImageToPdf()
{

}

