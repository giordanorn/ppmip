## ppmip - PPM Image Processor
ppmip (**PPM** **I**mage **P**rocessor) is a image processing software which handles .ppm files.

## Motivation
This project is totally inspired on the final project of *Introdução às Técnicas de Programação* [Introduction to Programming Techniques (ITP)] course given by Professor Gustavo Girão, Professor André Mauricio and Professor Márjory Abreu at UFRN later on 2019.1 semester.

I'm currently working on it in my free time totally for fun.

## Functionalities
The project documentation asks for some functionalities. They are arguments to be passed onto the program. The options are:
- greyscale: applies greyscale filter to an PPM image passed as second argument; *(Done!)*
- threshold: binarization of the image using thresholding;
- blur: performs blurring;
- sharp: perform sharpening;
- rotate: rotate the image by a given angle;
- amplify: magnify the image by a given zoom;
- reduce: reduce the image by a given zoom.

## Instructions
You might clone this repository and get into its folder and run `make`:
```sh
git clone https://github.com/giordanorn/ppmip
cd ppmip/
make
```
Then, it should be created a binary file called `ppmip`.

For executing the program you must run the `ppmip` binary and pass as first argument the filter to be applied. As second argument, you should pass the ppm file which filter will be applied to. Finally, as third argument, you should pass the path to a file which changes will be saved. More formally:
```sh
./ppmip <filter> <input-file> <output-file>
```

For instance:
```sh
./ppmip greyscale res/got.ppm res/got-greyscaled.ppm
```

## Disclaimer
Respecting the current classes of ITP, I am not finishing this project until the semester 2019.1 is over.