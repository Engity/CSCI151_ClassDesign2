#include "SectionB.h"
#include <regex>

Image::Image(std::string fileName = "", std::string imageType = "JPG", std::string date = "01/01/0001", 
    double size = 0.0, std::string authorName = "", int width = 1, int height = 1, 
    int apertureSize = 1, std::string exposureTime = "1/1", int iso = 0, bool flash = false){
        setName(fileName);
        setImageType(imageType);
        setDate(date);
        setSize(size);
        setAuthorName(authorName);
        setWidth(width);
        setHeight(height);
        setApertureSize(apertureSize);
        setExposureTime(exposureTime);
        setIso(iso);
        setFlash(flash);
    }
//Get functions
std::string Image::getName() const {
    return _name;
}

std::string Image::getImageType() const{
    return _type;
}

std::string Image::getDate() const{
    return _date;
}

double Image::getSize() const{
    return _size;
}

std::string Image::getAuthorName() const{
    return _author;
}

int Image::getWidth() const{
    return _dimensionWidth;
}

int Image::getHeight() const{
    return _dimensionHeight;
}

int Image::getApertureSize() const{
    return _apertureSize;
}

std::string Image::getExposureTime() const{
    return _exposureTime;
}

int Image::getIso() const{
    return _iso;
}

bool Image::getFlash() const{
    return _flashEnabled;
}

//Set functions
void Image::setName(std::string name)
{
    _name = name;
}

//Only allowing three values for image's type
void Image::setImageType(std::string type)
{
    if (type == "PNG" || type == "GIF" || type == "JPEG"){
        _type = type;
    }
    else {
        std::cout << "Error, incorrect type inputted\n";
    }
}

//Check date format (mm/dd/yyyy) using regex
void Image::setDate(std::string date){
    std::regex regex_date ("^(1[0-2]|0[1-9])/(3[01]|[12][0-9]|0[1-9])/[0-9]{4}");
    if (std::regex_match(date, regex_date)){
        _date = date;
    }
    else {
        std::cout << "Wrong format for date, "
            << "it should be a in the format mm/dd/yyyy\n";
    }
}
        
//putting positive requirement on size and any number value
void Image::setSize(double size){
    if (size > 0)
        _size = size;
    else {
        std::cout << "Cannot use negative value for size\n";
    }
}

void Image::setAuthorName(std::string author){
    _author = author;
}

void Image::setWidth(int width){
    if (width > 0)
        _dimensionWidth = width;
    else {
        std::cout << "Cannot use negative value for width\n";
    }
}

void Image::setHeight(int height){
    if (height > 0)
        _dimensionHeight = height;
    else {
        std::cout << "Cannot use negative value for height\n";
    }
}

void Image::setApertureSize(int aperture){
    if (aperture > 0)
        _apertureSize = aperture;
    else {
        std::cout << "Cannot use negative value for Aperture Size\n";
    }
}

void Image::setIso(int iso){
    if (iso >= 0)
        _iso = iso;
    else {
        std::cout << "Cannot use negative value for iso\n";
    }
}

void Image::setFlash(bool flash){
    _flashEnabled = flash;
}
//Checking fraction format using regex, with the numerator always has to be 1
void Image::setExposureTime(std::string time){
    std::regex regex_fraction ("^1/[1-9][0-9]*");
    if (std::regex_match(time, regex_fraction)){
        _exposureTime = time;
    }
    else {
        std::cout << "Wrong format for exposure time, "
            << "it should be a fraction of a second like \"1/30\", or \"1/1000\"\n";
    }
}

//Outputing information
void printImageInfo(const Image &image){
    std::cout << "Image Information:";

    std::cout << "\n\tFile name = " << image.getName()
        << "\n\tImage type = " << image.getImageType()
        << "\n\tDate: " << image.getDate() 
        << "\n\tSize: " << image.getSize() << " MB"
        << "\n\tAuthor name: " << image.getAuthorName() 
        << "\n\tDimension: Width: " << image.getWidth() << " Height: " << image.getHeight()
        << "\n\tAperture size: f/" << image.getApertureSize()  
        << "\n\tExposure time: " << image.getExposureTime() 
        << "\n\tISO value: " << image.getIso();
    if (image.getFlash())
        std::cout << "\n\tFlash enabled";
    else
        std::cout <<"\n\tFlash disabled";

    std::cout << "\n";
}
//non-member output stream overload function
std::ostream& operator <<(std::ostream& out, const Image& image){
    out << "Image Information:";

    out << "\n\tFile name = " << image.getName()
        << "\n\tImage type = " << image.getImageType()
        << "\n\tDate: " << image.getDate() 
        << "\n\tSize: " << image.getSize() << " MB"
        << "\n\tAuthor name: " << image.getAuthorName() 
        << "\n\tDimension: Width: " << image.getWidth() << " Height: " << image.getHeight()
        << "\n\tAperture size: f/" << image.getApertureSize()  
        << "\n\tExposure time: " << image.getExposureTime() 
        << "\n\tISO value: " << image.getIso();
    if (image.getFlash())
        out << "\n\tFlash enabled";
    else
        out <<"\n\tFlash disabled";

    out << "\n";
}
