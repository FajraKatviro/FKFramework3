#ifndef PACKAGEGENERATOR_H
#define PACKAGEGENERATOR_H

#include <QTextStream>
#include <QDir>
#include <QMap>
#include <QSize>

class QString;
class QStringList;

class PackageGenerator{
public:
    PackageGenerator(const QString& sourcePath,const QString& buildPath);
    bool readSetting();

    bool cleanImages(const bool excessiveOnly);
    bool addImages();
    bool buildQRC();
    bool buildRCC();
    QStringList resourceList() const;

    static bool writeResourceList(const QString path, const QStringList list);

    void setQtBinaryPath(const QString& path);
private:
    void output(const QString& msg);

    bool processImage(const QString& image,const QSize& sourceSize,const QSize& targetSize,const bool crop);

    QDir _sourceFolder;
    QDir _buildFolder;
    QTextStream _output;

    struct ImageSetting{
        QList<QSize> sourceSizes;
        QList<QSize> usedSizes;
        bool crop;
    };

    QList<QSize> _targetSizes;
    QMap<QString,ImageSetting> _imageSettings;

    QString _qtBinaryPath;
};

#endif // PACKAGEGENERATOR_H
