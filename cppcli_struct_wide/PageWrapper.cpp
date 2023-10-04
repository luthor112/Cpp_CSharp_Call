#using "Page.dll"

#include <msclr\auto_gcroot.h>
#include <vcclr.h>

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
    
    pin_ptr<const wchar_t> convertedPageUrlStr = PtrToStringChars(pageUrlStr);
    pin_ptr<const wchar_t> convertedPageTextStr = PtrToStringChars(pageTextStr);
    
    PageData nativePageData;
    nativePageData.PageUrl = convertedPageUrlStr;
    nativePageData.PageText = convertedPageTextStr;
    
    return nativePageData;
}

PageWrapper::~PageWrapper()
{
    delete _private;
}