#include "extract_html.h"

extraction_html::extraction_html()
{
    k=1;
    filesStack = new QStack<QString>();
    fileDialog.setFileMode(QFileDialog::Directory);
    fileDialog.setOption(QFileDialog::ShowDirsOnly);


    if (fileDialog.exec() == QFileDialog::Accepted) {
        rootDir = QDir(fileDialog.selectedFiles().first());

        rootDir.setFilter(QDir::Files |
                              QDir::Dirs | QDir::NoDot | QDir::NoDotDot);
        QStringList qsl; qsl.append("*.html");
        rootDir.setNameFilters(qsl);
        qDebug() << rootDir ;
        findFilesRecursively();

        site = "/home/roveref/Test" ;
        site_2 = std::to_string(2);
        site = site + site_2;
        site = site+".txt";
        std::cout << site << std::endl;
        fichier.open(site.c_str());

        while (!filesStack->isEmpty())
            {
            qDebug() << filesStack->last() ;


            fichier << filesStack->last().toStdString() << std::endl;

            QFile file1(filesStack->last());
            if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                 qDebug() << "Not opened";
            }
            QTextStream in(&file1);
            txt = in.readAll();


            QRegularExpression regex("<p>(.*)</p>");
            ite = regex.globalMatch(txt);
            filename = QString(filesStack->last() + ".txt");
            QFile file (filename);
            file.open(QIODevice::WriteOnly);

            while(ite.hasNext())
            {
                match = ite.next();
                file.write(match.captured(1).toUtf8() + " " );
            }
            file.close();
            filesStack->pop();
        }
        fichier.close();
    }
}

void extraction_html::findFilesRecursively() {
    QDirIterator it(rootDir, QDirIterator::Subdirectories);
    while(it.hasNext()) {
        filesStack->push(it.next());
    }
}

void extraction_html::scanDir(QDir directory)
{
    dir.setNameFilters(QStringList("*.nut"));
    dir.setFilter(QDir::Files  | QDir::NoSymLinks);

    qDebug() << "Scanning: " << dir.path();
    qDebug() << k ;
    k=k+1;

    fileList = dir.entryList();
    for (int i=0; i<fileList.count(); i++)
    {
        if(fileList[i] != "main.nut" &&
           fileList[i] != "info.nut")
        {
            qDebug() << "Found file: " << fileList[i];
            qDebug() << k ;
            k=k+1;

        }
    }

    dir.setFilter(QDir::AllDirs | QDir::NoSymLinks);
    dirList = dir.entryList();
    for (int i=0; i<dirList.size(); ++i)
    {
        newPath = QString("%1/%2").arg(dir.absolutePath()).arg(dirList.at(i));
        scanDir(QDir(newPath));
    }
}

int extraction_html::getNumero()
{
    return 1;
}

