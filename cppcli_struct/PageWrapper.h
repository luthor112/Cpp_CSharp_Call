class PageWrapperPrivate;

struct __declspec(dllexport) PageData
{
    const char* PageUrl;
    const char* PageText;
};

class __declspec(dllexport) PageWrapper
{
    private: PageWrapperPrivate* _private;

    public: PageWrapper();

    public: ~PageWrapper();
    
    public: const PageData GetData();
};