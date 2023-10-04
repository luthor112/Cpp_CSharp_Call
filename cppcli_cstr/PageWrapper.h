class PageWrapperPrivate;

class __declspec(dllexport) PageWrapper
{
    private: PageWrapperPrivate* _private;

    public: PageWrapper();

    public: ~PageWrapper();
    
    public: const char* GetData();
};