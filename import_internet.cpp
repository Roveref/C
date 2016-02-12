#include "import_internet.h"

import_internet::import_internet()
{

}

void import_internet::import()
{
    //execlp("wget", "wget", "http://www.yahoo.com",NULL);
    system("wget -r - N --no-parent http://www.yahoo.com");
}

