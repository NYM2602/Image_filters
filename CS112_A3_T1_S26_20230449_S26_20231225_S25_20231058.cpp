/* File: CS112_A3_Part1_S26_20230449_S26_20231225_S25_20231058.cpp

   Purpose: Image processing tool that can apply 5 different filters.

   Authors: 1) Noura Yasser Mohamed Abdelhalim   Section: S26
            2) Somaya Tamer Magdy Shoaib         Section: S26
            3) Radwa Essam Mohamed El Sayed      Section: S25

   Emails: 1) nourata20066@gmail.com
           2) somayatamer2015@gmail.com
           3) radwaalkrargy@gmail.com

  ID1: 20230449 Filter 3: "Invert Image"
  ID2: 20231225 Filter 1 "Grayscale" & Filter 4 " Merge Images"
  ID3: 20231058 Filter 2: "Black and White" & Filter 5: "Flip Image"
*/

#include <iostream>
#include "Image_Class.h"
#include <string>
#include <fstream>
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

int main()
{
    while (true)
    {
        string option,filename, filename2;
        bool stop=false;
        Image current;
        cout<<"****** PhotoShop ******"<<endl;
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
                    cout<<"A)Grayscale " <<endl;
                    cout<<"B)Black & White"<<endl;
                    cout<<"C)Invert Image"<<endl;
                    cout<<"D)Merge Images"<<endl;
                    cout<<"E)Flip Image"<<endl;
                    cout<<"F)Return"<<endl;
                    cout<<"Please enter your choice (A/B/C/D/E/F/G): ";
                    cin>>option;

                    // Filter 1: Grayscale
                    if (tolower(option[0])=='a')
                    {
                        cout<<"****** Grayscale ******"<<endl;
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
                        cout<<" ****** Black & White ******"<<endl;
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
                        cout<<" ****** Invert Image ******"<<endl;
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
                        cout<<" ****** Merge Images ******"<<endl;
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
                        cout<<" ****** Flip Image ******"<<endl;
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
                    else if (tolower(option[0])=='f')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Invalid! Please choose (A/B/C/D/E/F)"<<endl;
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
            cout<<"****** Program Exited ******"<<endl;
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
    float total_pixels;
    total_pixels = image.height*image.width*3;
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
