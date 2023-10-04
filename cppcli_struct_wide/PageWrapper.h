class PageWrapperPrivate;

struct __declspec(dllexport) PageData
{
    const wchar_t* PageUrl;
    const wchar_t* PageText;
};

class __declspec(dllexport) PageWrapper
{
    private: PageWrapperPrivate* _private;

    public: PageWrapper();

    public: ~PageWrapper();
    
    public: const PageData GetData();
};