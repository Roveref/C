#include "ParallelConcurrent.h"

ParallelConcurrent::ParallelConcurrent()
{
}

ParallelConcurrent::ParallelConcurrent(const int &numberConcurrent1,const int &numberConcurrent2)
{
    for(int i=1; i<=numberConcurrent1 + numberConcurrent2; ++i)
        {
        m_testFunction = new TestFunction(i);
        m_future = QtConcurrent::run(m_testFunction,&TestFunction::process);
        }
}

ParallelConcurrent::ParallelConcurrent(const int &choiceSelection, const QString &websiteAddress)
{
    if(choiceSelection == 0)
        m_textExtraction = new TextExtraction();
    else if(choiceSelection == 1)
        {
        m_textExtraction = new TextExtraction(websiteAddress);
        m_future = QtConcurrent::run(m_textExtraction,&TextExtraction::process);
        }
}

ParallelConcurrent::ParallelConcurrent(const QString &websiteAddress)
{
        m_webCrawler = new WebCrawler(websiteAddress);
        m_future = QtConcurrent::run(m_webCrawler,&WebCrawler::process);
}

ParallelConcurrent::~ParallelConcurrent()
{
}

