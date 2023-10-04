#using "Page.dll"

#include <msclr\auto_gcroot.h>

#include "PageWrapper.h"

using namespace System::Runtime::InteropServices; // Marshal

class PageWrapperPrivate
{
    public: msclr::auto_gcroot<Page^> page;
};

PageWrapper::PageWrapper()
{
    _private = new PageWrapperPrivate();
    _private->page = gcnew Page();
}

const char* PageWrapper::GetData()
{
    System::String^ managedCapi = _private->page->GetData();

    return (const char*)Marshal::StringToHGlobalAnsi(managedCapi).ToPointer();
}

PageWrapper::~PageWrapper()
{
    delete _private;
}