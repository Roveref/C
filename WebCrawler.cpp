#include "WebCrawler.h"

WebCrawler::WebCrawler(const QString &websiteAddress) : m_websiteAddress(websiteAddress)
{
}

WebCrawler::~WebCrawler()
{
}

int WebCrawler::process()
{
    m_systemCommand = "wget -r - N --no-parent ";
    m_systemCommand = m_systemCommand.append(m_websiteAddress);

    return system(m_systemCommand.toStdString().c_str());
    emit finished();
}

