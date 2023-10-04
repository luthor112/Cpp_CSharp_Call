#include <iostream>

#include "PageWrapper.h"

int main()
{
    PageWrapper page;
    
    PageData pageData = page.GetData();
    std::wcout << "Page URL: " << pageData.PageUrl << std::endl;
    std::wcout << "Page Contents: " << pageData.PageText << std::endl;
    
    return 0;
}