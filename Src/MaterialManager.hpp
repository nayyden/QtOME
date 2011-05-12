#ifndef MATERIALMANAGER_HPP
#define MATERIALMANAGER_HPP

#include <OGRE/Ogre.h>
#include <QStringList>
#include <QString>
#include <QMap>
#include <OGRE/OgreSingleton.h>

class MaterialManager : public Ogre::Singleton<MaterialManager>
{
public:
    MaterialManager();
    QStringList     getMaterialList(const QString & Path);
    QStringList     getCompositorList();
    QString         getFileName(const QString& Material);
    QString         getCompositorFileName(const QString& Material);
    QString         getWorkDir();
    void            addMaterial(const QString &script, const QString &name);
    Ogre::String    getCompositorName();
private:
    std::vector<Ogre::Material*>   mats;
    Ogre::MaterialPtr              currentMaterial;
    int                            count;
    QMap<QString,QString>          fileNames;
    QMap<QString,QString>          fileNames_Compositor;
    QString                        workDir;
    QString                        compositorName;
};

#endif // MATERIALMANAGER_HPP
