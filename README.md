# ppmip - PPM Image Processor
ppmip (**PPM** **I**mage **P**rocessor) is an image processing software which handles .ppm files.

# Motivation
This project is totally inspired on the final project of *Introdução às Técnicas de Programação* [Introduction to Programming Techniques (ITP)] course given by Professor Gustavo Girão, Professor André Mauricio and Professor Márjory Abreu at UFRN later on 2019.1 semester.

I'm currently working on it in my free time totally for fun.

# Functionalities
The project documentation asks for some functionalities. They are separated in two classes of functions.
## Filters
A function is called a *filter* if it manipulates the colors of an image. The options are:
### greyscale
Applies greyscale filter to an PPM image passed as second argument.

### threshold
Binarization of the image using thresholding.

### blur
Performs blurring.

### sharp
Performs sharpening.

## Transforms
A function is called a *transform* if it manipulates the arrangement of pixels in an image. The options are:
### rotate
Rotate the image by a given angle.

### scaleup
Scales up the image dimension.

### scaledown
Scales down the image dimension.

# Progress
Down below there is a checklist of the current development progress.
## Filters
- [x] *greyscale*
- [x] *threshold*
- [ ] *blur*
- [ ] *sharp*

## Transforms
- [ ] *rotate*
- [ ] *scaleup*
- [ ] *scaledown*

# Instructions
You might clone this repository and get into its folder and run `make`:
```sh
git clone https://github.com/giordanorn/ppmip
cd ppmip/
make
```
Then, it should be created a binary file called `ppmip`.

For applying filters, you must run the `ppmip` binary and pass as first argument the filter to be applied. As second argument, you should pass the ppm file which filter will be applied to. Finally, as third argument, you should pass the path to a file which changes will be saved. More formally:
```sh
./ppmip <filter> <input-file> <output-file>
```

For instance:
```sh
./ppmip greyscale res/test.ppm res/test-greyscaled.ppm
```

For applying transformations, it will be available soon.

# Testing
There is a test task for `make`. You may run the following:
```sh
make test
```
And then it should apply every available function to the test image `res/test.ppm`. The output are files `res/test-<function>.ppm` where `<filter>` is the applied filter.
