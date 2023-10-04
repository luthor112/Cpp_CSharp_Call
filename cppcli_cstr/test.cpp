#include <iostream>

#include "PageWrapper.h"

int main()
{
    PageWrapper page;
    
    const char* pageData = page.GetData();
    
    std::cout << "Page Contents:\n" << pageData << std::endl;
    
    return 0;
}