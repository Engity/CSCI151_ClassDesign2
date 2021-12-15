#pragma "once"
#include <string>
#include <iostream>

class URL{
    private:
        std::string _url, _authority, _scheme, _path;
    public:
        URL(std::string input);
        std::string getURL() const;
        std::string getAuthority() const;
        std::string getScheme() const;
        std::string getPath() const;
};

void printUrl(const URL&);
std::ostream& operator <<(std::ostream& out, const URL& url);//Non-member output stream overload function
