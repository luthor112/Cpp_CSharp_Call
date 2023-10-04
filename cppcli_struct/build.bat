csc /target:library Page.cs
cl /clr /LD PageWrapper.cpp
cl test.cpp PageWrapper.lib