#include "SectionA.h"

URL::URL(std::string input){
_url = input;
    _scheme = _url.substr(0,_url.find(':') + 1);
    //Get the authority from excluding scheme at the beginning and look for the / signified the end
    _authority = _url.substr(_scheme.length(),
        _url.find("/", _scheme.length() + 2) - _scheme.length());

    //Path is the rest of url
    _path = _url.substr(_authority.length() + _scheme.length());}


std::string URL::getURL() const{
    return _url;
}

std::string URL::getScheme() const{
    return _scheme;
}

std::string URL::getPath() const{
    return _path;
}

std::string URL::getAuthority() const{
    return _authority;
}

void printUrl(const URL &url){
    std::cout << "URL: " << url.getURL()
        << "\n\tScheme: " << url.getScheme() 
        << "\n\tAuthority: " << url.getAuthority() 
        << "\n\tPath: " << url.getPath() << "\n";
}
//Non-member output stream overload function
std::ostream& operator <<(std::ostream& out, const URL& url){
   out << "URL: " << url.getURL()
        << "\n\tScheme: " << url.getScheme() 
        << "\n\tAuthority: " << url.getAuthority() 
        << "\n\tPath: " << url.getPath() << "\n";
}