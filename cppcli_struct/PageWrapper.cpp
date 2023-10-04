#using "Page.dll"

#include <msclr\auto_gcroot.h>

#include "PageWrapper.h"

using namespace System::Runtime::InteropServices; // Marshal

class PageWrapperPrivate
{
    public: msclr::auto_gcroot<PageGetter::Page^> page;
};

PageWrapper::PageWrapper()
{
    _private = new PageWrapperPrivate();
    _private->page = gcnew PageGetter::Page();
}

const PageData PageWrapper::GetData()
{
    PageGetter::PageData managedPageData = _private->page->GetData();
    System::String^ pageUrlStr = managedPageData.PageUrl;
    System::String^ pageTextStr = managedPageData.PageText;
    
    PageData nativePageData;
    nativePageData.PageUrl = (const char*)(Marshal::StringToHGlobalAnsi(pageUrlStr).ToPointer());
    nativePageData.PageText = (const char*)(Marshal::StringToHGlobalAnsi(pageTextStr).ToPointer());
    
    return nativePageData;
}

PageWrapper::~PageWrapper()
{
    delete _private;
}