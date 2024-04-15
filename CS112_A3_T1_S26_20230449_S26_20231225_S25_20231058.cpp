/* File: CS112_A3_Part1_S26_20230449_S26_20231225_S25_20231058.cpp

   System Diagram :

   Purpose: Image processing tool that can apply 15 different filters.

   Authors: 1) Noura Yasser Mohamed Abdelhalim   Section: 26
            2) Somaya Tamer Magdy Shoaib         Section: 26
            3) Radwa Essam Mohamed El Sayed      Section: 25

   Emails: 1) nourata20066@gmail.com
           2) somayatamer2015@gmail.com
           3) radwaalkrargy@gmail.com

   ID1: 20230449 Filter 3: "Invert Image"
                 Filter 6: "Rotate Image"
                 Filter 9: "Add Frame"
                 Filter 12: "Blur Image"
                 Filter 15: "TV Effect"

   ID2: 20231225 Filter 1: "Gray Scale"
                 Filter 4: "Merge Images"
                 Filter 7: "Darken and Lighten Image"
                 Filter 10: "Detect Image Edges"
                 Filter 17: "Infrared"

   ID3: 20231058 Filter 2: "Black and White"
                 Filter 5: "Flip Image"
                 Filter 8: "Crop Image"
                 Filter 11: "Resize Image"
                 Filter 16: "Purple Effect"

*/
#include <iostream>
#include "Image_Class.h"
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
// **FUNCTIONS**
void showMenu3();
// Filter 1: Grayscale
void grayScale(Image&image);
// Filter 2: Black and White
void blackAndWhite(Image&image);
// Filter 3: Invert Image
void invFilter(Image&image);
// Filter 4: Merge Images
Image* mergeImages(Image&image1, Image&image2);
// Filter 5: Flip Image
void flipHorizontal(Image& image);
void flipVertical(Image& image);
// Filter 6: Rotate Image
// Filter 7: Darken and Lighten Image
void darkenImage(Image& image);
void lightenImage(Image& image);
// Filter 8: Crop Image
Image* cropImage(Image& image, float point_x , float point_y , float New_width , float New_height);
int checkValidation(Image& image , float point_x , float point_y , float New_width , float New_height);
bool isNumber(string input);
// Filter 9: Add Frame
// Filter 10: Detect Image Edges
Image* detectImageEdges(Image&image);
// Filter 11: Resize Image
Image* resizeImage(double& New_height , double& New_width , Image& image );
// Filter 12: Blur Image
// Filter 15: TV Effect
// Filter 16: Purple Effect
void purpleImage(Image& image);
// Filter 17: Infrared
void infrared (Image&image);
int main()
{
    while (true)
    {
        string option,filename, filename2;
        bool stop=false;
        Image current;
        cout<<"\t\t\t\t\t\t****** PhotoShop ******"<<endl;
        cout<<"What would you like to do today?"<<endl;
        cout<<"A) Filter an image"<<endl;
        cout<<"B) Exit"<<endl;
        cout<<"Please enter your choice (A/B): ";
        cin>> option;
        if (tolower(option[0])=='a')
        {
            cout<<"Enter image name to load: ";
            cin >> filename;
            try
            {
                Image* image = new Image(filename);

                while (true)
                {
                    cout<<"Choose filter you wish to apply"<<endl;
                    cout<<"A) Grayscale " <<endl;
                    cout<<"B) Black & White"<<endl;
                    cout<<"C) Invert Image"<<endl;
                    cout<<"D) Merge Images"<<endl;
                    cout<<"E) Flip Image"<<endl;
                    cout<<"F) Rotate Image"<<endl;
                    cout<<"G) Darken or Lighten "<<endl;
                    cout<<"H) Crop Image"<<endl;
                    cout<<"I) Add Frame"<<endl;
                    cout<<"J) Detect Edges"<<endl;
                    cout<<"K) Resize Image"<<endl;
                    cout<<"L) Blur Image"<<endl;
                    cout<<"M) TV Effect"<<endl;
                    cout<<"N) Purple Effect"<<endl;
                    cout<<"O) Infrared "<<endl;
                    cout<<"P) Return"<<endl;
                    cout<<"Please enter your choice (A-P): ";
                    cin>>option;

                    // Filter 1: Grayscale
                    if (tolower(option[0])=='a')
                    {
                        cout<<"\t\t\t\t\t\t****** Grayscale ******"<<endl;
                        grayScale(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Filter 2: Black and White
                    else if (tolower(option[0])=='b')
                    {
                        cout<<"\t\t\t\t\t\t****** Black & White ******"<<endl;
                        blackAndWhite(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Filter 3: Invert Image
                    else if (tolower(option[0])=='c')
                    {
                        cout<<"\t\t\t\t\t\t****** Invert Image ******"<<endl;
                        invFilter(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Filter 4: Merge Images
                    else if (tolower(option[0])=='d')
                    {
                        cout<<"\t\t\t\t\t\t****** Merge Images ******"<<endl;
                        cout << "Please enter filename of the second image: ";
                        cin >> filename2;
                        Image image2(filename2);
                        image = mergeImages(*image, image2);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Filter 5: Flip Image
                    else if (tolower(option[0])=='e')
                    {
                        cout<<"\t\t\t\t\t\t****** Flip Image ******"<<endl;
                        while (true)
                        {
                            string choice;
                            cout << "choose an operation \nA)flip horizontal \nB)flip vertical \n";
                            cin >> choice;
                            if (tolower(choice[0])=='a')
                            {
                                flipHorizontal(*image);
                                break;
                            }
                            else if (tolower(choice[0])=='b')
                            {
                                flipVertical(*image);
                                break;
                            }
                            else
                            {
                                cout << "Invalid! Please choose (A/B)"<<endl;
                                continue;
                            }
                        }
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 6: Rotate Image
                    else if (tolower(option[0])=='f')
                    {
                        cout<<"\t\t\t\t\t\t****** Rotate Image ******"<<endl;
                        //(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 7: Darken or Lighten Image
                    else if (tolower(option[0])=='g')
                    {
                        cout<<"\t\t\t\t\t\t****** Darken or Lighten ******"<<endl;
                        while (true)
                        {
                            string choice;
                            cout<<"Choose filter you wish to apply"<<endl;
                            cout<<"A)Lighten Filter"<<endl;
                            cout<<"B)Darken Filter"<<endl;
                            cout<<"Please enter your choice(A/B)"<<endl;
                            cin>> choice;
                            if (tolower(choice[0])=='a')
                            {
                                lightenImage(*image);
                                break;
                            }
                            else if (tolower(choice[0])=='b')
                            {
                                darkenImage(*image);
                                break;
                            }
                            else
                            {
                                cout << "Invalid! Please choose (A/B)"<<endl;
                                continue;
                            }
                        }
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 8: Crop Image
                    else if (tolower(option[0])=='h')
                    {
                        cout<<"\t\t\t\t\t\t****** Crop Image******"<<endl;
                        cout << "********Crop Image********" << endl;
                        string point_xstr,point_ystr,New_heightstr ,New_widthstr  ;
                        cout << "Enter start point 1: ";
                        cin >> point_xstr ;
                        while(!isNumber(point_xstr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>point_xstr;
                        }
                        cout << "Enter start point 2: ";
                        cin >> point_ystr ;
                        while(!isNumber(point_ystr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>point_ystr;
                        }
                        cout << "Enter new width: ";
                        cin >> New_widthstr ;
                        while(!isNumber(New_widthstr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>New_widthstr;
                        }
                        cout << "Enter new height: ";
                        cin >> New_heightstr ;
                        while(!isNumber(New_heightstr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>New_heightstr;
                        }
                        float point_x = stof(point_xstr + ".0");
                        float point_y  = stof(point_ystr  + ".0");
                        float New_width = stof(New_widthstr + ".0");
                        float New_height = stof(New_heightstr + ".0");
                        checkValidation(*image , point_x , point_y , New_width , New_height);
                        image = cropImage(*image, point_x , point_y , New_width , New_height);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Filter 9: Adding Frame
                    else if (tolower(option[0])=='i')
                    {
                        cout<<"\t\t\t\t\t\t****** Add Frame ******"<<endl;
                        invFilter(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 10: Detect Edges
                    else if (tolower(option[0])=='j')
                    {
                        cout<<"\t\t\t\t\t\t****** Detect Edges ******"<<endl;
                        image = detectImageEdges(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 11: Resize Image
                    else if (tolower(option[0])=='k')
                    {
                        cout<<"\t\t\t\t\t\t****** Resize Image ******"<<endl;
                        string New_heightstr ,New_widthstr  ;
                        cout << "Enter new width: ";
                        cin >> New_widthstr ;
                        while(!isNumber(New_widthstr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>New_widthstr;
                        }
                        cout << "Enter new height: ";
                        cin >> New_heightstr ;
                        while(!isNumber(New_heightstr)){
                            cout<<"Invalid! Enter a valid number"<<endl;
                            cin>>New_heightstr;
                        }
                        double New_width = stof(New_widthstr + ".0");
                        double New_height = stof(New_heightstr + ".0");

                        image=resizeImage(New_height , New_width , *image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Filter 12: Blur Image
                    else if (tolower(option[0])=='i')
                    {
                        cout<<"\t\t\t\t\t\t****** Blur Image ******"<<endl;
                        invFilter(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Filter 15 : TV Effect
                    else if (tolower(option[0])=='m')
                    {
                        cout<<"\t\t\t\t\t\t****** TV Effect ******"<<endl;
                        invFilter(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Filter 16: Purple Effect
                    else if (tolower(option[0])=='n')
                    {
                        cout<<"\t\t\t\t\t\t****** Purple Effect ******"<<endl;
                        purpleImage(*image);
                        lightenImage(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    //Filter 17: Infrared Effect
                    else if (tolower(option[0])=='o')
                    {
                        cout<<"\t\t\t\t\t\t****** Infrared ******"<<endl;
                        infrared(*image);
                        while (true)
                        {
                            showMenu3();
                            cin>>option;
                            if(tolower(option[0])=='a')
                            {
                                cout << "Please enter image name to store new image\n";
                                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                                cin>> filename;
                                (*image).saveImage(filename);
                                system(filename.c_str());
                                stop=false;
                                break;
                            }
                            else if (tolower(option[0])=='b')
                            {
                                stop=true;
                                break;
                            }
                            else
                            {
                                cout<<"Invalid! Please choose (A/B)"<<endl;
                            }
                        }
                        if (stop)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    // Return
                    else if (tolower(option[0])=='p')
                    {
                        break;
                    }

                    else
                    {
                        cout<<"Invalid! Please choose (A-P)"<<endl;
                        continue;
                    }
                }
            }
            catch (...)
            {
                cout << "Invalid filename! Please try again." << endl;
                continue;
            }
        }
        else if (tolower(option[0])=='b')
        {
            cout<<"\t\t\t\t\t\t****** Program Exited ******"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid! Please choose (A/B)"<<endl;
        }
    }
    return 0;
}


//**FUNCTIONS**
void showMenu3()
{
    cout<<"Do you wish to save image or continue ?"<<endl;
    cout<<"A)Save image" << endl;
    cout<<"B)Continue"<<endl;
    cout<<"Please enter your choice (A/B):";
}
//Filter 1: Grayscale
void grayScale(Image&image)
{
    for(int x=0 ; x<image.width; ++x)
    {
        for(int y =0; y<image.height; ++y)
        {
            int grayscale = (image(x, y, 0) + image(x, y, 1) + image(x, y, 2)) / 3;
            image (x, y, 0) = grayscale;
            image (x, y, 1) = grayscale;
            image (x, y, 2) = grayscale;
        }
    }
}
//Filter 2 : Black & White
void blackAndWhite(Image&image)
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned  int avg = 0;
            for (int k = 0; k < 3; ++k)
            {
                avg += image(i, j, k);
            }
            avg /= 3;
            if (avg > 128)
            {
                image(i,j,0) = 255;
                image(i,j,1) = 255;
                image(i,j,2) = 255;
            }
            else if (avg <= 128)
            {
                image(i,j,0) = 0;
                image(i,j,1) = 0;
                image(i,j,2) = 0;
            }
        }
    }
}
// Filter 3: Invert Image
void invFilter(Image&image)
{
    for (int i=0; i<image.width; i++)
    {
        for (int j=0; j<image.height; j++)
        {
            for (int k=0; k<3; k++)
            {
                image(i,j,k) = 255 - image(i,j,k);
            }
        }
    }
}

//Filter 4: Merge Images
Image* mergeImages(Image& image1, Image& image2)
{
    int smallerWidth = min(image1.width, image2.width);
    int smallerHeight = min(image1.height, image2.height);
    int halfWidth1 = (image1.width - smallerWidth) / 2;
    int halfHeight1 = (image1.height - smallerHeight) / 2;
    int halfWidth2 = (image2.width - smallerWidth) / 2;
    int halfHeight2 = (image2.height - smallerHeight) / 2;

    Image croppedImage1(smallerWidth, smallerHeight);
    for (int y = 0; y < smallerHeight; ++y)
    {
        for (int x = 0; x < smallerWidth; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                croppedImage1(x, y, c) = image1(x + halfWidth1, y + halfHeight1, c);
            }
        }
    }
    Image croppedImage2(smallerWidth, smallerHeight);
    for (int y = 0; y < smallerHeight; ++y)
    {
        for (int x = 0; x < smallerWidth; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                croppedImage2(x, y, c) = image2(x + halfWidth2, y + halfHeight2, c);
            }
        }
    }
    // Merge the cropped images
    Image* mergedImage = new Image(smallerWidth, smallerHeight);
    for (int y = 0; y < smallerHeight; ++y)
    {
        for (int x = 0; x < smallerWidth; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                (*mergedImage)(x, y, c) = (croppedImage1(x, y, c) + croppedImage2(x, y, c)) / 2; // Averaging pixel values from both images
            }
        }
    }
    return mergedImage;
}

// Filter 5: Flip Image
void flipHorizontal(Image& image)
{
    int width = image.width;
    int height = image.height;
    for (int i = 0 ; i < width / 2 ; i++)
    {
        for (int j = 0 ; j < height ; j++)
        {
            for (int k = 0 ; k < 3 ; k++)
            {
                unsigned int temp = image(i,j,k);
                image(i,j,k) = image(width - 1 - i, j,k);
                image(width-1-i,j,k) = temp;
            }
        }
    }
}
void flipVertical(Image& image)
{
    int width = image.width;
    int height = image.height;
    for (int i = 0 ; i < width ; i++)
    {
        for (int j = 0 ; j < height /2 ; j++)
        {
            for (int k = 0 ; k < 3 ; k++)
            {
                unsigned int temp = image(i,j,k);
                image(i,j,k) = image(i,height-1-j,k);
                image(i,height-1-j,k) = temp;
            }
        }
    }
}

// Filter 7 : Darken and Lighten Image
// Darken Function
void darkenImage(Image& image)
{
    for(int x=0 ; x<image.width; ++x)
    {
        for(int y =0; y<image.height; ++y)
        {
            image (x, y, 0) = image(x, y, 0)*0.5;
            image (x, y, 1) = image(x, y, 1)*0.5 ;
            image (x, y, 2) = image(x, y, 2)*0.5;
        }
    }

}

// Light Function
void lightenImage(Image& image)
{
    for(int x=0 ; x<image.width; ++x)
    {
        for(int y =0; y<image.height; ++y)
        {
            image(x, y, 0) = min(255, image(x,y,0)/2 + image(x,y,0));
            image(x, y, 1) = min(255, image(x,y,1)/2 + image(x,y,1));
            image(x, y, 2) = min(255, image(x,y,2)/2 + image(x,y,2));
        }
    }
}

// Filter 8 : Crop Image
Image* cropImage(Image& image , float point_x , float point_y , float New_width , float New_height){
    Image* newImage = new Image(New_width , New_height);
    for (float i = 0 ; i < New_width; i++){
        for (float j = 0 ; j < New_height ; j++){
            for (int k = 0 ; k < 3 ; k++){
                (*newImage)(i,j,k) = image(point_x + i , point_y + j, k) ;
            }
        }
    }
    return newImage;
}
int checkValidation(Image& image , float point_x , float point_y , float New_width , float New_height){
    while (true){
    if (point_x + New_width < image.width){
        break;}
    else{
        cout << "The image width is too large \n";
        continue;}
    if (point_y + New_height < image.height){
        break;}
    else{
        cout << "The image height is too large \n";
        continue;}
    }
    return 0 ;
}
bool isNumber( string input) {
    for (char c : input) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

// Filter 10: Detect Image Edges
Image* detectImageEdges(Image&image)
{
// Canny Edge Detector Method
// Convert to Gray scale
    grayScale(image);
// Gradient Calculation using Sobel operator
    Image* edge = new Image(image.width, image.height); // The output image
    int sobelX[3][3] = { {-1, 0, 1}, // The X direction kernel
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int sobelY[3][3] = { {-1, -2, -1}, // The Y direction kernel
        { 0,  0,  0},
        { 1,  2,  1}
    };
    for (int x = 1; x < image.width - 1; ++x)
    {
        for (int y = 1; y < image.height - 1; ++y) // x=1 and width -1 to exclude pixels at the borders cause of the size of the kernal
        {
            float gX = 0.0f; // Gradient magnitude of X
            float gY = 0.0f; // Gradient magnitude of Y
            for (int dx = -1; dx <= 1; ++dx) // -1 to 1 since sobel X and Y are 3x3
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    float intensity = image.getPixel(x + dx, y + dy, 0) * 0.299f  + // Gray scale factor for  Red channel , x+dx and y+dy are the neighboring pixels
                                      image.getPixel(x + dx, y + dy, 1) * 0.587f + // Gray scale factor for Green channel
                                      image.getPixel(x + dx, y + dy, 2) * 0.114f;  // Gray scale factor for Blue channel
                    gX += intensity * sobelX[dx + 1][dy + 1]; // Multiply the intensity
                    gY += intensity * sobelY[dx + 1][dy + 1];
                }
                int magnitude = sqrt(gX * gX + gY * gY);  // Calculate the magnitude of the gradient

                int threshold = 250;
                char edgeValue =(magnitude>threshold)?0:255;
                edge->setPixel(x, y, 0, edgeValue); // -> not edge.setpixel cause edge is of pointer type
                edge->setPixel(x, y, 1, edgeValue);
                edge->setPixel(x, y, 2, edgeValue);
            }
        }
    }
    return edge;
}
// Filter 11: Resize Image
Image* resizeImage(double& New_height , double& New_width , Image& image ){
    Image* newImage = new Image(New_width, New_height);
    double ratio_width = image.width / New_width ;
    double ratio_height = image.height / New_height;
    for (float i = 0 ; i < New_width ; i++){
        for (float j = 0 ; j < New_height ; j++){
            for (int k = 0 ; k < 3 ; k++){
                (*newImage)(i,j,k) = image(round(i*ratio_width) ,round(j*ratio_height) ,k);
            }
        }
    }
    return newImage;
}

// Filter 16: Purple Effect
void purpleImage(Image& image){
    for (int i = 0 ; i < image.width ; i++){
        for (int j = 0 ; j < image.height ; j++){
            for (int k = 0 ; k < 3 ; k++){
                if (k == 1)
                image (i,j,1) *= 0.7 ;
            }
        }
    }
}

// Filter 17: Infrared
void infrared (Image&image)
{
    for(int x=0 ; x<image.width; ++x)
    {
        for(int y =0; y<image.height; ++y)
        {
            int green = image.getPixel(x,y,1);
            int blue = image.getPixel(x,y,2);
            green = 255- green ;
            blue= 255- blue;

            image.setPixel(x, y, 0, 255);  // Max the red
            image.setPixel(x, y, 1, green);
            image.setPixel(x, y, 2, blue);
        }
    }
}
