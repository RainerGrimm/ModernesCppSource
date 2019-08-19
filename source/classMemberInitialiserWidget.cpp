// classMemberInitialiserWidget.cpp

#include <iostream>

class Widget{
  public:
    Widget(): width(640), height(480), frame(false), visible(true) {}
    explicit Widget(int w): width(w), height(getHeight(w)), frame(false), visible(true){}
    Widget(int w, int h): width(w), height(h), frame(false), visible(true){}

    void show(){ std::cout << std::boolalpha << width << "x" << height
                           << ", frame: " << frame << ", visible: " << visible
                           << std::endl;
     }
  private:
    int getHeight(int w){ return w*3/4; }
    int width;
    int height;
    bool frame;
    bool visible;
};

class WidgetImpro{
  public:
    WidgetImpro(){}
    explicit WidgetImpro(int w): width(w), height(getHeight(w)){}
    WidgetImpro(int w, int h): width(w), height(h){}

    void show(){ std::cout << std::boolalpha << width << "x" << height
                           << ", frame: " << frame << ", visible: " << visible
                           << std::endl;
    }

  private:
    int getHeight(int w){ return w * 3 / 4; }
    int width = 640;
    int height = 480;
    bool frame = false;
    bool visible = true;
};


int main(){

  std::cout << std::endl;

  Widget wVGA;
  Widget wSVGA(800);
  Widget wHD(1280, 720);

  wVGA.show();
  wSVGA.show();
  wHD.show();

  std::cout << std::endl;

  WidgetImpro wImproVGA;
  WidgetImpro wImproSVGA(800);
  WidgetImpro wImproHD(1280, 720);

  wImproVGA.show();
  wImproSVGA.show();
  wImproHD.show();

  std::cout << std::endl;

}
