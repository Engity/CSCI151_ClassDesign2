#include <iostream>
#include <string>

class Image{
    public:
        Image(std::string fileName , std::string imageType, std::string date, 
            double size, std::string authorName, int width, int height, 
            int apertureSize, std::string exposureTime, int iso, bool flash);
        
        std::string getName() const;
        std::string getImageType() const;
        std::string getDate() const;
        double getSize() const;
        std::string getAuthorName() const;
        int getWidth() const;
        int getHeight() const;
        int getApertureSize() const;
        std::string getExposureTime() const;
        int getIso() const;
        bool getFlash() const;
        
        void setName(std::string file);
        void setImageType(std::string type);
        void setDate(std::string date);
        void setSize(double size);
        void setAuthorName(std::string author);
        void setWidth(int width);
        void setHeight(int height);
        void setApertureSize(int aperture);
        void setExposureTime(std::string time);
        void setIso(int iso);
        void setFlash(bool flash);

    private:
        //Default values incase assigning fail
        std::string _date = "01/01/0001", _type ="PNG", _exposureTime = "1/1";
        int _iso = 0;
        int _apertureSize = 1;
        int _dimensionWidth = 0, _dimensionHeight = 0;
        double _size = 0.0;
        
        std::string _name, _author;
        bool _flashEnabled;
        
};

void printImageInfo(const Image &image);

std::ostream& operator <<(std::ostream& out, const Image& image);//non-member output stream overload function