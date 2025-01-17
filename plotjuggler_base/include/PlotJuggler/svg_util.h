#ifndef PJ_SVG_UTIL_H
#define PJ_SVG_UTIL_H

#ifdef QT_NO_SVGRENDERER
  #error "QT_NO_SVGRENDERER defined"
#endif

#include <QtSvg>
#include <QFile>
#include <QIcon>
#include <QTextStream>
#include <QByteArray>
#include <QPainter>
#include <QPixmap>
#include <QDebug>

// Useful function to change the color of SVG icons programmatically.
// Useful to switch between dark view and light view.
// To work, the SVG file must use the color #ffffff and #000000 only.
inline QPixmap LoadSvg(QString filename, QString style_name = "light")
{
  QFile file(filename);
  file.open(QFile::ReadOnly | QFile::Text);
  auto svg_data = file.readAll();
  file.close();

  if( style_name.contains("light") )
  {
    svg_data.replace("#000000", "#111111");
    svg_data.replace("#ffffff", "#dddddd");
  }
  else{
    svg_data.replace("#000000", "#dddddd");
    svg_data.replace("#ffffff", "#111111");
  }

  QByteArray content(svg_data);

  QSvgRenderer rr( content );
  QImage image(64, 64, QImage::Format_ARGB32);
  QPainter painter(&image);
  image.fill(Qt::transparent);
  rr.render(&painter);

  return QPixmap::fromImage(image);
}


#endif // PJ_SVG_UTIL_H
