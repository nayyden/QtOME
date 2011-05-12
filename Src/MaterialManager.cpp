#include "MaterialManager.hpp"

template<> MaterialManager* Ogre::Singleton<MaterialManager>::ms_Singleton = 0;

MaterialManager::MaterialManager()
{
    count = 0;
}

QStringList MaterialManager::getMaterialList(const QString & Path)
{
    // returns list of all materials already loaded by Ogre
    QStringList       list;
    QString           name;
    Ogre::MaterialPtr ptr;
    workDir = Path + '/';

    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(Path.toStdString() ,"FileSystem","Mats");
    Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("Mats");

    Ogre::ResourceManager::ResourceMapIterator materialIterator = Ogre::MaterialManager::getSingletonPtr()->getResourceIterator();
    while (materialIterator.hasMoreElements())
    {
        count++;
        ptr = (static_cast<Ogre::MaterialPtr>(materialIterator.peekNextValue()));
        mats.push_back(ptr.getPointer());
        if(!ptr.getPointer()->getOrigin().empty())
        {
            list.push_back(name.fromStdString(mats[mats.size()-1]->getName()));
            fileNames.insert(name.fromStdString(mats[mats.size()-1]->getName()), Path + '/' + ptr.getPointer()->getOrigin().c_str());
        }
        materialIterator.moveNext();
    }

    return list;
}

QStringList MaterialManager::getCompositorList()
{
    // returns list of all compositors already loaded by Ogre
    QStringList       list;
    QString           name;
    Ogre::MaterialPtr ptr;

    Ogre::ResourceManager::ResourceMapIterator compositorIterator = Ogre::CompositorManager::getSingletonPtr()->getResourceIterator();
    while (compositorIterator.hasMoreElements())
    {
        ptr = (static_cast<Ogre::CompositorPtr>(compositorIterator.peekNextValue()));
        if(!ptr.getPointer()->getOrigin().empty())
        {
            list.push_back(name.fromStdString(ptr.getPointer()->getName()));
            fileNames_Compositor.insert(name.fromStdString(ptr.getPointer()->getName()), workDir + ptr.getPointer()->getOrigin().c_str());
        }
        compositorIterator.moveNext();
    }

    return list;
}

QString MaterialManager::getFileName(const QString &Material)
{
    return fileNames[Material];
}

QString MaterialManager::getCompositorFileName(const QString &Compositor)
{
    compositorName = Compositor;
    return fileNames_Compositor[Compositor];
}

Ogre::String MaterialManager::getCompositorName()
{
    return compositorName.toStdString();
}

QString MaterialManager::getWorkDir()
{
    return workDir;
}

void MaterialManager::addMaterial(const QString &script, const QString &name)
{
    Ogre::MemoryDataStream *memoryStream = new Ogre::MemoryDataStream(Ogre::String(script.toStdString()), script.length() * sizeof(char));
    Ogre::DataStreamPtr dataStream(memoryStream);
    Ogre::MaterialManager::getSingleton().parseScript(dataStream, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    fileNames.insert(name, workDir + name + ".material");
}
